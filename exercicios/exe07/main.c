/*Faça um programa que leia um quantidade de elementos n, crie dinamicamente um vetor de n
elementos e passe esse vetor para uma função que irá ler seus elementos. Em seguida, o vetor
preenchido deve ser impresso.*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int* pont = (int*)  malloc(sizeof(int));
    *pont = 55;
    *(pont+1) = 45;
    //pont  = (int*) malloc(sizeof(int));
    printf("%d \n",sizeof(pont));
    system("pause");
    return 0;
}
