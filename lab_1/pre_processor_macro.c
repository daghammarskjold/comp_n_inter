#include <stdio.h>
#include <stdlib.h>
#define SUM(x,y) (x+y)
#define FACTORIAL(n) n==0?:(n*FACTORIAL(n-1))


int main(){
    int a, b;
    a = 3;
    b = 4;
    //printf("Sum of %d and %d is %d\n", a, b, SUM(a,b));
    printf("Factoral of %d is %d\n", b, FACTORIAL(b));
}