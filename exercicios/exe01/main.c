#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	printf("nome:");
		char nome[10];
		scanf("%s",nome);		
		char sexo = 'a';
		printf("sexo M/F:");
		scanf(" %c",&sexo);
  		
		if (1==strcmp(&sexo,"m"))
		{
			printf("Bem vindo %s \n",nome);
		}else if (1==strcmp(&sexo,"f"))
		{
			printf("Bem vinda %s \n",nome);
		}
		
		system("pause");
	return  0;
}