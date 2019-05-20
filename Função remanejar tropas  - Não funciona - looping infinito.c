#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "global.h"
#include "inicio.h"
#include "ferramentas.h"
#include "rodada.h"
//Essa biblioteca contém as funções principais de cada rodada do jogo

void remanejar_tropas(){ // 
	
	char posicao_pais1, posicao_pais2; //vai receber a letra do pais 
	
	int num_pais1, num_pais2, cont_num_pais, qntd_paises_player1 = 0, qntd_paises_player2 = 0, tropas_player[3], num_tropas_add; 

	for(cont_num_pais = 0; cont_num_pais < 21; cont_num_pais++){ //percorre a matriz pais[21][4] em busca dos numeros 1 e 2 que definirão a que player cada pais pertence
		
		if(pais[cont_num_pais][0] == '1'){ //se o pais tiver o numero 1, a variavel qntd_paises_player1 vai aumentar em 1
			
			qntd_paises_player1++;
			
		} else{ //se o pais tiver o numero 2, a variavel qntd_paises_player2 vai aumentar em 1
			
			qntd_paises_player2++;
			
		}
		
	} tropas_player[0] = qntd_paises_player1 / 2; //armazena na variavel tropas_player[0] a quantidade de tropas que o player 1 tem disponivel para adicionar em seus paises
	
	tropas_player[1] = qntd_paises_player2 / 2; //armazena na variavel tropas_player[1] a quantidade de tropas que o player 2 tem disponivel para adicionar em seus paises

	while(tropas_player[vez] != 0){ //vai repetir o processo de adicionar as tropas até a quantidade de tropas disponiveis do player acabar
	
		printf("%s, voce possui %d tropas adicionais.\nDigite a letra do pais que deseja adicionar suas tropas:\n", player[vez], tropas_player[vez]); //diz a quantidade e quem vai começar a adicionar as tropas
		
		scanf("%s", &posicao_pais1); 
		
		fflush(stdin);
		
		printf("%s, voce possui %d tropas adicionais.\nDigite a letra do pais que deseja adicionar suas tropas:\n", player[vez], tropas_player[vez]); //diz a quantidade e quem vai começar a adicionar as tropas
		
		scanf("%s", &posicao_pais2); 
		
		fflush(stdin);
		if(teste_dono_pais(posicao_pais1) && teste_dono_pais(posicao_pais2)){ //prossegue com o código apenas se o país digitado pelo usuário pertencer a ele, senão pede pra digitar novamente
			
			if(posicao_pais1 >= 65 && posicao_pais1 <= 84 ){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que será usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais1 = posicao_pais1 - 65;
				
			} else if(posicao_pais1 >= 97 && posicao_pais1 <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que será usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais1 = posicao_pais1 - 97;
				
			}
			
			if(posicao_pais2 >= 65 && posicao_pais2 <= 84 ){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que será usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais2 = posicao_pais2 - 65;
				
			} else if(posicao_pais2 >= 97 && posicao_pais2 <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que será usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais2 = posicao_pais2 - 97;
				
			}
			
			
			
			if(/*teste_existencia_pais(num_pais1) && teste_existencia_pais(num_pais2)*/ true){ //se a letra digitada estiver entre A e T maiusculo ou minusculo, o processo continua, senão pede pra digitar novamente
		
				if(tropas_pais[num_pais1] >= 2){
					if(/*teste_vizinhanca_pais(num_pais1, num_pais2)*/true){
						printf("%s, voce possui %d tropas .\nDigite o numero de tropas que voce deseja remanejar do pais [%c] para [%c]:\n", player[vez], tropas_player[vez], posicao_pais1, posicao_pais2);
						int reman_tropas;
						scanf("%d", &reman_tropas);
						while(reman_tropas<=0 || reman_tropas>=tropas_pais[num_pais1]){
							system("cls");
							printf("[ERRO] %s, voce possui %d tropas .\nDigite o numero de tropas que voce deseja remanejar do pais [%c] para [%c]:\n", player[vez], tropas_player[vez], posicao_pais1, posicao_pais2);
							scanf("%d", &reman_tropas);
						}
						
						tropas_pais[num_pais1] += reman_tropas;
						tropas_pais[num_pais2] -= reman_tropas;
					}
				
				}else{
					printf("Quantidade de tropas no pais insuficiente!!");
					
				}
					
					
		} else{
				
				printf("Pais nao registrado. Digite novamente.\n"); //printa na tela essa mensagem caso a letra digitada não seja referente a nenhum país
				
			}
			
		} else{
			
			printf("O pais digitado nao te pertence. Digite novamente.\n"); //printa na tela essa mensagem caso o país não pertença ao player da vez
		
		} 
		
	}
	
}

void remanejar_tropas(){ // 
	
	char posicao_pais1, posicao_pais2; //vai receber a letra do pais 
	
	int num_pais1, num_pais2, cont_num_pais, tropas_player[3]; 
	char resp[4];
	
	//iniciar o remanejamento
	printf("Deseja remanejar? [sim][nao]");
	scanf("%[^\n]s",resp);
	
	//loopin pra continuar a remanejar
	while(strcmp(resp,"sim") || resp,"Sim") || resp,"SIM");{
		
		printf("Digite a letra do pais que deseja a saida de tropas:\n");
		scanf("%s", &posicao_pais1); 
		fflush(stdin);
		
		//VERFICA EXISTENCIA PAIS
		while(!teste_existencia_pais(posicao_pais1) || teste_dono_pais(posicao_pais1)){
			printf("[ERRO] Digite a letra do pais que deseja a saida de tropas:\n");
			scanf("%s", &posicao_pais1); 
			fflush(stdin);
		}
		
		printf("Digite a letra do pais que deseja a entrada de tropas:\n");
		scanf("%s", &posicao_pais2);
		 
		//VERFICA EXISTENCIA PAIS		
		while(!teste_existencia_pais(posicao_pais2) || teste_dono_pais(posicao_pais2)){
			printf("[ERRO] Digite a letra do pais que deseja a saida de tropas:\n");
			scanf("%s", &posicao_pais2); 
			fflush(stdin);
		}
		
		//insire a quantidade de tropas pra remanejar
		int qntdTropasRemanejar =0;
		printf("insira a quantidade de tropas que voce quer remanejar");
		scanf("%d", &qntdTropasRemanejar);
			
		//POPULAR NUM_PAIS
		if(posicao_pais1 >= 65 && posicao_pais1 <= 84 ){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÂ¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
			
			num_pais1 = posicao_pais1 - 65;
			
		} else if(posicao_pais1 >= 97 && posicao_pais1 <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÂ¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
			
			num_pais1 = posicao_pais1 - 97;
			
		}
		
		if(posicao_pais2 >= 65 && posicao_pais2 <= 84 ){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÂ¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
			
			num_pais2 = posicao_pais2 - 65;
			
		} else if(posicao_pais2 >= 97 && posicao_pais2 <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÂ¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
			
			num_pais2 = posicao_pais2 - 97;
			
		}
		
		
		//VERIFICAR SE ELE PODE FAZER O REMANEJAMENTO
		
		//PEGA QUANTIDADE DE TROPAS DO PAIS
		
		//REMANEJAR TROPAS
		
		
		printf("Deseja remanejar mais? [sim][nao]");
		scanf("%[^\n]s",resp);
	}		
}
