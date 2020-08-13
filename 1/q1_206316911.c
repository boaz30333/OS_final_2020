#define  _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* 1. BSS data section*/
int primes[] = { 2, 3, 5, 7 };  /* 2.initialized data section */

static int
square(int x)                   /* 3. function instruction on text section and 
                                    and x veriable send by register and saved on
                                "square" stack frame that opened to "square" function*/
{
    int result;                 /* 4. on "squere" stack frame */

    result = x * x;
    return result;              /* 5.  return value passed by register*/
}

static void
doCalc(int val)                 /* 6. function instruction on text section and val veriable send by register and saved on
                                "doCalc" stack frame that opened to "doCalc" function*/
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7.  on "doCalc" stack frame  */

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /* 8.  function instruction on text section and  veriables send by register and saved on
                                "main" stack frame that opened to "main" function*/
{
    static int key = 5;      /* 9.  BSS data section*/
    static char mbuf[10240000]; /* 10. initialized data section */
    char* p= key;                    /* 11. main stack frame but actually not alocted at all after optimazation */
    doCalc(key);


    exit(EXIT_SUCCESS);
}