#include <iostream>
#include <cstdlib>

typedef struct {
	int id;
} Amizades;

struct No {
	Amizades conteudo;
	struct No * dir;
	struct No * esq;
};

typedef struct No no;

typedef struct {
	no * raiz;
} Arvore;

Arvore * CriaArvore();
void Inserir(Arvore * A, Amizades Am);
Amizades Buscar(Arvore * A, int id);
Amizades Remover(Arvore *A, int id);
Amizades AmizadeNula();
void Imprimir(Arvore * A);
