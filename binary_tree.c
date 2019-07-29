#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
  int info;
  struct No *esq, *dir;
} No;

typedef No *p_no;

p_no inserir(p_no raiz, int chave){
  p_no novo;
  if (raiz == NULL){
    novo = malloc(sizeof(No));
    novo->esq = novo->dir = NULL;
    novo->info = chave;
    return novo;
  }
  if (chave < raiz->info){
    raiz->esq = inserir(raiz->esq, chave);
  }
  else{
    raiz->dir = inserir(raiz->dir, chave);
  }
  return raiz;
}

void pre_ordem(p_no raiz){
  if (raiz != NULL){
    printf("%d ", raiz->info);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
  }
}

void pos_ordem(p_no raiz){
  if (raiz != NULL){
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d ", raiz->info);
  }
}

void in_ordem(p_no raiz){
  if (raiz != NULL){
    in_ordem(raiz->esq);
    printf("%d ", raiz->info);
    in_ordem(raiz->dir);
  }
}

p_no liberar_arvore(p_no r){
  if (r!=NULL){
    r->esq = liberar_arvore(r->esq);
    r->dir = liberar_arvore(r->dir);

    free(r);
  }
  return NULL;
}

int altura(p_no raiz){
  int h_esq, h_dir;
  if (raiz==NULL){
    return 0;
  }
  else{
    h_esq = 1+altura(raiz->esq);
    h_dir = 1+altura(raiz->dir);
    if (h_esq > h_dir)
      return h_esq;
    else
      return h_dir;
  }
}

int max(int a, int b){
  if (a>b)
    return a;
  else
    return b;
}

int diametro(p_no tree){
  if (tree == NULL){
    return 0;
  }
  int laltura = altura(tree->esq);
  int raltura = altura(tree->dir);
  int ldiametro = diametro(tree->esq);
  int rdiametro = diametro(tree->dir);
  return max(laltura+raltura+1, max(ldiametro,rdiametro));
}

int main(){
  int n, i, chave, D;
  char comando[4];
  p_no no = NULL;
  while (1){
    scanf("%d %s", &n, comando);
    if (comando[0] == '0')
      break;
    for(i=0; i<n; i++){
      scanf("%d", &chave);
      no = inserir(no, chave);
    }
    D = diametro(no);
    printf("Diametro da arvore binaria: %d\n", D);
    if (comando[0] == 'p' && comando[1] == 'o'){
      pos_ordem(no);
      printf("\n");
    }
    else if (comando[0] == 'i'){
      in_ordem(no);
      printf("\n");
    }
    else if (comando[0] == 'p' && comando[1] == 'r'){
      pre_ordem(no);
      printf("\n");
    }
    no = liberar_arvore(no);
    D = 0;
  }
  return 0;
}
