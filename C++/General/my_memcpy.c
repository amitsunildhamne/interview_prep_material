#include <stdio.h>

void my_memcpy(void *src, void *dest, int length)
{
   int i;
   for(i = 0; i < length; ++i)
   {
     *(char *)((char *)dest + i) = *(char *)((char *)src + i);
   }
}

int main()
{
   int src[100];
   int i = 0;
   for(i = 0; i < 100; ++i)
   {
      src[i] = i;
   }
   int dest[100];
   int length = 100;
   my_memcpy((void *)dest, (void *)src, length );
   return 0;
}
