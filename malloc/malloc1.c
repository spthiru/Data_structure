#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *arr;

   arr = (int *) malloc(sizeof (int)*100);
   if(arr == NULL)
   {
      printf("memory allocation failed in heap area\n");
   }

   for(int i = 0; i < 100; i++)
   {
      arr[i] = i;
   }
   for(int i = 0; i < 100; i++)
   {
      printf("%d\n",arr[i]);
   }
}

