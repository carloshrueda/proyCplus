#include "tadfrac.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
//#include <string.h>

int tamvecprimos;


void simplificarfrac(int  *num,  int  *den)
{
    TVec vdivnum;
    //TVec vdivden;

    inittvec(&vdivnum);
    divisores(num, &vdivnum);
}

void inittvec(TVec *tv)
{
    tv->tam= 0;
    tv->ultelem= -1;
    //inizializando el vector en ceros
    for(register int i=0; i<TAMVEC; i++)
        *(tv->vec + i)= 0;

    //Calcular el tamaño del vector
    for(tamvecprimos=0; vprimos[tamvecprimos]; ++tamvecprimos);
}

void divisores(int *num, TVec *t)
{
    register int i;
    //register int raiznum= (int) ceil(sqrt(*num));
    for(i = 0; ( ( vprimos[i] ) && (vprimos[i]<=*num) ); i++ )
    {
        if ((*num % vprimos[i]) == 0)
        {
            ++t->ultelem;
            t->vec[t->ultelem]= vprimos[i];
            ++(t->tam);
            *num= *num / vprimos[i];
            printf("i: %d || div: %d ||num: %d\n", i, vprimos[i], *num);
            --i;
        }
    }
    printf("num: %d\n", *num);
    //printf("raiz: %d\n", raiznum);
    printf("i: %d\n", i);
    printf("vprimos[i]: %d\n", vprimos[i]);
    for(int k=0; k<t->tam; k++)
        printf("%d, ", t->vec[k]);
    printf("\n-------------\n");

    if(*num > vprimos[tamvecprimos-1]) {
        for(i=vprimos[tamvecprimos-1]+2; i<=*num; i+=2)
        {
            if (*num % i == 0)
            {
                ++t->ultelem;
                t->vec[t->ultelem]= i;
                ++(t->tam);
                *num= *num / i;
                printf("i: %d || num: %d\n", i, *num);
                i -= 2;
            }

        }
        for(int k=0; k<t->tam; k++)
            printf("%d, ", t->vec[k]);
        printf("\n-------------\n");
    }
}


int vprimos[] = {
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37,
    41,
    43,
    47,
    53,
    59,
    61,
    67,
    71,
    73,
    79,
    83,
    89,
    97,
    101,
    103,
    107,
    109,
    113,
    127,
    131,
    137,
    139,
    149,
    151,
    157,
    163,
    167,
    173,
    179,
    181,
    191,
    193,
    197,
    199,
    211,
    223,
    227,
    229,
    233,
    239,
    241,
    251,
    257,
    263,
    269,
    271,
    277,
    281,
    283,
    293,
    307,
    311,
    313,
    317,
    331,
    337,
    347,
    349,
    353,
    359,
    367,
    373,
    379,
    383,
    389,
    397,
    401,
    409,
    419,
    421,
    431,
    433,
    439,
    443,
    449,
    457,
    461,
    463,
    467,
    479,
    487,
    491,
    499,
    503,
    509,
    521,
    523,
    541
};
