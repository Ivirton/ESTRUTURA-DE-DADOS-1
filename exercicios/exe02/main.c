#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Digite um número maior que 0 e menor que 9:");
    int n = 0;
    scanf("%d",&n);
    if(n > 0 && n<9){
        for (int i = 0; i <= 10; i++)
        {
            printf("%d x %d = %d\n",n,i,(i*n));
        }
        
    }
    
    system("pause");
   
    
    return 0;
}
