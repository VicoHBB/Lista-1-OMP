/**********************************************************************************
 histo_ser.c
**********************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> 

#define N 10 /* luego 6000 */
#define NG 10 /* luego 256 */

int main( void )
{

     struct timeval t0, t1;
     double tej; 

     int IMA[N][N], histo[NG], B[N], C[N];
     int i, j, tid, hmin, imin, spm = 0, x;

     // Inicializacion de variables( aleatorio )
     for( i = 0 ; i < N ; i++ )
     {
       for ( j = 0 ; j < N ; j++ )
       {
           IMA[i][j] = rand() % NG;
       }
     }

     // se imprimen 10 elementos de 10 filas de IMA
     printf("\n Matriz IMA ");

     for( i = 0 ; i < 10 ; i++ )
     {

         printf("\n");

         for ( j = 0 ; j < 10 ; j++ )
         {
             printf(" %3d", IMA[i][j]);
         }

         printf("\n");

     }

     for( i = 0 ; i < NG ; i++ )
     {
         histo[i] = 0;
     }

     // toma de tiempos
     gettimeofday(&t0, 0);

     // 1. Calculo del histograma de IMA
     for ( i = 0 ; i < N ; i++ )
     {
         for ( j = 0 ; j < N ; j++ )
         {
             histo[IMA[i][j]]++;
         }
     }

     // 2. Busqueda del minimo del histograma
     hmin = N*N+1;
     for( i = 0 ; i < NG ; i++ )
     {
         if( hmin > histo[i] )
         {
             hmin = histo[i];
             imin = i;
         }
     }

     // Calculo de B, C y SPM
     for( i = 0 ; i < N ; i++ )
     {

         j = 0;
         x = 0;

         while( ( IMA[i][j] != imin ) && ( j < N ) )
         {
             x = x + IMA[i][j] ;
             j++;
         }

         B[i] = x;
         C[i] = j;
         spm = spm + j;

     }

     // toma de tiempos
     gettimeofday( &t1, 0 );

     // Imprimir resultados
     printf("\n Histograma \n");

     for( i = 0 ; i < 10 ; i++ )
     {
         printf("%5d", i);
     }

     printf("\n");

     for( i = 0 ; i < 10 ; i++ )
     {
         printf("%5d", histo[i]);
     }

     printf("\n hmin = %d imin = %d\n", hmin, imin);

     printf("\n Vector B \n");

     for ( i = 0 ; i < 10 ; i++ )
     {
         printf(" %3d", B[i]);
     }

     printf("\n Vector C \n");

     for ( i = 0 ; i < 10 ; i++ )
     {
         printf(" %3d", C[i]);
     }

     printf("\n SPM = %d\n\n", spm);

     tej = (t1.tv_sec - t0.tv_sec) + (t1.tv_usec - t0.tv_usec) / 1e6;
     printf("\n T. ejec. (serie) = %1.3f ms \n\n", tej*1000);

     return 0;
}
