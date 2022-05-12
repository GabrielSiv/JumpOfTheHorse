#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "menu.h"
#include "matrizes.h"

#define TAM 8


int main()
{
    int matriz[TAM][TAM];

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    menuNav(matriz);
}

