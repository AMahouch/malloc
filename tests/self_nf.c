#include <stdio.h>
#include <stdlib.h>

int main()
{

// env LD_PRELOAD=lib/libmalloc-nf.so tests/self_nf

int i, j, k;
  void* ptrs[500];
    for(i = 0; i < 500; i++) 
    {
        ptrs[i] = malloc(100);
        if(ptrs[i] == NULL)
        {
            printf("Error: failed to allocate memory.\n");
            exit(1);
        }

        for(j = 0; j < 100; j++)
        {
            *((char *)ptrs[i] + j) = (char)i;
        }

        void* more_ptrs[100];

        for(int l = 0; l < 100; l++)
        {
            more_ptrs[l] = malloc(l*4);
            more_ptrs[l] = more_ptrs[l];
        }
    for(k = 0; k < 500; k += 2)
    {
        // free(ptrs[k]);
    }
    for(k = 1; k < 500; k += 2)
    {
        // free(ptrs[k]);
    }
    }

}