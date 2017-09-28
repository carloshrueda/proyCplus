#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "tadfrac.h"

void leerNumeros(int *num, int *den) {
	int n;
	char msgerror[255];

	printf("Numerador: ");
	n = scanf("%d", num);
	if (n != 1) {
		if (errno != 0) {
			perror(msgerror);
			puts(msgerror);
			printf("\n");
			exit(1);
		} else {
			printf("Error. No se pudo leer el numerador.\n");
			exit(1);
		}
	}
	printf("Denominador: ");
	n = scanf("%d", den);
	if (n != 1) {
		if (errno != 0) {
			perror(msgerror);
			puts(msgerror);
			printf("\n\n");
			exit(1);
		} else {
			printf("Error. No se pudo leer el denominador.\n\n");
			exit(1);
		}
	}

}

int main(void) {
	int num, den;

	leerNumeros(&num, &den);

	if ((num > 0) && (den > 0)) {
		simplificarfrac(&num, &den);
	}

	return 0;

}
