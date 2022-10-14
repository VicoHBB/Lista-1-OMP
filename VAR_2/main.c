/**************************************************************************
var2.c
hay que declarar correctamente las variables. PARA COMPLETAR.
**************************************************************************/
//// Ejecutar var_g para que se vea que tiene que salir

#include <stdio.h>

#ifdef _OPENMP

#include <omp.h>
#define TRUE 1
#define FALSE 0

#else

#define omp_get_thread_num() 0
#define omp_get_num_threads() 1

#endif

#define N 4

int tid, nth;
int comienzo, fin, x = 0, z = 0, zpar, A[N][N], i, j;

int main( void )
{

    for ( i = 0 ; i < N ; i++ )
    {

        for ( j = 0 ; j < N ; j++ ) 
        {

            A[i][j] = i + j;

        }

    }

    printf("Matriz\n");

#pragma omp parallel default( shared ) private( tid, nth, comienzo, fin, x ) shared( z, zpar )
{
    tid = omp_get_thread_num();
    nth = omp_get_num_threads();

    comienzo = tid * N / nth;
    fin      = (tid+1) * N / nth;

    printf("\n Proceso %d/%d; comienzo = %d, fin = %d \n", tid, nth, comienzo, fin);

    zpar = 0;

    for ( i = comienzo ; i < fin ; i++ )
    {

        for ( j = 0 ; j < N ; j++ )
        {

            x       = A[i][j] * A[i][j];
            A[i][j] = A[i][j] + x;
            zpar    = zpar + x;

        }

    }

    z = z + zpar;

}

    printf("\n --> Matriz A[i][j]\n");

    for(i=0; i<4; i++)
    {

        printf("\n");

        for(j=0; j<4; j++) 
        {  

            printf(" %8d ", A[i][j]);

        }

        printf("\n");

    }

    printf("\n\n --> x, z, zpar = %d, %d, %d \n\n", x, z, zpar);

    return 0;
}
