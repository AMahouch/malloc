#include <stdio.h>
#include <stdlib.h>

int main()
{

 // env LD_PRELOAD=lib/libmalloc-wf.so tests/self_wf

  char * ptr1 = ( char * ) malloc ( 65535 );
  char * buffer1 = ( char * ) malloc( 1 );
  char * ptr4 = ( char * ) malloc ( 65 );
  char * buffer2 = ( char * ) malloc( 1 );
  char * ptr2 = ( char * ) malloc ( 6000 );

  char * ptr = ( char * ) malloc ( 65535 );


  free( ptr1 ); 
  free( ptr2 ); 

  buffer1 = buffer1;
  buffer2 = buffer2;
  ptr4 = ptr4;

  char * ptr3 = ( char * ) malloc ( 1000 );

  char * ptr_array[4096];

  int i;
  for ( i = 0; i < 4096; i++ )
  {
    ptr_array[i] = ( char * ) malloc ( 4096 ); 
    
    ptr_array[i] = ptr_array[i];
  }

  free( ptr );

  for ( i = 0; i < 4096; i++ )
  {
    if( i % 2 == 0 )
    {
      free( ptr_array[i] );
    }
  }

  ptr = ( char * ) malloc ( 65535 );
  free( ptr ); 

  
//   char * ptr11 = ( char * ) malloc ( 1000 );
//   char * buf12 = ( char * ) malloc ( 1 );
//   char * ptr62= ( char * ) malloc ( 10 );
//   char * buf2 = ( char * ) malloc ( 1 );
//   char * ptr23 = ( char * ) malloc ( 6000 );
//   char * buf34 = ( char * ) malloc ( 1 );
//   char * ptr75= ( char * ) malloc ( 10 );
//   char * buf46 = ( char * ) malloc ( 1 );
//   char * ptr32= ( char * ) malloc ( 1000 );

    


  return 0;
  
}