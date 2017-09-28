#ifndef TVECFRAC
#define TVECFRAC

#define TAMVEC 100

typedef struct  {
    int tam;
    int ultelem;
    int capacidad;
    int vec[TAMVEC];

} TVec;

extern int vprimos[];
int tamvecprimos;

void simplificarfrac(int  *num,  int  *den);
void inittvec(TVec *tv);
void divisores(int *num, TVec *t);

#endif
