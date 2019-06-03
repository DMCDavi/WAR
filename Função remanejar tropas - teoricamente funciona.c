#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "global.h"
#include "inicio.h"
#include "ferramentas.h"
#include "rodada.h"
//Essa biblioteca contÃ©m as funÃ§Ãµes principais de cada rodada do jogo
void remanejar_tropas(){ 
	
	char posicao_pais1, posicao_pais2; //vai receber a letra do pais 
	
	int num_pais1, num_pais2, cont_num_pais, tropas_player[3]; 
	char resp[4];
	
	//iniciar o remanejamento
	fflush(stdin);
	printf("Deseja remanejar? [sim][nao]\n");
	scanf("%s",resp);
	fflush(stdin);
	
	//loopin pra continuar a remaneja
	while(strcmp(resp,"sim") == 0 || strcmp(resp,"SIM") == 0 || strcmp(resp,"Sim") == 0 || strcmp(resp,"SIm") == 0 || strcmp(resp,"sIM") || strcmp(resp, "siM") == 0){
		fflush(stdin);
		printf("Digite a letra do pais que deseja a saida de tropas:\n");
		scanf("%s", &posicao_pais1); 
		fflush(stdin);
		
		
		//VERFICA EXISTENCIA PAIS
		while(!teste_existencia_pais(posicao_pais1) || !teste_dono_pais(posicao_pais1)){
			fflush(stdin);
			printf("[ERRO - O PAIS NAO EXISTE OU NAO TE PERTENCE]\n");
			printf("Digite a letra do pais que deseja a saida de tropas:\n");
			scanf("%s", &posicao_pais1); 
			fflush(stdin);	
		}
		
		printf("%s,Digite a letra do pais que deseja a entrada de tropas:\n", player[vez]);
		scanf("%s", &posicao_pais2);
		 
		//VERFICA EXISTENCIA PAIS		
		while(!teste_existencia_pais(posicao_pais2) || !teste_dono_pais(posicao_pais2)){ // testara se o pais existe ou se o joagdor da vez possui o pais
			fflush(stdin);
			printf("[ERRO - O PAIS NAO EXISTE OU NAO TE PERTENCE]\n");
			printf("Digite a letra do pais que deseja a entrada de tropas:\n");
			scanf("%s", &posicao_pais2); 
			fflush(stdin);
		}
		
		if(teste_vizinhanca_pais(posicao_pais1,posicao_pais2)){
			//insire a quantidade de tropas pra remanejar
			int qntdTropasRemanejar =0;
			int qtd_Tropas_Pais_Entrada = 0;
			printf("insira a quantidade de tropas que voce quer remanejar\n");
			scanf("%d", &qntdTropasRemanejar);
			
			//VERIFICAR SE ELE PODE FAZER O REMANEJAMENTO	
			if(posicao_pais1 >= 65 && posicao_pais1 <= 84){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais1 = posicao_pais1 - 65;
				
			} else if(posicao_pais1 >= 97 && posicao_pais1 <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais1 = posicao_pais1 - 97;
								
			}
			
			int qtd_Tropas_Pais_Saida = tropas_pais[num_pais1];
			
			if(posicao_pais2 >= 65 && posicao_pais2 <= 84){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais2 = posicao_pais2 - 65;
				
			} else if(posicao_pais2 >= 97 && posicao_pais2 <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais2 = posicao_pais2 - 97;
				
			}
		
		
			
			//PEGA QUANTIDADE DE TROPAS DO PAIS
			
			//REMANEJAR TROPAS	
		}else{
			printf("[ERRO - OS PAISES SELECIONADOS NAO PODEM FAZER DESLOCAMENTO]\n");
			continue;
		}
		
		
		fflush(stdin);
		printf("Deseja remanejar mais? [sim][nao]\n");
		scanf("%s",resp);
		fflush(stdin);
	}		
	while(strcmp(resp,"nao") == 0 || strcmp(resp,"NAO") == 0 || strcmp(resp,"Nao") == 0 || strcmp(resp,"NAo") == 0 || strcmp(resp,"naO") || strcmp(resp, "nAO") == 0){
		print("Seu turno acabou, indo para o proximo player!\n");
	}
	
}
