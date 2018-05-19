#include <iostream>

using namespace std;

template <class T, class U>
class No
{
public:
	No(T ch, U co);
	T chave;
	U conteudo;
	No * esquerda, * direita;
};

template <class T, class U>
No<T, U>::No(T ch, U co)
{
	chave = ch;
	conteudo = co;
	esquerda = NULL;
	direita = NULL;
}


template <class T, class U>
class Dicionario
{
public:
	No<T, U> * raiz;

	Dicionario();
	void Inserir(T chave, U conteudo);
	void InserirRecursivo(No<T, U> * & anda, T chave, U conteudo);
	U Remover(T chave);
	U RemoverRecursivo(No<T, U> * & anda, T chave);
	U Buscar(T chave);
	U BuscarRecursivo(No<T, U> * anda, T chave);
	int NumNos(No<T, U> * x);
	int NumFolhas(No<T, U> * x);
	int NosCaminho(No<T, U> * anda, T chave);
	int NumNiveis(No<T, U> * x);

	void RotacaoDireita(No<T, U> * x);
	void RotacaoEsquerda(No<T, U> * x);

	void Imprime();
	void ImprimeRec(No<T, U> * x);
};

template <class T, class U>
Dicionario<T, U>::Dicionario()
{
	raiz = NULL;
}

template <class T, class U>
void Dicionario<T, U>::Inserir(T chave, U conteudo)
{
	InserirRecursivo(raiz, chave, conteudo);
}

template <class T, class U>
void Dicionario<T, U>::InserirRecursivo(No<T, U> * & anda, T chave, U conteudo)
{
	if(anda == NULL)
	{
		No<T, U> * novo = new No<T, U>(chave, conteudo);

		anda = novo;
	}

	if(chave == anda->chave)
		return;

	if(chave < anda->chave)
		InserirRecursivo(anda->esquerda, chave, conteudo);

	if(chave > anda->chave)
		InserirRecursivo(anda->direita, chave, conteudo);
}


template <class T, class U>
U Dicionario<T, U>::Buscar(T chave)
{
	return BuscarRecursivo(raiz, chave);
}

template <class T, class U>
U Dicionario<T, U>::BuscarRecursivo(No<T, U> * anda, T chave)
{
	if(anda == NULL)
		return U();

	if(chave == anda->chave)
		return anda->conteudo;

	if(chave < anda->chave)
		return BuscarRecursivo(anda->esquerda, chave);

	if(chave > anda->chave)
		return BuscarRecursivo(anda->direita, chave);
}

template <class T, class U>
U Dicionario<T, U>::Remover(T chave)
{
	return RemoverRecursivo(raiz, chave);
}

template <class T, class U>
U Dicionario<T, U>::RemoverRecursivo(No<T, U> * & anda, T chave)
{
	if(anda == NULL)
		return U();

	if(chave == anda->chave)
	{
		U conteudo = anda->conteudo;
		//Caso 3: 2 Filhos
		if(anda->esquerda != NULL && anda->direita != NULL)	
		{
			//Encontrar maior da esquerda de anda
			No<T, U> * ME = anda->esquerda;
			while(ME->direita != NULL)
				ME = ME->direita;

			T chaveME = ME->chave;
			anda->conteudo = RemoverRecursivo(anda->esquerda, ME->chave);
			anda->chave = chaveME;
		}
		else
		{
			No<T, U> * novoanda;
			//Caso 1: Nó Folha
			if(anda->esquerda == NULL && anda->direita == NULL)	
			{
				novoanda = NULL;
			}
			//Caso 2: 1 Filho (direita)
			else if(anda->esquerda == NULL && anda->direita != NULL)
			{
				cout << "achou caso" << endl;
				novoanda = anda->direita;
			}
			//Caso 2: 1 Filho (esquerda)
			else if(anda->direita == NULL && anda->esquerda != NULL)
			{
				novoanda = anda->esquerda;
			}

			delete anda;
			anda = novoanda;
		}

		return conteudo;
	}
	if(chave < anda->chave)
		return RemoverRecursivo(anda->esquerda, chave);
	else if(chave > anda->chave)
		return RemoverRecursivo(anda->direita, chave);
}



template <class T, class U>
void Dicionario<T, U>::Imprime()
{
	ImprimeRec(raiz);
	cout << "Número de nós: " << NumNos(raiz) << endl;
	cout << "Número de níveis: " << NumNiveis(raiz) << endl;
	cout << "Número de folhas: " << NumFolhas(raiz) << endl;
}

template <class T, class U>
void Dicionario<T, U>::ImprimeRec(No<T, U> * x)
{
	if(x == NULL)
		return;	

	ImprimeRec(x->esquerda);
	cout << x->chave << " ";
	x->conteudo.Imprime();
	ImprimeRec(x->direita);
}

template <class T, class U>
int Dicionario<T, U>::NumNos(No<T, U> * x)
{
	if(x == NULL)
		return 0;

	return 1 + NumNos(x->esquerda) + NumNos(x->direita);
}

template <class T, class U>
int Dicionario<T, U>::NumFolhas(No<T, U> * x)
{
	if(x == NULL)
		return 0;
	if(x->esquerda == NULL && x->direita == NULL)
		return 1;
	return NumFolhas(x->esquerda) + NumFolhas(x->direita);
}

template <class T, class U>
int Dicionario<T, U>::NosCaminho(No<T, U> * anda, T chave)
{
	if(anda == NULL)
		return 0;	

	if(chave == anda->chave)
		return 1;

	if(chave < anda->chave)
		//o nó atual contribui em uma unidade
		//+ o número de nós na esquerda
		return 1 + NosCaminho(anda->esquerda, chave);

	if(chave > anda->chave)
		return 1 + NosCaminho(anda->direita, chave);
}

template <class T, class U>
int Dicionario<T, U>::NumNiveis(No<T, U> * x)
{
	if(x == NULL)
		return 0;

	int ne = NumNiveis(x->esquerda);
	int nd = NumNiveis(x->direita);
	int max;
	if(ne > nd)
		max = ne;
	else 
		max = nd;

	return 1 + max;
}

template <class T, class U>
void Dicionario<T, U>::RotacaoDireita(No<T, U> * & x)
{
	if(x->esquerda == NULL)
		return;

	No<T, U> * aux = x->esquerda;
	x->esquerda = aux->direita;
	aux->direita = x;

	x = aux;
}

template <class T, class U>
void Dicionario<T, U>::RotacaoEsquerda(No<T, U> * &  x)
{
	if(x->direita == NULL)
		return;

	//aux aponta para x direita
	No<T, U> * aux = x->direita;
	x->direita = aux->esquerda;
	aux->esquerda = x;

	x = aux;
}


