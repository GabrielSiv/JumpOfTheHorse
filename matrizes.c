#include "matrizes.h"
#include <stdio.h>

int count;

void desenhaMatriz(int matriz[TAM][TAM])
{
    int i,j;
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            if(matriz[i][j] > 9){
                printf("    %d", matriz[i][j]);
            }else{
            printf("     %d", matriz[i][j]);
            }
        }
        printf("\n\n\n");
    }
}

int start(int matriz[TAM][TAM])
{
    count = 1;
    int i = 0, j = 0, i1 = 0, j1 = 0;
    while(i<=0 || i > 8)
    {
        desenhaMatriz(matriz);
        printf("   Selecione uma linha entre 1 e 8 para iniciar: ");
        scanf("%d", &i);
        system("cls");
    }
    i--;
    while(j<=0 || j > 8)
    {
        desenhaMatriz(matriz);
        printf("   Selecione uma coluna entre 1 e 8 para iniciar: ");
        scanf("%d", &j);
        system("cls");
    }
    j--;
    system("cls");

    for(i1=0; i1<TAM; i1++)
    {
        for(j1=0; j1<TAM; j1++)
        {
            if(i1==i && j1==j)
            {
                matriz[i1][j1] = 1;
            }
            else
            {
                matriz[i1][j1] = 0;
            }
        }
    }

    atualizaMatriz(matriz);

    return 1;
}
void atualizaMatriz(int matriz[TAM][TAM])
{
    int i,j, maiorValor = 0, maiorValorLinha, maiorValorColuna;
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            if(matriz[i][j] != 0)
            {
                matriz[i][j];
                if(matriz[i][j] > maiorValor)
                {
                    maiorValor = matriz[i][j];
                    maiorValorLinha = i;
                    maiorValorColuna = j;
                }
            }
        }
    }
    system("cls");
    desenhaMatriz(matriz);
    movePeca(matriz, maiorValorLinha, maiorValorColuna);
}
int movePeca(int mat[TAM][TAM], int i1, int j1)
{
    int x,i,j, matriz[TAM][TAM], breakPoint, i2, j2, vetBreak[8], countVetBreak = 0;
    char tecla;

    printf("   Pressione uma tecla para executar um movimento: ");
    tecla = getche();
    fflush(stdin);
    if(tecla)
    {
        for(i=0;i<TAM; i++){
        vetBreak[i] = 0;
    }
        do
        {
            breakPoint = 0;
            x = rand()%TAM;
            switch(x)
            {
            case 0:
                i2 = i1 + 1;
                j2 = j1 + 2;
                vetBreak[x] = x + 1;
                break;
            case 1:
                i2 = i1 + 1;
                j2 = j1 - 2;
                vetBreak[x] = x + 1;
                break;
            case 2:
                i2 = i1 - 1;
                j2 = j1 + 2;
                vetBreak[x] = x + 1;
                break;
            case 3:
                i2 = i1 - 1;
                j2 = j1 - 2;
                vetBreak[x] = x + 1;
                break;
            case 4:
                i2 = i1 + 2;
                j2 = j1 + 1;
                vetBreak[x] = x + 1;
                break;
            case 5:
                i2 = i1 + 2;
                j2 = j1 - 1;
                vetBreak[x] = x + 1;
                break;
            case 6:
                i2 = i1 - 2;
                j2 = j1 + 1;
                vetBreak[x] = x + 1;
                break;
            case 7:
                i2 = i1 - 2;
                j2 = j1 - 1;
                vetBreak[x] = x + 1;
                break;
            }
            x = 0;
            if(mat[i2][j2] == 0)
            {
                breakPoint = 1;
            }

            countVetBreak = 0;

            for(i=0; i<TAM; i++)
            {
                countVetBreak = countVetBreak + vetBreak[i];
            }
            if(countVetBreak == 36 && mat[i2][j2] != 0)
            {
                casasVisitadas();
                return 0;
            }
        }
        while(i2 < 0 || i2 > 7 || j2 < 0 || j2 > 7 || breakPoint == 0);
    }
    system("cls");
    desenhaMatriz(mat);
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            if(i==i2 && j==j2)
            {
                matriz[i][j] = ++count;
            }
            else if(mat[i][j] !=0)
            {
                matriz[i][j] = mat[i][j];
            }
            else
            {
                matriz[i][j] = 0;
            }
        }
    }
    atualizaMatriz(matriz);
    return 1;
}
int casasVisitadas()
{
    return(count);
}
