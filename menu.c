#include "menu.h"

int desenhaMenuPrincipal()
{
    int usuarioNaveg = 0;
    do
    {
        system("cls");
        printf("  Bem vindo ao Random Jump of The Horse!\n");
        printf("\n\n  Pressione a tecla da ação que deseja executar: \n\n");
        printf("\n    1 - Como jogar...");
        printf("\n    2 - Iniciar jogo...");
        printf("\n    3 - Sair do jogo...\n    ");
        scanf("%d", &usuarioNaveg);

    }
    while(usuarioNaveg < 1 || usuarioNaveg > 3);
    return usuarioNaveg;
}
void desenhaComoJogar()
{
    int usuarioNaveg;
    do
    {
        system("cls");
        printf("\n       Antes de mais nada é preciso ter em mente que o jogo\n   se baseia na movimentação que o cavalo realiza no xadrez.\n       Ou seja, a peça se movimenta em L, independente da di-\n   reção.\n\n      Em Random Jump of The Horse, como o próprio nome já diz\n");
        printf("   o cavalo dará saltos aleatórios, portanto, basta pressionar \n   qualquer tecla do seu teclado para realizar o movimento até \n   que as opções se esgotem!");
        printf("\n\n\n   Pressione 1 para voltar ao menu anterior: ");
        scanf("%d", &usuarioNaveg);
    }
    while(usuarioNaveg != 1);
}
void menuNav(int matriz[TAM][TAM])
{
    int menuFlag, jogarNovamente = 1, casasRestantes, i, j;
    do
    {
        menuFlag = 0;

        for(i=0; i<TAM; i++)
        {
            for(j=0; j<TAM; j++)
            {
                matriz[i][j] = 0;
            }
        }
        while(menuFlag == 0)
        {

            switch(desenhaMenuPrincipal())
            {
            case 1:
                desenhaComoJogar();
                break;
            case 2:
                system("cls");
                menuFlag = 1;
                start(matriz);
                break;
            case 3:
                printf("\n\n   Obrigado por jogar!\n\n");
                system("pause");
                return 0;
            }
        }
        casasRestantes = TABULEIRO - casasVisitadas();

        printf("\n\n   O cavalo visitou um total de %d casas no jogo.", casasVisitadas());
        printf("\n   Restaram %d casas não visitadas pelo cavalo.", casasRestantes);
        printf("\n\n   Deseja jogar novamente? Sim (1) / Não (0): ");
        fflush(stdin);
        scanf("%d", &jogarNovamente);
    }
    while(jogarNovamente == 1);
    printf("\n\n   Obrigado por jogar!\n\n   ");
    system("pause");
}
