#ifndef REDESOCIAL_HPP
#define REDESOCIAL_HPP

#include <iostream>
#include <string>

using namespace std;

template <class C, class A> //C = chave, A = amigos;
class No {
	public:
		No(C chave, A amigos);
		C chave;
		A amigos;
		No *esq, *dir;
		//arvore<C, A> *Amizades; //amizades
};

template <class C, class A>
No<C, A>::No(C ch, A co) {
	chave = ch;
	amigos = co;
	esq = NULL;
	dir = NULL;
	//amigos->arvore();
}

template <class C, class A>
class Amizades {
	public:
		No<C, A> *raiz;
		Amizades();
		void Inserir(C chave, A conteudo);
		void InserirIterativo(C chave, A conteudo);
		void InserirRecursivo(No<C, A> * & anda, C chave, A conteudo);
		A Remover(C chave);
		A RemoverRecursivo(No<C, A> * & anda, C chave);
		A Buscar(C chave);
		A BuscarIterativo(C chave);
		A BuscarRecursivo(No<C, A> * anda, C chave);
		void Imprime();
		void ImprimeRec(No<C, A> * x);
};

template <class C, class A>
Amizades<C, A>::Amizades() {
	raiz = NULL;
}

template <class C, class A>
void Amizades<C, A>::Inserir(C chave, A conteudo) {
	//InserirIterativo(chave, conteudo);
	InserirRecursivo(raiz, chave, conteudo);
}

template <class C, class A>
void Amizades<C, A>::InserirIterativo(C chave, A conteudo) {
	No<C, A> * novo = new No<C, A>(chave, conteudo);

	if(raiz == NULL) {
		raiz = novo;
	}
	else {
		No<C, A> * anda = raiz;

		while(anda->chave != chave) {
			if(chave > anda->chave) {
				if(anda->dir == NULL)
					anda->dir = novo;
				anda = anda->dir;
			} else if(chave < anda->chave) {
				if(anda->esq == NULL)
					anda->esq = novo;
				anda = anda->esq;
			}
		}
	}
}

template <class C, class A>
void Amizades<C, A>::InserirRecursivo(No<C, A> * & anda, C chave, A conteudo) {
	if(anda == NULL) {
		No<C, A> * novo = new No<C, A>(chave, conteudo);
		anda = novo;
	}
	if(chave == anda->chave)
		return;

	if(chave < anda->chave)
		InserirRecursivo(anda->esquerda, chave, conteudo);

	if(chave > anda->chave)
		InserirRecursivo(anda->direita, chave, conteudo);
}

template <class C, class A>
A Amizades<C, A>::Buscar(C chave) {
	//return BuscarIterativo(chave);
	return BuscarRecursivo(raiz, chave);
}

template <class C, class A>
A Amizades<C, A>::BuscarIterativo(C chave) {
	No<C, A> * anda = raiz;

	while(anda != NULL) {
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
	return A();
}

template <class C, class A>
A Amizades<C, A>::BuscarRecursivo(No<C, A> * anda, C chave) {
	if(anda == NULL)
		return A();

	if(chave == anda->chave)
		return anda->amigos;

	if(chave < anda->chave)
		return BuscarRecursivo(anda->esq, chave);

	if(chave > anda->chave)
		return BuscarRecursivo(anda->dir, chave);
}

template <class C, class A>
A Amizades<C, A>::Remover(C chave) {
	return RemoverRecursivo(raiz, chave);
}

template <class C, class A>
A Amizades<C, A>::RemoverRecursivo(No<C, A> * & anda, C chave) {
	if(anda == NULL)
		return A();

	if(chave == anda->chave) {
		A amigos = anda->amigos;
		//Caso 3: 2 Filhos
		if(anda->esq != NULL && anda->dir != NULL) {
			//Encontrar maior da esquerda de anda
			No<C, A> * ME = anda->esq;
			while(ME->dir != NULL)
				ME = ME->dir;

			C chaveME = ME->chave;
			anda->amigos = RemoverRecursivo(anda->esq, ME->chave);
			anda->chave = chaveME;
		} else {
			No<C, A> * novoanda;
			//Caso 1: Nó Folha
			if(anda->esq == NULL && anda->dir == NULL) {
				novoanda = NULL;
			}
			//Caso 2: 1 Filho (direita)
			else if(anda->esq == NULL && anda->dir != NULL) {
				cout << "achou caso" << endl;
				novoanda = anda->dir;
			}
			//Caso 2: 1 Filho (esquerda)
			else if(anda->dir == NULL && anda->esq != NULL) {
				novoanda = anda->esq;
			}
			delete anda;
			anda = novoanda;
		}
		return amigos;
	}
	if(chave < anda->chave)
		return RemoverRecursivo(anda->esq, chave);
	else if(chave > anda->chave)
		return RemoverRecursivo(anda->dir, chave);
}

template <class C, class A>
void Amizades<C, A>::Imprime() {
	ImprimeRec(raiz);
}

template <class C, class A>
void Amizades<C, A>::ImprimeRec(No<C, A> * x) {
	if(x == NULL)
		return;	

	ImprimeRec(x->esq);
	cout << x->chave << " ";
	x->amigos.Imprime();
	ImprimeRec(x->dir);
}

#endif
