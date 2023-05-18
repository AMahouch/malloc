#include <stdlib.h>
#include <stdio.h>

int main()
{
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
    }
    
    for(k = 0; k < 500; k += 2)
    {
        free(ptrs[k]);
    }
    for(k = 1; k < 500; k += 2)
    {
        free(ptrs[k]);
    }

    return 0;
}