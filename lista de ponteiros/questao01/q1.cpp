#include<stdio.h>
#include<stdlib.h>
/*
Escreva um programa que declare um inteiro, um real e um char, e ponteiros para in-
teiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de  ́

cada variavel usando os ponteiros. Imprima os valores das vari  ́ aveis antes e ap  ́ os a  ́
modificac ̧ao.  ̃
 ̃*/


int main()
{
    int inteiro = 3;
    float real = 4.6;
    char caracter = 'c';
    printf("ANTES\n");
    printf("inteiro:  %d\n",inteiro);
    printf("real:  %f\n",real);
    printf("caracter:  %c\n",caracter);
    int *prtInter = &inteiro;
    float *ptrFloat = &real;
    char *ptrCaracter = &caracter;
    *prtInter = 55;
    *ptrFloat = 55.6;
    *ptrCaracter = 'h';
    printf("DEPOIS\n");
    printf("ANTES\n");
    printf("inteiro:  %d\n",inteiro);
    printf("real:  %f\n",real);
    printf("caracter:  %c\n",caracter);
    system("pause");
    return 0;
}
