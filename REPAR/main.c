/**********************************************************************************
repar.c
reparto de interacciones de un bucle entre los procesos.
hacer un reparto consecutivo del primer bucle y entrelazado del segundo
PARA COMPLETAR
**********************************************************************************/
//// Ejecutar repar_g para que se vea la salida del programa

#include <stdio.h>

#ifdef _OPENMP

#include <omp.h>
#define TRUE 1
#define FALSE 0

#else

#define omp_get_thread_num() 0
#define omp_get_num_threads() 1

#endif

#define N 40    // Número máximo de nucleos


int main ( void )
{
    int A[N], B[N];
    int i, j;

    // ejecutar los bucles en paralelo haciendo el reparto de iteraciones a mano:
    // (bucle 1) consecutivo y (bucle 2) entrelazado
    // para ver que thread ejecuta cada iteracion, cargar en A[i] y B[i] el tid del proceso
    // en lugar de i
    
    for( i = 0 ; i < N ; i++ )
    { 
        A[i] = i;
    }

    for( i = 0 ; i < N ; i++ )
    {
        B[i] = i;
    }

    // impresion de resultados
    

    printf ("\n Vector A, reparto consecutivo \n\n");
    printf (" 0 1 2 3 4 5 6 7 8 9\n");
    printf ("-----------------------------------------\n");

    for ( i = 0 ; i < N/10 ; i++ )
    {

        printf ("\n");

        for ( j = i*10 ; j < (i+1)*10 ; j++ ) 
        {
            printf("%3d ", A[j]);
        }

        printf ("\n");

    }

    printf ("\n\n");
    printf (" Vector B, reparto entrelazado \n\n");
    printf (" 0 1 2 3 4 5 6 7 8 9\n");
    printf ("-----------------------------------------\n");

    for ( i = 0 ; i < N/10 ; i++ )
    {

        printf ("\n");

        for ( j = i*10 ; j < (i+1)*10 ; j++ )
        {
            printf("%3d ", B[j]);
        }

        printf ("\n");

    }

    printf ("\n");

    return 0;

}
