/*********************************************************
 fibo_ser.c (usleep)
 Ejemplo de uso de la directiva task en un programa
 recursivo para calcular el numero de fibonacci
 f(n) = f(n-1) + f(n-2) con f(0)=1 y f(1)=1
 version serie con usleep
**********************************************************/
#include <stdio.h>
#include <sys/time.h> 
#include <unistd.h> 

long fibonacci( int n )
{
    long fn1, fn2, fn;

    usleep( 2 );

    if (n == 0 || n == 1)
    {
        return 1;
    }

    fn1 = fibonacci(n - 1);
    fn2 = fibonacci(n-2);
    fn = fn1 + fn2;

    return fn;
}

int main( void )
{

    struct timeval t0, t1;
    double tej;
    int n;
    long result;

    printf("\n Numero a calcular? ");
    scanf("%d", &n);

    gettimeofday(&t0, 0);

    result = fibonacci(n);

    gettimeofday(&t1, 0);

    printf ("\nEl numero Fibonacci de %d es %ld", n, result);

    tej = (t1.tv_sec - t0.tv_sec) + (t1.tv_usec - t0.tv_usec) / 1e6;

    printf("\n T. de ejec. = %1.3f ms \n\n", tej*1000);

    return 0;
}
