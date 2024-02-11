#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct{
    int array[MAX];
    int top;
}Stack;

void barras(){
    printf("-----------------\n");
}
void iniciarPilha(Stack *pilha){
    pilha->top = -1;
}
int size(Stack *pilha){
    return pilha->top;
}
void push(Stack *pilha,int valor){
    if(pilha->top == (MAX-1)){
        printf("Pilha cheia");
        return;
    }
    pilha->top++;
    pilha->array[pilha->top] = valor;
}
int pop(Stack *pilha){
    if(pilha->top == -1){
        printf("pilha vazia\n");
        return -1;
    }
    int remover = pilha->array[pilha->top];
    pilha->top--;
    return remover;

}
void imprimir(Stack *pilha){
    barras();
    for (int i = 0; i < size(pilha); i++){
        printf("%d\n",pilha->array[i]);
    }
    barras();
}

int main()
{
    Stack pilha1;
    iniciarPilha(&pilha1);
    push(&pilha1,22);
    push(&pilha1,24);
    push(&pilha1,26);
    imprimir(&pilha1);
    pop(&pilha1);
    imprimir(&pilha1);
    system("pause");
    return 0;
}
