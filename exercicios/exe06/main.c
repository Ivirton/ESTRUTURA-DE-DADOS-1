#include <stdio.h>
#include <stdlib.h>
int main()
{
    int array[4] = {3,5,7,8},*pont;
    pont = array;
   for (int i = 0; i < 4; i++)
   {
        //aritimética de ponteiros
        printf(" %d \n",*(pont+i));
   }
    system("pause");
    return 0;
}
