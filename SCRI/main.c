/**************************************************************************
 scri.c
 uso de una seccion critica para planificacion guided de un bucle
 se reparte un cuarto de la parte proporcional
 se hacen N iteraciones en las que una de ellas, N/4, es mucho mas larga
 POR COMPLETAR
****************************************************************************/
//// Esquema dado para teminar

#include <omp.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define N 1000 

int calculo( int T )
{
    usleep( 10 * T );
    return( rand() % 100 );
}

int main( void )
{
    int A[N];
    int j, ini, fin, tid, nthr;
    int larga; // Variable para almacenar el tid del thread que ejecuta la larga
    int ITER[10]; // En ITER[tid] el numero de iter. ejecutadas por el thread tid
    for( j = 0 ; j < N ; j++ )
    {
        A[j] = rand() % 100;
    }

    A[N / 4] = 10000;

    for ( j = 0; j < 10; j++ )
    {
        ITER[j] = 0;
    }

 #pragma omp parallel
 {

     tid = omp_get_thread_num();
     nthr = omp_get_num_threads();

     /* OPERACION DE PLANIFICACION */
     /* Dejar en ini y fin las iteraciones comienzo y fin */
     while ( ini < N )
     {
         /* EJECUTAR TRABAJO PLANIFICADO */
         /* Por cada iteracion hacer: if (A[x] > 90) A[x] = calculo(A[x]); */
         /* OPERACION DE PLANIFICACION */
         /* Dejar en ini y fin las iteraciones comienzo y fin */
     }
 }

    for( j = 0 ; j < nthr ; j++ )
    {
        printf( "\n IT(%d) = %d", j, ITER[j] );
    }

    printf( "\n\n larga --> %d\n\n", larga );

    return 0;
}


