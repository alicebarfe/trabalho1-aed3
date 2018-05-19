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
	void InserirIterativo(T chave, U conteudo);
	void InserirRecursivo(No<T, U> * & anda, T chave, U conteudo);
	U Remover(T chave);
	U RemoverRecursivo(No<T, U> * & anda, T chave);
	U Buscar(T chave);
	U BuscarIterativo(T chave);
	U BuscarRecursivo(No<T, U> * anda, T chave);


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
	//InserirIterativo(chave, conteudo);
	InserirRecursivo(raiz, chave, conteudo);
}


template <class T, class U>
void Dicionario<T, U>::InserirIterativo(T chave, U conteudo)
{
	No<T, U> * novo = new No<T, U>(chave, conteudo);

	if(raiz == NULL)
	{
		raiz = novo;
	}
	else
	{
		No<T, U> * anda = raiz;

		while(anda->chave != chave)
		{
			if(chave > anda->chave)
			{
				if(anda->direita == NULL)
					anda->direita = novo;
				anda = anda->direita;
			}
			else if(chave < anda->chave)
			{
				if(anda->esquerda == NULL)
					anda->esquerda = novo;
				anda = anda->esquerda;
			}
		}
	}
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
	//return BuscarIterativo(chave);
	return BuscarRecursivo(raiz, chave);
}

template <class T, class U>
U Dicionario<T, U>::BuscarIterativo(T chave)
{
	No<T, U> * anda = raiz;

	while(anda != NULL)
	{
		if(chave > anda->chave)
			anda = anda->direita;
		else if(chave < anda->chave)
			anda = anda->esquerda;
		else
			return anda->conteudo;
	}

	//Caso não encontre o conteúdo
	//Retorna um conteúdo padrão para indicar que não encontrou
	//(Pessoa vazia)
	return U();
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


