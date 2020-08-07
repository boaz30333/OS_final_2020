#define  _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* 1. BSS data section*/
int primes[] = { 2, 3, 5, 7 };  /* 2.initialized data section */

static int
square(int x)                   /* 3. function instruction on text section and the veriables on "square" stack frame*/
{
    int result;                 /* 4. on "squere" stack frame */

    result = x * x;
    return result;              /* 5.  return value passed by register*/
}

static void
doCalc(int val)                 /* 6. text section */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7.  on "doCalc" stack frame  */

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /* 8. function instruction on text section and the veriables on "main" stack frame */
{
    static int key = 5;      /* 9.  BSS data section*/
    static char mbuf[10240000]; /* 10. initialized data section */
    char* p= key;                    /* 11. main stack frame but actually not alocted at all after optimazation */
    doCalc(key);


    exit(EXIT_SUCCESS);
}