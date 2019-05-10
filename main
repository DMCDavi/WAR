#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "var_globais.h"

void cadastro_players(){ //função que irá cadastrar os players em nomes de usuario
	
	printf("Bem-vindo ao MINI WAR.\n");
		
	printf("Player 1, digite seu username: ");
	
	scanf(" %[^\n]s", &player1);
	
	printf("Player 2, digite seu username: ");
	
	scanf(" %[^\n]s", &player2);
	
	system("pause");
	
}

void aleat_players(){ //função que define de forma aleatoria quem vai iniciar o jogo
	
	int num_aleatorio;
	
	srand(time(NULL));
	
	num_aleatorio = rand() % 2; //um número aleatório que receberá 0 ou 1
	
	if(num_aleatorio == 0){ //se o número aleatório for 0, o jogo vai iniciar pelo player 1
		
		strcpy(vez_player[0], player1); 
		
		strcpy(vez_player[1], player2);
		
	}else if(num_aleatorio == 1){ //se o numero aletorio for 1, o jogo vai iniciar pelo player 2
		
		strcpy(vez_player[0], player2); 
	
		strcpy(vez_player[1], player1);
	
	}
	
}

void nome_paises(char pais[21][4]){ //função que nomeará os vinte paises com 3 caracteres cada, distribuindo-os aleatoriamente para cada jogador
		
	int cont_nome_pais, num_aleatorio, qntd_paises_player1 = 0, qntd_paises_player2 = 0;
	
	srand(time(NULL));
	
	for(cont_nome_pais = 0; cont_nome_pais < 20; cont_nome_pais++){ //repete 20 vezes a operação pra nomear todos os 20 países
		
		num_aleatorio = rand() % 2; //o numero aleatorio receberá um numero entre 0 e 1
		
		if((num_aleatorio == 0 && qntd_paises_player1 < 10) || qntd_paises_player2 >= 10){ //se o numero aletorio receber 0 e o player 1 ainda não tiver 10 paises sob seu controle ou se a quantidade de paises sob controle do player 2 tiver chegado a 10, o país passará a ser do player 1
			
			strcpy(num_player, "1\0"); //copia 1 na variável num_player
			
			qntd_paises_player1++; //aumenta em 1 a quantidade de paises sob controle do player 1
			
		} else if((num_aleatorio == 1 && qntd_paises_player2 < 10) || qntd_paises_player1 >= 10){ //se o numero aletorio receber 1 e o player 2 ainda não tiver 10 paises sob seu controle ou se a quantidade de paises sob controle do player 1 tiver chegado a 10, o país passará a ser do player 2
		
			strcpy(num_player, "2\0"); //copia 2 na variavel num_player
			
			qntd_paises_player2++; //aumenta em 1 a quantidade de paises sob controle do player 2
			
		} letra_pais[0] = 65 + cont_nome_pais; //define a letra que cada país vai receber, seguindo a tabela ASCII
		
		letra_pais[1] = '-'; //adiciona um hífen que separa a identificação do país das tropas
		
		letra_pais[2] = '\0'; //põe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
		
		strcat(num_player, letra_pais); //concatena a numeração do player com a letra do país e o hífen na variável num_player
		
		strcpy(pais[cont_nome_pais], num_player); //copia na matriz pais[21][4] a identificação de cada país e a qual player pertence 
		
		num_player[0] = '\0'; //põe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
		
		letra_pais[0] = '\0'; //põe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
	}
	
}

void print_mapa(){ //função que printa na tela o mapa
	
	system("color 1F"); //define as cores do mapa
	
	int cont_tropas = 0, cont_linhas, cont_colunas, cont_pais = 0, mapa[40][75] = {
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,7,0,7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,5,2,2,2,6,4,5,2,2,2,6,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,
3,3,3,3,3,3,3,7,0,7,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,0,7,7,0,7,3,7,0,7,7,0,7,7,0,7,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,8,2,2,2,9,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,8,2,2,2,9,4,8,2,2,2,9,8,2,2,2,9,8,2,2,2,9,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,4,5,2,2,2,6,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,0,7,3,7,0,7,7,0,7,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,4,8,2,2,2,9,8,2,2,2,9,8,2,2,2,9,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,3,3,3,7,0,7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,7,0,7,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,0,7,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,7,0,7,7,0,7,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,8,2,2,2,9,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
};
	
	for(cont_linhas = 0; cont_linhas < 40; cont_linhas++ ){ //percorre a matriz mapa toda e substitui seus valores por um caracter especial
		
		for(cont_colunas = 0 ; cont_colunas < 75; cont_colunas++ ){
			
			if(mapa[cont_linhas][cont_colunas] == NEVE){
				
				printf("%c%c",219,219);
					
			}else if(mapa[cont_linhas][cont_colunas] == AGUA){
				
				printf("%c%c",32,32);
										
			}else if(mapa[cont_linhas][cont_colunas] == HORIZONTAL){
				
				printf("%c%c",205,205);
										
			}else if(mapa[cont_linhas][cont_colunas] == VERTICAL){
				
				printf("%c%c",186,186);
										
			}else if(mapa[cont_linhas][cont_colunas] == CANTINFESQ){
				
				printf("%c%c",200,200);
										
			}else if(mapa[cont_linhas][cont_colunas] == CANTINFDIR){
				
				printf("%c%c",188,188);
										
			}else if(mapa[cont_linhas][cont_colunas] == CANTSUPESQ){
				
				printf("%c%c",201,201);	
									
			}else if(mapa[cont_linhas][cont_colunas] == CANTSUPDIR){
				
				printf("%c%c",187,187);
										
			}else if(mapa[cont_linhas][cont_colunas] == CAMINHOHOR){
				
				printf("%c%c",196,196);	
									
			}else if(mapa[cont_linhas][cont_colunas] == CAMINHOVER){
				
				printf("%c%c",124,124);	
									
			}else if(mapa[cont_linhas][cont_colunas] == PAIS){
				
				nome_paises(pais); //chama a função que nomeia cada pais e aramazena cada nome na matriz pais
						
				printf("%s%.3d", pais[cont_pais], tropas_pais[cont_tropas]);	//quando o valor 0 é encontrado na matriz, printa a identificação de cada país seguido da quantidade de tropas
			
				cont_pais++;
				
				cont_tropas++;
			}
				
		}printf("\n");
		
	} printf("======================================================================================================================================================\n");
	
}

void add_tropas(){ //função para adicionar as tropas no inicio de cada rodada
	
	char posicao_pais; //vai receber a letra do pais 
	
	int ascii_posicao_pais, cont_num_pais, qntd_paises_player1 = 0, qntd_paises_player2 = 0, tropas_player[3], teste_v_f = 0, num_tropas_add, cont_maiuscula = 65, cont_minuscula = 97, c, qtp, Y = 10, U; 

	for(cont_num_pais = 0; cont_num_pais < 21; cont_num_pais++){ //percorre a matriz pais[21][4] em busca dos numeros 1 e 2 que definirão a que player cada pais pertence
		
		if(pais[cont_num_pais][0] == '1'){ //se o pais tiver o numero 1, a variavel qntd_paises_player1 vai aumentar em 1
			
			qntd_paises_player1++;
			
		}else{ //se o pais tiver o numero 2, a variavel qntd_paises_player2 vai aumentar em 1
			
			qntd_paises_player2++;
			
		}
		
	} tropas_player[0] = qntd_paises_player1 / 2; //armazena na variavel tropas_player[0] a quantidade de tropas que o player 1 tem disponivel para adicionar em seus paises
	
	tropas_player[1] = qntd_paises_player2 / 2; //armazena na variavel tropas_player[1] a quantidade de tropas que o player 2 tem disponivel para adicionar em seus paises

	printf("%s, voce possui %d tropas adicionais.\nPosicione-as com sabedoria.\n", vez_player[vez], tropas_player[vez]); //diz quem vai começar a adicionar as tropas

	while(tropas_player[vez] != 0){ //vai repetir o processo de adicionar as tropas até a quantidade de tropas disponiveis do player acabar
	
		printf("Digite a letra do pais que deseja adicionar suas tropas:\n");
		
		scanf("%s", &posicao_pais); //lê a letra do pais que o usuario quer adicionar as tropas
		
		fflush(stdin);
		
		ascii_posicao_pais = posicao_pais; //transforma a letra do pais em um numero da tabela ASCII pra posteriormente ver se a letra digitada é válida ou não
		
		while(cont_maiuscula <= 84 || cont_minuscula <= 116){ //percorre os valores da tabela ascii, referentes as letras de A até T maiusculas e minusculas
			
			if(ascii_posicao_pais == cont_minuscula || ascii_posicao_pais == cont_maiuscula){ //caso a letra digitada esteja entre as letras A e T maiusculas e minusculas, a variavel teste_v_f recebe 1
				
				teste_v_f = 1;
				
				break; //para a verificação caso ache a letra válida
			
			} else{ //caso a letra digitada não seja válida, teste_v_f vai receber 0
				
				teste_v_f = 0;
				
			}cont_maiuscula++;
			
			cont_minuscula++;
			
		} cont_maiuscula = 65; //retornando o valor original das variaveis
		
		cont_minuscula = 97; 
		
		if(teste_v_f == 1){ //se a letra digitada for válida o processo continua, senão pede pra digitar novamente
	
			printf("Digite o numero de tropas que voce deseja adicionar nesse pais:\n");
		
			scanf("%d", &num_tropas_add); // Lê o número de tropas que o player quer adicionar no pais
			
			if(num_tropas_add <= tropas_player[vez]){
				
				tropas_player[vez] = tropas_player[vez] - num_tropas_add; //diminui a quantidade de tropas disponiveis
				
			} else{
				
				printf("Voce apenas possui %d tropas. Digite novamente.\n");
				
			}
		
		} else{
			
			printf("Pais nao registrado. Digite novamente.\n"); //printa na tela essa mensagem caso a letra digitada não seja válida
			
		}
		
	}
	
}
//Quantidade de dados por jogador ---TROPAS----
int calcular_Quantidade_Dados_Jogador1(int idRodadaJogador){
	
	
	
	if(idRodadaJogador == 1){

		//aqui pega as variaveis globais (qntd_player1) 

	}else{
		//aqui pega as variaveis globais (qntd_player2) 
	}
	
}


//dados de ataque e defesa
	int ataque (int qtd_dados){
		int dado_ataque[qtd_dados];
		int i;
		int maior_ataque = 0;
		for (i=0; i<qtd_dados; i++){
			srand(time(NULL));
			dado_ataque[i] = (rand() % 5) + 1;
		//pegando o maior numero sorteado pelos dados de ataque para compará-lo com o maior dos de defesa;
			if (maior_ataque < dado_ataque[i]) maior_ataque = dado_ataque[i];			
	}
	return maior_ataque; 
}
int defesa (int i, int dado_defesa[3], int maior_defesa){
	maior_defesa = 0;
	for (i=0; i<3; i++){
		srand(time(NULL));
		dado_defesa[i] = (rand() % 5) + 1;
		//pegando o maior numero sorteado pelos dados de ataque para compará-lo com o maior dos de defesa;	
		if (maior_defesa < dado_defesa[i]) maior_defesa = dado_defesa[i];		
	}
	return maior_defesa; 
}


int main(){
	
	cadastro_players();
	
	aleat_players();
	
	print_mapa();
	
	printf("Cada pais possui uma numeracao seguido de uma letra.\nOs paises de numero 1 pertencem a %s.\nEnquanto os paises de numero 2 pertencem a %s.\n", player1, player2);
	
	system("pause");
	
	add_tropas();
	
	return 0;
	
}
