/**********************************************************************************
 sincro1.c
 Ejemplo para ver como sincronizar un bucle
 B(i) = B(i) + 3
 C(i) = B(i-1) * 5
 sincronizacion mediante un contador. MAL: se bloquea.
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

#define N 17 

int main( void )
{

    int tid, i;
    int C[N], suma;
    int B[N];
    int KB;

    // inicializacion de datos
     for( i = 0 ; i < N ; i++ )
     {
         B[i] = i;
         C[i] = 0;
     }

     KB = 0; // contador de sincronizacion 

#pragma omp parallel shared(B,C, KB) private(tid)
{
     tid = omp_get_thread_num();

     #pragma omp for schedule(static,1)
     for ( i = 1 ; i < N ; i++ )
     {

         B[i] = B[i] + 3;

         printf("\n >> Thread %d esperando a que KB = %d", tid, i-1);

         while ( KB < (i - 1) );     // espera para sincronizacion wait(KB,i-1)
         KB = i; // post(KB,i)
                 //
         C[i] = B[i-1] * 5;

     }
}

    suma = 0;

    for ( i = 0 ; i < N ; i++ )
    {
        suma += C[i];
    }

    printf("\n\n\n C(%d) es %d KB es %d \n\n", N-1, C[N-1], KB);

    printf("\n Valores de B ");

    for ( i = 0 ; i < N ; i++ )
    {
        printf(" %d ", B[i]);
    }

    printf("\n\n");

    printf("\n Valores de C ");

    for ( i = 1 ; i < N ; i++ )
    {
        printf(" %d ", C[i]);
    }

    printf("\n\n");

    printf ("Suma de C es: %d\n\n", suma); 

    return 0;
}
