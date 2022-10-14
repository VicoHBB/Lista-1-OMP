/**************************************************************************
var1.c
ambito de variables (ejemplo transparencias )
**************************************************************************/

//Predecir antes de ejecutar lo que tiene que salir
//Ojo con el uso de variables private sin inicializar (-> firstprivate)

#include <stdio.h>

#ifdef _OPENMP

#include <omp.h>
#define TRUE 1
#define FALSE 0

#else

#define omp_get_thread_num() 0
#define omp_get_num_threads() 1

#endif

int tid, x = -1 , y = -1 , z = -1;

int main( void )
{

    x = 2;
    y = 1;

    printf("\n\n ANTES --> x = %d\t y = %d\t z = %d\n", x, y, z);

#pragma omp parallel shared( y ) firstprivate( x, z )        // cambiar el private por fisrt private
{

    tid = omp_get_thread_num();                              // Changes to get the correct id

    if( tid == 0 )
    {
        printf("\n\n DENTRO(1) --> x = %d\t y = %d\t z = %d\n", x, y, z);
    }

    z = ( x * x ) + 3;
    x = ( y * 3 ) + z;

    if( tid == 1 )
    {
        printf("\n\n DENTRO(2) --> x = %d\t y = %d\t z = %d\n", x, y, z);
    }
}

    printf("\n\n FUERA --> x = %d\t y = %d\t z = %d\n", x, y, z);

    return 0;
}
