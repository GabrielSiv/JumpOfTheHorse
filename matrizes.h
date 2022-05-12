#define TAM 8
#define TABULEIRO 64

//Respons�vel por desenhar a matriz na tela do usu�rio.
void desenhaMatriz(int matriz[TAM][TAM]);

//Respons�vel por fazer a checagem de casas dispon�veis
//e, se poss�vel, mover a pe�a aleatoriamente para uma
//dessas casas.
int movePeca(int mat[TAM][TAM], int i1, int j1);

//Respons�vel por atualizar a matriz, inserindo o valor
//da �ltima movimenta��o do cavalo na casa onde ele est�
//ap�s isso invoca desenhaMatriz para desenhar a matriz
//atualizada.
void atualizaMatriz(int matriz[TAM][TAM]);

//Respons�vel pela primeira inicializa��o da matriz, onde
//recebe uma matriz limpa como par�metro e solicita que o
//usu�rio entre com valores v�lidos para linha e coluna.
//Al�m de resetar o contador de casas percorridas.
int start(int matriz[TAM][TAM]);

//Respons�vel por retornar o valor do contador de casas
//que ser� resetado ap�s uma nova inicializa��o da ap-
//plica��o.
int casasVisitadas();
