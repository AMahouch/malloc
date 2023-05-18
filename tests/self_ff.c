#include <stdio.h>
#include <stdlib.h>

int main()
{

// env LD_PRELOAD=lib/libmalloc-ff.so tests/self_ff

  void * ptr_arr[1000];
  for(int k = 0; k < 1000; k++)
  {
    ptr_arr[k] = (char*) malloc(2*k + 1 );
    ptr_arr[k] = ptr_arr[k];
  }


  char * ptr1 = ( char * ) malloc( 2048 );

  free( ptr1 );

  char * ptr2 = ( char * ) malloc( 1024 );

  free( ptr2 );


  ptr1 = ( char * ) malloc ( 65535 );
  char * buffer1 = ( char * ) malloc( 1 );
  free(buffer1);

  char * ptr4 = ( char * ) malloc ( 65 );
  char * buffer2 = ( char * ) malloc( 1 );
  ptr2 = ( char * ) malloc ( 6000 );

  char* ptr5 = (char*) malloc(401);
  char* ptr6 = (char*) malloc(34);
  char* ptr7 = (char*) malloc(15);
  char* ptr8 = (char*) malloc(646);
  char* ptr9 = (char*) malloc(3);
  char* ptr10 = (char*) malloc(1);

  free(ptr7);

  char* ptr11 = (char*) malloc(45);

  free(ptr8);

  char* ptr12 = (char*) malloc(34);
  char* ptr13 = (char*) malloc(15);
  char* ptr14 = (char*) malloc(646);

  free(ptr5);
  free(ptr9);

  char* ptr15 = (char*) malloc(3);
  char* ptr16 = (char*) malloc(1);

  char* ptr17 = malloc(100203449);
  if(ptr17 != NULL)
  {
    char* ptr[10000];

    for(int i = 0; i < 10000; i++)
    {
        ptr[i] = (char* ) malloc(i+1);

        if(i % 3 != 0)
        {
            free(ptr[i]);
        }
        ptr[i] = ptr[i];
    }
  }

    void* ptrs[1000];
    for(int i = 0; i < 1000; i++) 
    {
        ptrs[i] = malloc(100);
        if(ptrs[i] == NULL)
        {
            printf("Error: failed to allocate memory.\n");
            exit(1);
        }

        for(int j = 0; j < 100; j++)
        {
            *((char *)ptrs[i] + j) = (char)i;
        }
    }
    
    for(int k = 0; k < 1000; k += 2)
    {
        free(ptrs[k]);
    }
    for(int k = 1; k < 1000; k += 2)
    {
        free(ptrs[k]);
    }

    free(ptr16);
    free(ptr15);
    free(ptr14);
    free(ptr13);
    free(ptr12);
    free(ptr11);
    free(ptr10);
    free(ptr6);
    free(ptr2);
    free(buffer2);
    free(ptr4);
    free(ptr1);


 
    





}