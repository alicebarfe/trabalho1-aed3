#include <iostream>
using namespace std;

template <class T>
class NoAmigo
{
public:
	NoAmigo(T ch);
	T chave;
	NoAmigo * esquerda, * direita;
};

template <class T>
NoAmigo<T>::NoAmigo(T ch)
{
	chave = ch;
	esquerda = NULL;
	direita = NULL;
}

template <class T, class N>
class Pessoa
{
public:
	Pessoa(T ch, N no);
	T chave;
	N nome;
	Pessoa * esquerda, * direita;
	NoAmigo<T> * Raiz_amigos = new Pessoa<T,N>();
};

template <class T, class N>
Pessoa<T, N>::Pessoa(T ch, N no)
{
	chave = ch;
	nome = no;
	esquerda = NULL;
	direita = NULL;
	Raiz_amigos = NULL;
}

template <class T, class N>
class Rede_Social
{
public:
	Pessoa<T, N> * raiz;

	Rede_Social();
	void InserirPessoa(T chave, N nome);
	void InserirPessoaRec(Pessoa<T, N> * & anda, T chave, N nome);
	N Remover(T chave);
	N RemoverRecursivo(Pessoa<T, N> * & anda, T chave);
	N Buscar(T chave);
	N BuscarRecursivo(Pessoa<T, N> * anda, T chave);
	void Cadastrar_amigos(T id_1, T id_2);
	void Cadastrar(Pessoa<T, N> * & anda, T chave);
	void Imprime();
	void ImprimeRec(Pessoa<T, N> * x);
};

template <class T, class N>
Rede_Social<T, N>::Rede_Social()
{
	raiz = NULL;
}

template <class T, class N>
void Rede_Social<T, N>::InserirPessoa(T chave, N nome)
{
	InserirRecursivo(raiz, chave, nome);
}

template <class T, class N>
void Rede_Social<T, N>::InserirPessoaRec(Pessoa<T, N> * & anda, T chave, N nome)
{
	if(anda == NULL)
	{
		Pessoa<T, N> * novo = new Pessoa<T, N>(chave, nome);

		anda = novo;
	}

	if(chave == anda->chave)
		return;

	if(chave < anda->chave)
		InserirPessoaRec(anda->esquerda, chave, nome);

	if(chave > anda->chave)
		InserirPessoaRec(anda->direita, chave, nome);
}

template <class T, class N>
N Rede_Social<T, N>::Buscar(T chave)
{
	return BuscarRecursivo(raiz, chave);
}

template <class T, class N>
N Rede_Social<T, N>::BuscarRecursivo(Pessoa<T, N> * anda, T chave)
{
	if(anda == NULL)
		throw "não encontrado";

	if(chave == anda->chave)
		return anda->nome;

	if(chave < anda->chave)
		return BuscarRecursivo(anda->esquerda, chave);

	if(chave > anda->chave)
		return BuscarRecursivo(anda->direita, chave);
}

template <class T, class N>
N Rede_Social<T, N>::Remover(T chave)
{
	return RemoverRecursivo(raiz, chave);
}

template <class T, class N>
N Rede_Social<T, N>::RemoverRecursivo(Pessoa<T, N> * & anda, T chave)
{
	N nome;

	if(anda == NULL)
		throw "remoção de chave inexistente";

	if(chave == anda->chave)
	{
		nome = anda->nome;
		//Caso 3: 2 Filhos
		if(anda->esquerda != NULL && anda->direita != NULL)	
		{
			//Encontrar maior da esquerda de anda
			Pessoa<T, N> * ME = anda->esquerda;
			while(ME->direita != NULL)
				ME = ME->direita;

			T chaveME = ME->chave;
			anda->nome = RemoverRecursivo(anda->esquerda, ME->chave);
			anda->chave = chaveME;
		}
		else
		{
			Pessoa<T, N> * novoanda;
			//Caso 1: Nó Folha
			if(anda->esquerda == NULL && anda->direita == NULL)	
			{
				novoanda = NULL;
			}
			//Caso 2: 1 Filho (direita)
			else if(anda->esquerda == NULL && anda->direita != NULL)
			{
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

	}
	else if(chave < anda->chave)
	{
		nome = RemoverRecursivo(anda->esquerda, chave);
	}
	else if(chave > anda->chave)
	{
		nome = RemoverRecursivo(anda->direita, chave);
	}

	return nome;
}
template <class T, class N>
void Rede_Social<T, N>::Cadastrar_amigos(T id_1,T id_2)
{
	if (Buscar(id_1)!= "não encobntrado" && Buscar(id_2)!= "não encobntrado")
	{
		if(Consultar_amizade(id_1, id_2) != "não encontrado"){
			Cadastrar(id_1->Raiz_amigos, id_2);
			Cadastrar(id_2->Raiz_amigos, id_1);
		}
	}
}

template <class T, class N>
void Rede_Social<T, N>::Cadastrar(Pessoa<T, N> * & anda, T chave)
{
	if(anda == NULL)
	{
		Pessoa<T, N> * novo = new Pessoa<T, N>(chave);

		anda = novo;
	}

	if(chave == anda->chave)
		return;

	if(chave < anda->chave)
		InserirRecursivo(anda->esquerda, chave);

	if(chave > anda->chave)
		InserirRecursivo(anda->direita, chave);
}

template <class T, class N>
void Rede_Social<T, N>::Imprime()
{
	ImprimeRec(raiz);
}

template <class T, class N>
void Rede_Social<T, N>::ImprimeRec(Pessoa<T, N> * x)
{
	if(x == NULL)
		return;	

	ImprimeRec(x->esquerda);
	cout << x->chave << " " << x->nome;
	ImprimeRec(x->direita);
}
