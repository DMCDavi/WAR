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
	while(strcmp(resp,"sim") == 0 || strcmp(resp,"SIM") == 0 || strcmp(resp,"Sim") == 0 || strcmp(resp,"SIm") == 0 || strcmp(resp,"sIM") == 0){
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
		while(!teste_existencia_pais(posicao_pais2) || !teste_dono_pais(posicao_pais2)){
			fflush(stdin);
			printf("[ERRO - O PAIS NAO EXISTE OU NAO TE PERTENCE]\n");
			printf("Digite a letra do pais que deseja a entrada de tropas:\n");
			scanf("%s", &posicao_pais2); 
			fflush(stdin);
		}
		
		if(teste_vizinhanca_pais(posicao_pais1,posicao_pais2)){
			//insire a quantidade de tropas pra remanejar
			int qntdTropasRemanejar =0;
			printf("insira a quantidade de tropas que voce quer remanejar\n");
			scanf("%d", &qntdTropasRemanejar);
				
		
			//VERIFICAR SE ELE PODE FAZER O REMANEJAMENTO
			
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
}
