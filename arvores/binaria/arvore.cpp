#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int conteudo;
    no *esqueda, *direitra;
}No;
typedef struct{
    No *raiz;
}Arvore;

No* novo_no(){
    no *novo = (no*) malloc(sizeof(no));
    novo->direitra = NULL;
    novo->esqueda = NULL;
    return novo;
}
void inserirDireita(No *noDireita,int valor);
void inserirEsquerada(No *noEsqueda,int valor){
    if(noEsqueda->esqueda == NULL){
        No *novo = novo_no();
        novo->conteudo = valor;
        noEsqueda->esqueda = novo;
    }else{
     if(valor < noEsqueda->esqueda->conteudo){
        inserirEsquerada(noEsqueda->esqueda,valor);
     }if(valor > noEsqueda->esqueda->conteudo){
        inserirDireita(noEsqueda->esqueda,valor);
     }
    }
}
void inserirDireita(No *noDireita,int valor){
    if(noDireita->direitra == NULL){
        No *novo = novo_no();
        novo->conteudo = valor;
        noDireita->direitra = novo;
    }else{
        if(valor > noDireita->direitra->conteudo){
            inserirDireita(noDireita->direitra,valor);
        }
        if(valor < noDireita->direitra->conteudo){
            inserirEsquerada(noDireita->direitra,valor);
        }
    }
}
void inserir(Arvore *arv,int valor){
    if (arv->raiz ==  NULL){
        no *novo = novo_no();
        novo->conteudo = valor;
        arv->raiz = novo;
    }
    else{
        if(valor < arv->raiz->conteudo){
           inserirEsquerada(arv->raiz,valor);
        }if(valor > arv->raiz->conteudo){
           inserirDireita(arv->raiz,valor);
        }
    }
}
void imprimir(No *raiz) {
  if(raiz != NULL){
        imprimir(raiz->esqueda);
        printf("%d ",raiz->conteudo);
        imprimir(raiz->direitra);
  }
}

void imprimir2(No *node, int tab = 0) {
  if (node == NULL) return;

  imprimir2(node->direitra, tab + 1);
  for (int i = 0; i < tab; i++) {
    printf("\t");
  }
  printf("%d\n", node->conteudo);
  imprimir2(node->esqueda, tab + 1);
}


int main(){
    system("cls");
    Arvore arv01 ;
    arv01.raiz = NULL;
    inserir(&arv01,500);
    inserir(&arv01,600);
    inserir(&arv01,700);
    inserir(&arv01,400);
    inserir(&arv01,200);
    inserir(&arv01,700);
    inserir(&arv01,1000);
    inserir(&arv01,1200);
    inserir(&arv01,1400);
    inserir(&arv01,1250);
    imprimir2(arv01.raiz);
    return 0;
}
