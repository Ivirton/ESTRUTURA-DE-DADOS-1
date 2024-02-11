#include <stdio.h>
#include <stdlib.h>

main(){

    float notas[9];
    int aux = 0;
    float maior = 0;
    for (int i = 0; i<9; i++)
    {
        printf("Digite nota do aluno(a) %d:",i+1);
        scanf("%f",&notas[i]);
        if (notas[i] > maior)
        {
            maior = notas[i];
        }
    }
    printf("\n Maior nota: %1.2f \n",maior);
    system("pause");
    return 0;
}