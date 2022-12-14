/**********************************************************************************
 *
hola1.c
Generacion de varios threads y modificacion del numero de threads mediante:
export OMP_NUM_THREADS=4
**********************************************************************************/
#include <stdio.h>

#ifdef _OPENMP

#include <omp.h>
#define TRUE 1
#define FALSE 0

#else

#define omp_get_thread_num() 0
#define omp_get_num_threads() 1

#endif

#define N 4    // Número máximo de nucleos

int tid, nthr; // identificador del thread y numero de threads
int i, A[N];

int main ( void )
{

    for ( i = 0 ; i<N ; i++ ) 
    {
        A[i] = 0; 
    }

#pragma omp parallel private(tid)
    {
        nthr = omp_get_num_threads();
        tid = omp_get_thread_num();
        printf ("Thread %d de %d en marcha \n", tid, nthr);
        A[tid] = tid + 10;
        printf ("El thread %d ha terminado \n", tid);
    }

    for ( i = 0 ; i < N ; i++ ) 
    {
        printf ("A(%d) = %d \n", i, A[i]);

    }

    return 0;

}
