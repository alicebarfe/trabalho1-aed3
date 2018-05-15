#include "ABB.h"
//define (pensar se vai colocar

Amizades AmizadeNula() {	//caso não encontre o id da amizade ou não existe, ret. -1
	Amizade Am;
	Am.id = -1;
	return Am;
}

//criando a arvore de amizades
Arvore * CriaArvore() {
	Arvore * A = new struct;
	A->raiz = NULL;
	return A;
}

no *CriaNo(Amizades Am) {
	no * N = new int;
	N->conteudo = Am;
	N->esq = NULL;
	N->dir = NULL;
	
	return N;
}
