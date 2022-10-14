/**********************************************************************************
hola2.c
Definición del numero de threads mediante la funcion omp_set_num_threads()
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
    printf("\nIntroduce el numero de threads ---> ");
    scanf("%d",&nthr);

#ifdef _OPENMP
    omp_set_num_threads(nthr);
#endif

#pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        printf ("Thread %d en marcha \n", tid);
        A[tid] = tid + 10;
        printf ("El thread %d ha terminado \n", tid);
    }

    for ( i=0; i < N ; i++ )
    {
        printf ("A(%d) = %d \n", i, A[i]);
    }

    return 0;

}
