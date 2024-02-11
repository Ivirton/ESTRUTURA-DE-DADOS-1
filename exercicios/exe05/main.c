#include <stdio.h>
#include <stdlib.h>
void dobro(int *a,int *b){
    *a = (*a*2);
    *b = (*b*2);
}
int main()
{
    int a=4,b=8;
    dobro(&a,&b);
    printf("%d %d\n",a,b);
    system("pause");
    return 0;
}                       
