#include "rede-social.hpp"
#include <iostream>

/* A estrutura da árvore é representada por um ponteiro
   para o nó raiz. Com esse ponteiro, temos acesso aos
   demais nós. */

Amizade* criaAmizade() {
/* Uma árvore é representada pelo endereço do nó raiz,
   essa função cria uma árvore com nenhum elemento,
   ou seja, cria uma árvore vazia, por isso retorna NULL. */
	return NULL;
}

int amizadeVazia(Amizade *a) {
	return a == NULL;
}

void mostraAmizade(Amizade* a) {
	cout << " < ";
	if(!amizadeVazia(a)) {
		cout << a->num;
		mostraAmizade(a->esq);
		mostraAmizade(a->dir);
	}
	cout << " > ";
}

void insereAmigos(Amizade** a, int num) {
	if(*a == NULL) {
		Amizade* nova_amizade = new Amizade;
		nova_amizade->num = num;
		nova_amizade->esq = esq;
		nova_amizade->dir = dir;
	} else {
		if(num < nova_amizade->num) {
			insereAmigos(*nova_amizade->esq, num)
		}
		if(num > nova_amizade->num) {
			insereAmizade(*nova_amizade->dir, num)
		}
	}
}

int ehAmigo (Amizade* a, int num) {
	if(amizadeVazia(a)) {
		return 0;
	}
	return a->num == num || ehAmigo(a->esq, num) || ehAmigo(a->dir, num);
}
