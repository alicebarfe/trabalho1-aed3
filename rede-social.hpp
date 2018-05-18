#ifndef REDE-SOCIAL_HPP
#define REDE-SOCIAL_HPP

#include <iostream>
#include <cstdlib>

typedef struct amigos {
	int num;
	struct amigos* esq;
	struct amigos* dir;
} Amizade;

Amizade* criaAmizade();

int amizadeVazia(Amizade* a);

void mostraAmizade(Amizade* a);

void insereAmigos(Amizade** a, int num);

int ehAmigo(Amizade* a, int num);

#endif
