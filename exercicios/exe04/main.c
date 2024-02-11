#include <stdio.h>
#include <stdlib.h>
main(){
    int n1 = 4;float n2 = 0;char ch = 'p' ;
     //exibir antes
    printf("%d\n",n1);
    printf("%f\n",n2);
    printf("%c\n",ch);
    printf("-----------\n");
    //atribuiçao dos endereços das variaveis para os ponteiors
    int *pInt = &n1; 
    float *pFloat = &n2;
    char *pChar = &ch;
    *pInt = 3;
    *pFloat = 4.3;
    *pChar = 't';
    //exibir depois
    printf("%d\n",*pInt);
    printf("%f\n",*pFloat);
    printf("%c\n",*pChar);
    system("pause");
    
}