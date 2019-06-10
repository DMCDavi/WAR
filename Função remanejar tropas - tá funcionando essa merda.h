void remanejar_tropas(){ 
	
	char posicao_pais1, posicao_pais2; //vai receber a letra do pais 
	
	int num_pais1, num_pais2, cont_num_pais, tropas_player[3], cont_remanejar, qtd_Tropas_Pais_Saida_Original[21]; 
	char resp[4];
    for(cont_remanejar = 0; cont_remanejar<21; cont_remanejar++){
    		qtd_Tropas_Pais_Saida_Original[cont_remanejar] = tropas_pais[cont_remanejar];
	}
	cont_remanejar = 1;
	//iniciar o remanejamento
	fflush(stdin);
	printf("Deseja remanejar? [sim][nao]\n");
	scanf("%s",resp);
	fflush(stdin);
	
	//loopin pra continuar a remanejar
	while(strcasecmp(resp,"sim") == 0){
		fflush(stdin);
		printf("Digite a letra do pais que deseja a saida de tropas:\n");
		scanf("%c", &posicao_pais1); 
		fflush(stdin);
		
		
		//VERFICA EXISTENCIA PAIS
		while(!teste_existencia_pais(posicao_pais1) || !teste_dono_pais(posicao_pais1)){
			fflush(stdin);
			text_color(4);
			printf("[ERRO - O PAIS NAO EXISTE OU NAO TE PERTENCE]\n");
			printf("Digite a letra do pais que deseja a saida de tropas:\n");
			scanf("%c", &posicao_pais1); 
			fflush(stdin);	
		}
		printf("\n========================================================\n");
		
		printf("%s,Digite a letra do pais que deseja a entrada de tropas:\n", player[vez]);
		scanf("%c", &posicao_pais2);
		 
		//VERFICA EXISTENCIA PAIS		
		while(!teste_existencia_pais(posicao_pais2) || !teste_dono_pais(posicao_pais2)){ // testara se o pais existe ou se o joagdor da vez possui o pais
			fflush(stdin);
			printf("[ERRO - O PAIS NAO EXISTE OU NAO TE PERTENCE]\n");
			printf("Digite a letra do pais que deseja a entrada de tropas:\n");
			scanf("%c", &posicao_pais2); 
			fflush(stdin);
		}
		
		if(teste_vizinhanca_pais(posicao_pais1,posicao_pais2)){
			//insire a quantidade de tropas pra remanejar
			int qntdTropasRemanejar =0;
			printf("insira a quantidade de tropas que voce quer remanejar\n");
			scanf("%d", &qntdTropasRemanejar);
			

			//PEGA QUANTIDADE DE TROPAS DO PAIS 1
			if(posicao_pais1 >= 65 && posicao_pais1 <= 84){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais1 = posicao_pais1 - 65;
				
			} else if(posicao_pais1 >= 97 && posicao_pais1 <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais1 = posicao_pais1 - 97;
								
			}
			
			int qtd_Tropas_Pais_Saida = 0;
			
			qtd_Tropas_Pais_Saida = qtd_Tropas_Pais_Saida_Original[num_pais1]; 
			
			//PEGA QUANTIDADE DE TROPAS DO PAIS 2
			if(posicao_pais2 >= 65 && posicao_pais2 <= 84){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais2 = posicao_pais2 - 65;
				
			} else if(posicao_pais2 >= 97 && posicao_pais2 <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais2 = posicao_pais2 - 97;
				
			}
			
			int qtd_Tropas_Pais_Entrada = 0;
			
			qtd_Tropas_Pais_Entrada = tropas_pais[num_pais2];
			
			printf("\n========================================================\n");
			printf("[Tropas pais saida]: %d\n", qtd_Tropas_Pais_Saida);
			printf("[Tropas pais entrada]: %d\n", qtd_Tropas_Pais_Entrada);
			printf("\n========================================================\n");

			//VERIFICAR SE ELE PODE FAZER O REMANEJAMENTO	
			if((qtd_Tropas_Pais_Saida) > 1 && (qtd_Tropas_Pais_Saida - qntdTropasRemanejar > 1)){
				
				//tropas 				
				qtd_Tropas_Pais_Saida-= qntdTropasRemanejar;
				
				qtd_Tropas_Pais_Entrada+= qntdTropasRemanejar;
				
				tropas_pais[num_pais1] = qtd_Tropas_Pais_Saida;
				
				tropas_pais[num_pais2] = qtd_Tropas_Pais_Entrada;
				
			}else{
				text_color(4);
				printf("[ERRO - NAO HA TROPAS SUFICIENTES PARA REMANEJAMENTO!]\n");
				continue;
			}
		}else{
			text_color(4);
			printf("[ERRO - OS PAISES SELECIONADOS NAO PODEM FAZER DESLOCAMENTO]\n");
			continue;
		}
		
		system("cls");
		print_mapa();
		
		printf("\n========================================================\n");
		fflush(stdin);
		printf("Deseja remanejar mais? [sim][nao]\n");
		scanf("%s",resp);
		cont_remanejar++;
	}
			
	printf("\t\t\t\t\t\t\t\tSeu turno acabou, indo para o proximo player!\n");	
}
