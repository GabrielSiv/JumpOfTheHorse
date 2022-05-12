#define TAM 8
#define TABULEIRO 64

//Responsável por desenhar a matriz na tela do usuário.
void desenhaMatriz(int matriz[TAM][TAM]);

//Responsável por fazer a checagem de casas disponíveis
//e, se possível, mover a peça aleatoriamente para uma
//dessas casas.
int movePeca(int mat[TAM][TAM], int i1, int j1);

//Responsável por atualizar a matriz, inserindo o valor
//da última movimentação do cavalo na casa onde ele está
//após isso invoca desenhaMatriz para desenhar a matriz
//atualizada.
void atualizaMatriz(int matriz[TAM][TAM]);

//Responsável pela primeira inicialização da matriz, onde
//recebe uma matriz limpa como parâmetro e solicita que o
//usuário entre com valores válidos para linha e coluna.
//Além de resetar o contador de casas percorridas.
int start(int matriz[TAM][TAM]);

//Responsável por retornar o valor do contador de casas
//que será resetado após uma nova inicialização da ap-
//plicação.
int casasVisitadas();
