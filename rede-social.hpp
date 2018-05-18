#include <iostream>
#include <cstdlib>

/* Cada nó armazena três informações:
   nesse caso um número (num),
   ponteiro para subárvore à direita (esq)
   e ponteiro para subárvore à esquerda (dir).*/

typedef struct amigos
{
  int num;
  struct amigos* esq;
  struct amigos* dir;
} Amizade;

/* A estrutura da árvore é representada por um ponteiro
   para o nó raiz. Com esse ponteiro, temos acesso aos
   demais nós. */

/* Função que cria uma árvore */
Amizade* createAmizade()
{
  /* Uma árvore é representada pelo endereço do nó raiz,
     essa função cria uma árvore com nenhum elemento,
     ou seja, cria uma árvore vazia, por isso retorna NULL. */
  return NULL;
}

/* Função que verifica se uma árvore é vazia */
int amizadeVazia(Amizade* t)
{
  /* Retorna 1 se a árvore for vazia e 0 caso contrário */
  return t == NULL;

}

/* Função que mostra a informação da árvore */
void mostrarAmigos(Amizade* t)
{
  /* Essa função imprime os elementos de forma recursiva */
  
  printf("<"); /* notação para organizar na hora de mostrar os elementos */
  if(!amizadeVazia(t)) /* se a árvore não for vazia... */
  {
    /* Mostra os elementos em pré-ordem */
    printf("%d ", t->num); /* mostra a raiz */
    mostrarAmigos(t->sae); /* mostra a esq (subárvore à esquerda) */
    mostrarAmigos(t->sad); /* mostra a dir (subárvore à direita) */
  }
  printf(">"); /* notação para organizar na hora de mostrar os elementos */
}

/* Função que insere um dado na árvore */
void inserirAmigos(Amizade** t, int num)
{
  /* Essa função insere os elementos de forma recursiva */
  if(*t == NULL)
  {
    *t = (Amizade*)malloc(sizeof(Amizade)); /* Aloca memória para a estrutura */
    (*t)->esq = NULL; /* Subárvore à esquerda é NULL */
    (*t)->dir = NULL; /* Subárvore à direita é NULL */
    (*t)->num = num; /* Armazena a informação */
  } else {
    if(num < (*t)->num) /* Se o número for menor então vai pra esquerda */
    {
      /* Percorre pela subárvore à esquerda */
      inserirAmigos(&(*t)->esq, num);
    }
    if(num > (*t)->num) /* Se o número for maior então vai pra direita */
    {
      /* Percorre pela subárvore à direita */
      inserirAmigos(&(*t)->dir, num);
    }
  }
}

/* Função que verifica se um elemento pertence ou não à árvore */
int ehAmigo(Amizade* t, int num) {
  
  if(amizadeVazia(t)) { /* Se a árvore estiver vazia, então retorna 0 */
    return 0;
  }
  
  /* O operador lógico || interrompe a busca quando o elemento for encontrado */
  return t->num==num || isInTree(t->sae, num) || isInTree(t->sad, num);
}ostream>
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
	direita = NUL

