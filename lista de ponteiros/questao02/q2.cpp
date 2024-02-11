#include<stdio.h>
#include<stdlib.h>
/*2. Escreva um programa que contenha duas variaveis inteiras. Compare seus enderec ̧os e  ́
exiba o maior enderec ̧o.*/
int main()
{
    printf("Digite um numero:");
    int val1 = 0;
    scanf("%d",&val1);
    printf("Digite outro numero:");
    int val2 = 0;
    scanf("%d",&val2);
    if(val1 > val2){
        printf("%p",val1);
    }else{
        printf("%p",val2);
    }
    
    system("pause");
    return 0;
}
