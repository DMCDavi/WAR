#define TERRA 10
#define NEVE 11
#define AGUA 4
#define CAMINHOHOR 3
#define CAMINHOVER 1
#define HORIZONTAL 2
#define VERTICAL 7
#define CANTINFESQ 8
#define CANTINFDIR 9
#define CANTSUPESQ 5
#define CANTSUPDIR 6
#define PAIS 0

char pais[21][4]; //variável que será usada na função nome_paises para receber a nomeação de cada país

char num_player[2], letra_pais[3]; //num_player armazenará os numeros 1 ou 2 referentes a cada player; letra_pais armazenará as letras que representarão cada país

char vez_player[3][100], player1[100], player2[100]; //variáveis que receberão os nicks dos players; vez_player[0] vai receber o jogador que iniciará o jogo e vez_player[1] vai receber o player que não vai iniciar o jogo

int vez = 0; //armazenará os valores 0 ou 1, que servirão como parâmetro pra saber de quem é a vez na rodada, onde 0 representa o player que iniciou o jogo e 1 o outro player

int tropas_pais[21] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; //tropas_pais armazena a quantidade de tropas de cada país, onde cada valor do vetor representa um pais
