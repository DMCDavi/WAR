//Essa biblioteca contÃ©m as bibliotecas essenciais, as constantes e as variÃ¡veis globais

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>


#define AUX 13
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

char pais[21][4]; //variÃ¡vel que serÃ¡ usada na funÃ§Ã£o nome_paises para receber a nomeaÃ§Ã£o de cada paÃ­s

char num_player[2], letra_pais[3]; //num_player armazenarÃ¡ os numeros 1 ou 2 referentes a cada player; letra_pais armazenarÃ¡ as letras que representarÃ£o cada paÃ­s

char player[3][100], player1[100], player2[100]; //variÃ¡veis que receberÃ£o os nicks dos players; player[0] vai receber o jogador que iniciarÃ¡ o jogo e vez_player[1] vai receber o player que nÃ£o vai iniciar o jogo

int vez = 0; //armazenarÃ¡ os valores 0 ou 1, que servirÃ£o como parÃ¢metro pra saber de quem Ã© a vez na rodada, onde 0 representa o player que iniciou o jogo e 1 o outro player

int tropas_pais[21] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; //tropas_pais armazena a quantidade de tropas de cada paÃ­s, onde cada valor do vetor representa um pais

unsigned int posicao_pais_encontrado_ataque = 0, posicao_pais_encontrado_defesa = 0;

unsigned int qntd_tropas_bonus_player1 = 0, qntd_tropas_bonus_player2 = 0;

unsigned int qntd_paises_player1 = 0, qntd_paises_player2 = 0; //representam a quantidade de paises que cada player possui
