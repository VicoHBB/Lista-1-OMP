/**********************************************************************************
 nested.c
 Ejemplo de regiones paralelas anidadas
**********************************************************************************/
#include <stdio.h>
#ifdef _OPENMP

#include <omp.h>
#define TRUE 1
#define FALSE 0

#else

#define omp_get_thread_num() 0
#define omp_get_num_threads() 1
#define omp_get_nested() 0
#define omp_get_level() 0

#endif

int main( void )
{

    int tid = -1;

#ifdef _OPENMP

    (void) omp_set_num_threads(4);
    (void) omp_set_nested(TRUE);

    if ( !omp_get_nested() ) 
    {
        printf("Cuidado! No se ha activado el paralelismo anidado \n");
    }

#endif

    printf("Paralelismo anidado esta %s\n", omp_get_nested() ? "activado" : "no activado" );

#pragma omp parallel private (tid)
{
    tid = omp_get_thread_num();
    printf("TID(%d) ejecuta la region externa (nivel: %d)\n",tid,omp_get_level());
    #pragma omp parallel num_threads(3)
    {
        printf(" >>>TID(%d.%d): El thread %d ejecuta la region interna (nivel: %d)\n", tid, omp_get_thread_num()
                                                                                     , omp_get_thread_num()
                                                                                     , omp_get_level() );
    }
}
    return 0;
}
