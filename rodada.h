void add_tropas(){ //funÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o para adicionar as tropas no inicio de cada rodada
	
	char posicao_pais; //vai receber a letra do pais 
	
	unsigned int num_pais, cont_num_pais, tropas_player[3], num_tropas_add; 

	contar_paises();

	if(qntd_paises_player1 <= 6){ //se o player 1 tiver 6 paises ou menos sob seu controle, irÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¡ receber 3 tropas adicionais de qualquer forma
		
		tropas_player[0] = 3;
			
	} else{ //senao, a quantidade de tropas diposniveis para o player 1 sera igual a quantidade de paises sob seu controle dividido por dois
			
		tropas_player[0] = qntd_paises_player1 / 2; //armazena na variavel tropas_player[0] a quantidade de tropas que o player 1 tem disponivel para adicionar em seus paises
			
	} if(qntd_paises_player2 <= 6){ //se o player 2 tiver 6 paises ou menos sob seu controle, irÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¡ receber 3 tropas adicionais de qualquer forma

		tropas_player[1] = 3;
			
	} else { //senao, a quantidade de tropas diposniveis para o player 2 sera igual a quantidade de paises sob seu controle dividido por dois
			
		tropas_player[1] = qntd_paises_player2 / 2; //armazena na variavel tropas_player[1] a quantidade de tropas que o player 2 tem disponivel para adicionar em seus paises
			
	}	
	
	while(tropas_player[vez] != 0){ //vai repetir o processo de adicionar as tropas atÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â© a quantidade de tropas disponiveis do player acabar
		
		if(strcmp(player[vez],player1) == 0){ //se for a vez do player1
						
			text_color(10); 
		}
		else if(strcmp(player[vez],player2) == 0){
						
			text_color(1);
		}
		printf("\n\t\t\t\t\t\t\t     %s, voce possui %d tropas adicionais.\n", player[vez], tropas_player[vez]); //diz a quantidade e quem vai comeÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§ar a adicionar as tropas
		
		printf("\t\t\t\t\t\t\tDigite a letra do pais que deseja adicionar suas tropas\n");
		printf("\t\t\t\t\t\t\t\t\t     :");
		scanf("%s", &posicao_pais); //lÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Âª a letra do pais que o usuario quer adicionar as tropas
		
		fflush(stdin);
		
		if(teste_dono_pais(posicao_pais)){ //prossegue com o cÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â³digo apenas se o paÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â­s digitado pelo usuÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¡rio pertencer a ele, senÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o pede pra digitar novamente
			
			if(posicao_pais >= 65 && posicao_pais <= 84){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais = posicao_pais - 65;
				
			} else if(posicao_pais >= 97 && posicao_pais <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais = posicao_pais - 97;
				
			}
			
			if(teste_existencia_pais(posicao_pais)){ //se a letra digitada estiver entre A e T maiusculo ou minusculo, o processo continua, senÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o pede pra digitar novamente
					
				printf("\n\t\t\t\t\t\t\t     %s, voce possui %d tropas adicionais.\n", player[vez], tropas_player[vez]);
				printf("\t\t\t\t\t\t\tDigite o numero de tropas que voce deseja adicionar nesse pais\n");
				printf("\t\t\t\t\t\t\t\t\t     :");
				scanf("%d", &num_tropas_add); // LÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Âª o nÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Âºmero de tropas que o player quer adicionar no pais
				
				if(num_tropas_add <= tropas_player[vez]){ //sÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â³ prossegue com o cÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â³digo se o nÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Âºmero de tropas que o player quer adicinonar for menor ou igual que o nÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Âºmero de tropas disponÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â­veis que ele possui, senÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o pede pra digitar novamente
								
					if(player[vez] == player1){ //se for a vez do player1
					
						tropas_pais[num_pais] = tropas_pais[num_pais] + num_tropas_add; //adiciona a quantidade desejada de tropas no pais de interesse		
				
					}
					else{ //vez do player2
					
						tropas_pais[num_pais] = tropas_pais[num_pais] + num_tropas_add;
				
					}
				
					
					tropas_player[vez] = tropas_player[vez] - num_tropas_add; //diminui a quantidade de tropas disponiveis
					
					system ("cls"); //limpa a tela
			
					print_mapa(); //imprime o mapa com as novas tropas
					
				} else{
					text_color(4);
					printf("\t\t\t\t\t\t\t [ERRO]Voce apenas possui %d tropas. Digite novamente.\n", tropas_player[vez]);
					
				}
			
		} else{
				text_color(4);
				printf("\t\t\t\t\t\t\t [ERRO]Pais nao registrado. Digite novamente.\n"); //printa na tela essa mensagem caso a letra digitada nÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o seja referente a nenhum paÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â­s
				
			}
			
		} else{
			text_color(4);
			printf("\t\t\t\t\t\t\t [ERRO]O pais digitado nao te pertence. Digite novamente.\n"); //printa na tela essa mensagem caso o paÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â­s nÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o pertenÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§a ao player da vez
		
		} 
		
	}
	
}


void remanejar_tropas(){ 
	
	char posicao_pais1, posicao_pais2; //vai receber a letra do pais 
	
	int num_pais1, num_pais2, cont_num_pais, tropas_player[3], cont_remanejar, qtd_Tropas_Pais_Saida_Original[21], qtd_Tropas_pais_Entrada_Original[21], opcao; 
	char resp[4];
    for(cont_remanejar = 0; cont_remanejar<21; cont_remanejar++){ // laco com um contador para verificar se o pais possuia inicialmente 1 tropa
    		qtd_Tropas_Pais_Saida_Original[cont_remanejar] = tropas_pais[cont_remanejar]; // pega a quantidade de tropas originais do pais de saida
    }
	cont_remanejar = 1;
	//iniciar o remanejamento
	fflush(stdin);
	printf("\t\t\t\t\t\t\tTurno de %s\n", player[vez]);
	printf("\t\t\t\t\t\t\tDeseja remanejar? [sim][nao]\n");
	scanf("%s",resp);
	fflush(stdin);
	
	//loopin pra continuar a remanejar
	while(strcasecmp(resp,"sim") == 0){
		fflush(stdin);
		printf("\t\t\t\t\t\t\tDigite a letra do pais que deseja a saida de tropas:\n");
		scanf("%c", &posicao_pais1); 
		fflush(stdin);
		
		
		//VERFICA EXISTENCIA PAIS
		while(!teste_existencia_pais(posicao_pais1) || !teste_dono_pais(posicao_pais1)){ // fara a verificacao se o pais existe ou esta em posse do jogador do turno.
			fflush(stdin);
			text_color(4);
			printf("\t\t\t\t\t\t\t[ERRO - O PAIS NAO EXISTE OU NAO TE PERTENCE]\n");
			printf("\t\t\t\t\t\t\tDigite a letra do pais que deseja a saida de tropas:\n");
			scanf("%c", &posicao_pais1); 
			fflush(stdin);	
			
		}
		printf("\n\t\t\t\t\t\t\t========================================================\n");
		
		printf("\t\t\t\t\t\t\t%s,Digite a letra do pais que deseja a entrada de tropas:\n", player[vez]);
		printf("\t\t\t\t\t\t\tCaso esteja sem paises proximos, digite ['0'] para sair!:\n");
		scanf("%c", &posicao_pais2);
			if((posicao_pais2 =='0')){
				system("pause");
				system("cls");
				break;
			}
		//VERFICA EXISTENCIA PAIS		
		while(!teste_existencia_pais(posicao_pais2) || !teste_dono_pais(posicao_pais2)){ // testara se o pais existe ou se o joagdor da vez possui o pais
			fflush(stdin);
			printf("\t\t\t\t\t\t\t[ERRO - O PAIS NAO EXISTE OU NAO TE PERTENCE]\n");
			printf("\t\t\t\t\t\t\tDigite a letra do pais que deseja a entrada de tropas:\n");
			scanf("%c", &posicao_pais2);
		
			fflush(stdin); // limba buffer.
		}
		
		if(teste_vizinhanca_pais(posicao_pais1,posicao_pais2)){
			//insire a quantidade de tropas pra remanejar
			int qntdTropasRemanejar =0;
			printf("\t\t\t\t\t\t\tinsira a quantidade de tropas que voce quer remanejar:\n");
			scanf("%d", &qntdTropasRemanejar);
			

			//PEGA QUANTIDADE DE TROPAS DO PAIS 1
			if(posicao_pais1 >= 65 && posicao_pais1 <= 84){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¾Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¾ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¾ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¾Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â¦ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â¦ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais1 = posicao_pais1 - 65; // converte o pais para um numero entre 0 e 19
				
			} else if(posicao_pais1 >= 97 && posicao_pais1 <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¾Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¾ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¾ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¾Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â¦ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â¦ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais1 = posicao_pais1 - 97; // converte o pais para um numero entre 0 e 19
								
			}
			
			int qtd_Tropas_Pais_Saida = 0; // atribui a quantidade do pais de saida 0 para nao dar problema
			
			qtd_Tropas_Pais_Saida = qtd_Tropas_Pais_Saida_Original[num_pais1]; // agora atribui o variavel a outra para comparacao
			
			//PEGA QUANTIDADE DE TROPAS DO PAIS 2
			if(posicao_pais2 >= 65 && posicao_pais2 <= 84){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¾Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¾ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¾ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¾Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â¦ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â¦ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais2 = posicao_pais2 - 65;
				
			} else if(posicao_pais2 >= 97 && posicao_pais2 <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¾Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¾ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¾ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€š ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¾Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â¦ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬ ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â¦ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais2 = posicao_pais2 - 97;
				
			}
			
			int qtd_Tropas_Pais_Entrada = 0; // atribui a quantidade inicial a 0 para nao dar problema
			
			qtd_Tropas_Pais_Entrada = tropas_pais[num_pais2]; // agora atribui o variavel a outra para comparacao
			
			printf("\n========================================================\n");
			printf("[Tropas pais saida]: %d\n", qtd_Tropas_Pais_Saida);
			printf("[Tropas pais entrada]: %d\n", qtd_Tropas_Pais_Entrada);
			printf("\n========================================================\n"); // aqui ele printa a qnt de tropas do pais que esta dando tropas e o pais que esta recebendo tropas 

			//VERIFICAR SE ELE PODE FAZER O REMANEJAMENTO	
			if((qtd_Tropas_Pais_Saida) > 1 && (qtd_Tropas_Pais_Saida - qntdTropasRemanejar >= 1)){ // se a qnt de tropas de onde esta sendo retirada for maior que 1 e se essa quantidade menos a quantidade a ser retirada for maior que 1, o condicao e aceita
				
				//tropas 				
				qtd_Tropas_Pais_Saida-= qntdTropasRemanejar; // retira as tropas do pais de saida
				
				qtd_Tropas_Pais_Entrada+= qntdTropasRemanejar; // adiciona as tropas ao pais de entrada 
				
				tropas_pais[num_pais1] = qtd_Tropas_Pais_Saida; // a variavel tropas_pais do pais 1 agora recebe a qnt de tropas que o pais de saida 
				
				tropas_pais[num_pais2] = qtd_Tropas_Pais_Entrada; // a variavel tropas_pais do pais 2 agora recebe a qnt de tropas que o pais de entrada 
				
			}else{
				text_color(4);
				printf("\t\t\t\t\t\t\t[ERRO - NAO HA TROPAS SUFICIENTES PARA REMANEJAMENTO!]\n");
				continue;
			}
		}else{
			text_color(4);
			printf("\t\t\t\t\t\t\t[ERRO - OS PAISES SELECIONADOS NAO PODEM FAZER DESLOCAMENTO]\n");
			continue;
		}
		
		system("cls");
		print_mapa();
		printf("\t\t\t\t\t\t\tTurno de %s", player[vez]);
		
		printf("\n\t\t\t\t\t\t\t========================================================\n");
		fflush(stdin);
		printf("\t\t\t\t\t\t\tDeseja remanejar mais? [sim][nao]\n");
		scanf("%s",resp);
		cont_remanejar++;
	}
	print_mapa();	
	printf("\t\t\t\t\t\t\t\tSeu turno acabou, indo para o proximo player!\n");
	system("pause");	
}


//dados de ataque e defesa (apos ter add as tropas aos seus devidos territorios)


void ataque_defesa (){
	
	int qtd_comparacao, qtd_dados_ataque, qtd_dados_defesa; 
	//variaveis q calculam a qtd de dados de ataque X defesa e dps comparam
	int cont_sorteio_dados, posicao_pais_encontrado_ataque, posicao_pais_encontrado_defesa, tropas_realocar;
	//contadores para o for 
	char pais_desejado_atacante, pais_desejado_atacado;  
	//variaveis que receberao os nomes dos paises de ataque e defesa selecionados pelo player
	char resposta_ataque[4] = "SIM"; 
	//resposta do novo ataque
	srand(time(NULL));
	
	printf("\n\t\t\t\t");
	if(strcmp(player[vez],player1) == 0){ //se for a vez do player1
		
		text_color(10); 
	}
	else if(strcmp(player[vez],player2) == 0){
				
		text_color(1);
	}
	printf("%s, ", player[vez]);
	text_color(15);
	printf("chegou a sua vez de atacar! Para pular essa parte digite 0! Senao, prossiga normalmente o jogo!\n\n");
	
	while (strcmp(resposta_ataque, "sim") == 0 || strcmp(resposta_ataque, "SIM") == 0){ // LOOPING DO ATAQUE
		int maior_ataque[3] = {0, 0, 0}, maior_defesa[3] = {0, 0, 0}, dado_ataque[3] = {0, 0, 0}, dado_defesa[3] = {0, 0, 0}; 
		//vetores que armazenarao valores sorteados em ordem crescente
	if(strcmp(player[vez],player1) == 0){ //se for a vez do player1
		
		text_color(10); 
	}
	else if(strcmp(player[vez],player2) == 0){
				
		text_color(1);
	}		
		printf("\t\t\t\t\t\t\t    %s, ",player[vez]);
		text_color(15); 
		printf("Digite a letra do pais com o qual deseja atacar");
		printf("\n\t\t\t\t\t\t\t\t\t   :");
		scanf(" %c", &pais_desejado_atacante); //variavel que recebe o pais de ataque 
		
		
		if(pais_desejado_atacante != '0'){
		
		
			//verificacao se o pais existe ou nao
			if(teste_existencia_pais(pais_desejado_atacante)){ //se o pais existir...
				//parte de verificacao de pertencimento do pais ao jogador :
				if(teste_dono_pais(pais_desejado_atacante)){ //caso o pais pertenca ao player q ataca...
											
					//relacionando com as tropas do pais que ataca correspondente
					if(pais_desejado_atacante >= 65 && pais_desejado_atacante <= 84){ //se a letra for maiuscula
						
						posicao_pais_encontrado_ataque = pais_desejado_atacante - 65;
						
					} else if(pais_desejado_atacante >= 97 && pais_desejado_atacante <= 116){ //se a letra for minuscula
						
						posicao_pais_encontrado_ataque = pais_desejado_atacante - 97;
						
					}
				
					//se pertencer ao jogador:
					//fara a verificacao se o numero de tropas eh suficiente para atacar
					if(tropas_pais[posicao_pais_encontrado_ataque] > 1) { //caso a qtd de tropas seja suficiente...					
										
						//selecionando quem vai ser atacado
						if(strcmp(player[vez],player1) == 0){ //se for a vez do player1
		
							text_color(10); 
						}
						else if(strcmp(player[vez],player2) == 0){
				
							text_color(1);
						}
						printf("\t\t\t\t\t\t\t    %s, ", player[vez]);
						text_color(15);
						printf("digite a letra do pais adversario que voce deseja atacar\n");
						printf("\t\t\t\t\t\t\t\t\t   :");
						scanf(" %c", &pais_desejado_atacado);
						
						//verificando existencia do pais atacado
						if(teste_existencia_pais(pais_desejado_atacado)){ //se existir...	
															
							// verificando pertencimento de do pais a ser atacado (inimigo)
							if (!teste_dono_pais(pais_desejado_atacado) && teste_vizinhanca_pais(pais_desejado_atacante, pais_desejado_atacado)) { //se pertencer ao inimigo e for vizinho
								//caso o pais atacado pertenca ao player q defende...
								
								
								//relacionando com as tropas do pais correspondente
								if(pais_desejado_atacado >= 65 && pais_desejado_atacado <= 84){ //se a letra for maiuscula
							
									posicao_pais_encontrado_defesa = pais_desejado_atacado - 65;
							
								} 
								else if(pais_desejado_atacado >= 97 && pais_desejado_atacado <= 116){ //se a letra for minuscula
							
									posicao_pais_encontrado_defesa = pais_desejado_atacado - 97;
							
								}
								
								
								
								//determinando a quantidade de dados para atauqe
								if(tropas_pais[posicao_pais_encontrado_ataque] == 2) { //para 1 dado
									qtd_dados_ataque = 1;
								}
								else if (tropas_pais[posicao_pais_encontrado_ataque] == 3){ // para 2 dados
						 			qtd_dados_ataque = 2;
								}
								else if (tropas_pais[posicao_pais_encontrado_ataque] > 3){ // para 3 dados
									qtd_dados_ataque = 3;
								}
								
								
								//determinando a quantidade de dados para defesa do inimigo
								if(tropas_pais[posicao_pais_encontrado_defesa] == 1) { //para 1 dado
									qtd_dados_defesa = 1;
								}
								else if (tropas_pais[posicao_pais_encontrado_defesa] == 2){ // para 2 dados
						 			qtd_dados_defesa = 2;
								}
								else if (tropas_pais[posicao_pais_encontrado_defesa] >= 3){ // para 3 dados
									qtd_dados_defesa = 3;
								}			
							
							
								//sorteando dados do ATAQUE
								if(strcmp(player[vez], player1) == 0){
									text_color(10);
									printf("%s\n", player1);
								}
								else if(strcmp(player[vez], player2) == 0){
									text_color(1);
									printf("%s\n", player2);
								}
								for (cont_sorteio_dados=0; cont_sorteio_dados<qtd_dados_ataque; cont_sorteio_dados++){
									
									dado_ataque[cont_sorteio_dados] = (rand() % 6) + 1;
									text_color(15);
									printf("Dado de ataque %d: %d\n", cont_sorteio_dados+1, dado_ataque[cont_sorteio_dados]);
									//quando resolver o printf dos valores em ordem crescente pode tirar esse?
								}
				
				
								//colocando em ORDEM CRESCENTE os numeros sorteados pelos dados de ataque
								if(dado_ataque[0] >= dado_ataque[1] && dado_ataque[0] >= dado_ataque[2] && maior_ataque[2] == 0){
									
									maior_ataque[2] = dado_ataque[0];
									
								}else if(dado_ataque[0] <= dado_ataque[1] && dado_ataque[0] <= dado_ataque[2] && maior_ataque[0] == 0){
									
									maior_ataque[0] = dado_ataque[0];
									
								}else if((dado_ataque[0] >= dado_ataque[1] && dado_ataque[0] <= dado_ataque[2] && maior_ataque[1] == 0) || (dado_ataque[0] >= dado_ataque[2] && dado_ataque[0] <= dado_ataque[1] && maior_ataque[1] == 0)){
									
									maior_ataque[1] = dado_ataque[0];
									
								} if(dado_ataque[1] >= dado_ataque[0] && dado_ataque[1] >= dado_ataque[2] && maior_ataque[2] == 0){
									
									maior_ataque[2] = dado_ataque[1];
									
								}else if(dado_ataque[1] <= dado_ataque[0] && dado_ataque[1] <= dado_ataque[2] && maior_ataque[0] == 0){
									
									maior_ataque[0] = dado_ataque[1];
									
								}else if((dado_ataque[1] >= dado_ataque[0] && dado_ataque[1] <= dado_ataque[2] && maior_ataque[1] == 0) || (dado_ataque[1] >= dado_ataque[2] && dado_ataque[1] <= dado_ataque[0] && maior_ataque[1] == 0)){
									
									maior_ataque[1] = dado_ataque[1];
									
								} if(dado_ataque[2] >= dado_ataque[1] && dado_ataque[2] >= dado_ataque[0] && maior_ataque[2] == 0){
									
									maior_ataque[2] = dado_ataque[2];
									
								}else if(dado_ataque[2] <= dado_ataque[1] && dado_ataque[2] <= dado_ataque[0] && maior_ataque[0] == 0){
									
									maior_ataque[0] = dado_ataque[2];
									
								}else if((dado_ataque[2] >= dado_ataque[1] && dado_ataque[2] <= dado_ataque[0] && maior_ataque[1] == 0) || (dado_ataque[2] >= dado_ataque[0] && dado_ataque[2] <= dado_ataque[1] && maior_ataque[1] == 0)){
									
									maior_ataque[1] = dado_ataque[2];
									
								}
										
								//sorteando dados da DEFESA
								if(strcmp(player[vez], player2) == 0){
									text_color(1);
									printf("%s\n", player2);
								}
								else if(strcmp(player[vez], player1) == 0){
									text_color(10);
									printf("%s\n", player1);
								}
								for (cont_sorteio_dados = 0; cont_sorteio_dados < qtd_dados_defesa; cont_sorteio_dados++){
									
									dado_defesa[cont_sorteio_dados] = (rand() % 6) + 1;
									text_color(15);
									printf("Dado de defesa %d: %d\n", cont_sorteio_dados+1, dado_defesa[cont_sorteio_dados]); 
									//quando resolver o printf dos valores em ordem crescente pode tirar esse?
								}
								
								//colocando em ordem crescente os numeros sorteados pelos dados de defesa
								if(dado_defesa[0] >= dado_defesa[1] && dado_defesa[0] >= dado_defesa[2] && maior_defesa[2] == 0){
									
									maior_defesa[2] = dado_defesa[0];
									
								}else if(dado_defesa[0] <= dado_defesa[1] && dado_defesa[0] <= dado_defesa[2] && maior_defesa[0] == 0){
									
									maior_defesa[0] = dado_defesa[0];
									
								}else if((dado_defesa[0] >= dado_defesa[1] && dado_defesa[0] <= dado_defesa[2] && maior_defesa[1] == 0) || (dado_defesa[0] >= dado_defesa[2] && dado_defesa[0] <= dado_defesa[1] && maior_defesa[1] == 0)){
									
									maior_defesa[1] = dado_defesa[0];
									
								} if(dado_defesa[1] >= dado_defesa[0] && dado_defesa[1] >= dado_defesa[2] && maior_defesa[2] == 0){
									
									maior_defesa[2] = dado_defesa[1];
									
								}else if(dado_defesa[1] <= dado_defesa[0] && dado_defesa[1] <= dado_defesa[2] && maior_defesa[0] == 0){
									
									maior_defesa[0] = dado_defesa[1];
									
								}else if((dado_defesa[1] >= dado_defesa[0] && dado_defesa[1] <= dado_defesa[2] && maior_defesa[1] == 0) || (dado_defesa[1] >= dado_defesa[2] && dado_defesa[1] <= dado_defesa[0] && maior_defesa[1] == 0)){
									
									maior_defesa[1] = dado_defesa[1];
									
								} if(dado_defesa[2] >= dado_defesa[1] && dado_defesa[2] >= dado_defesa[0] && maior_defesa[2] == 0){
									
									maior_defesa[2] = dado_defesa[2];
									
								}else if(dado_defesa[2] <= dado_defesa[1] && dado_defesa[2] <= dado_defesa[0] && maior_defesa[0] == 0){
									
									maior_defesa[0] = dado_defesa[2];
									
								}else if((dado_defesa[2] >= dado_defesa[1] && dado_defesa[2] <= dado_defesa[0] && maior_defesa[1] == 0) || (dado_defesa[2] >= dado_defesa[0] && dado_defesa[2] <= dado_defesa[1] && maior_defesa[1] == 0)){
									
									maior_defesa[1] = dado_defesa[2];
									
								}						
				
								//comparando e imprimindo valores de ataque e defesa (quem ganha/perde territorio)
							
								if(qtd_dados_ataque>=qtd_dados_defesa){
									qtd_comparacao = qtd_dados_defesa;
								}
								else{
									qtd_comparacao = qtd_dados_ataque;
								}					
								
								if(qtd_comparacao == 3){ //transformando variavel para o for da impressao dos valores sorteados em ordem crescente
									qtd_comparacao = 0;
								}
								else if(qtd_comparacao == 2){
									qtd_comparacao = 1;
								}
								else{
									qtd_comparacao = 2;
								}
								for(cont_sorteio_dados=2; cont_sorteio_dados >= qtd_comparacao; cont_sorteio_dados--){
									//imprimindo nome dos jogadores com os numeros sorteados em ordem crescente
									if(strcmp(player[vez], player1) == 0){
										printf("\n\n\t\t\t\t\t\t\t\t\t");
										text_color(10);
										printf("%s\t", player1);
										text_color(15);
										printf("x");
										text_color(1);
										printf("\t%s\n", player2);
									}
									else if(strcmp(player[vez], player2) == 0){
										printf("\n\n\t\t\t\t\t\t\t\t\t");
										text_color(10);
										printf("%s\t", player2);
										text_color(15);
										printf("x");
										text_color(1);
										printf("\t%s\n", player1);
									}
									printf("\n\n\t\t\t\t\t\t\t\t\t");
									text_color(15);
									printf("%d\t",maior_ataque[cont_sorteio_dados]);
									text_color(15);
									printf("x");
									text_color(15);
									printf("\t%d\n" , maior_defesa[cont_sorteio_dados]);
									
									//verificando quem ganhou
									if(maior_ataque[cont_sorteio_dados] <= maior_defesa[cont_sorteio_dados]){ //ganho defesa
										tropas_pais[posicao_pais_encontrado_ataque] = tropas_pais[posicao_pais_encontrado_ataque] - 1;
									}
									else{ //ganho ataque
										tropas_pais[posicao_pais_encontrado_defesa] = tropas_pais[posicao_pais_encontrado_defesa] - 1;
										if(tropas_pais[posicao_pais_encontrado_defesa] == 0){ //se o a defesa nao tiver mais tropas...
											if(strcmp(player[vez], player1) == 0){ //se for a vez do player 1
												pais[posicao_pais_encontrado_defesa][0] = '1'; //player1 conquista o territorio do player2
											}
											else if(strcmp(player[vez], player2) == 0){ //se for player 2 
												pais[posicao_pais_encontrado_defesa][0] = '2'; //player2 conquista o territorio do player1
											}								
										} contar_paises();
									}		
									text_color(15);							
									system("pause");
									//atualizando o mapa...
									system("cls"); //limpando a tela
									print_mapa(); //reimprime o mapa
									
									while(tropas_pais[posicao_pais_encontrado_defesa] == 0){
										
										if(tropas_pais[posicao_pais_encontrado_defesa] == 0){ //se o a defesa nao tiver mais tropas...
											if(strcmp(player[vez],player1) == 0){ //se for a vez do player1
		
												text_color(10); 
											}
											else if(strcmp(player[vez],player2) == 0){
				
												text_color(1);
											}
											printf("\t\t\t\t\t\t%s, ", player[vez]);
											text_color(15);
											printf("quantas tropas voce deseja colocar no territorio conquistado?\n");
											printf("\t\t\t\t\t\t\t\t\t   :");
											scanf("%d", &tropas_realocar);
											
											if(tropas_realocar < tropas_pais[posicao_pais_encontrado_ataque] && tropas_realocar <= qtd_dados_ataque){
												
												tropas_pais[posicao_pais_encontrado_defesa] += tropas_realocar;
												tropas_pais[posicao_pais_encontrado_ataque] -= tropas_realocar;
												system("cls"); //limpando a tela
												print_mapa(); //reimprime o mapa
												
											}else{
												text_color(4);
												printf("\t\t\t\t\t\t [ERRO] O NUMERO DE TROPAS EXCEDE A QUANTIDADE DE TROPAS DE SEU PAIS. Digite novamente\n");
												
											}
																
										}
									}
															
								} //fim for print dos dados em ordem crescente								
							
							}//FIM IF PERTENCIMENTO AO INIMIGO
							
							else{ //caso o pais nao pertenca ao inimigo
								text_color(4);
								printf("\t\t\t\t\t\t [ERRO] NAO EH POSSIVEL SELECIONAR ESSE PAIS! Por favor, tente outro.\n");
								text_color(15);
							}
							
						}//FIM IF EXISTENCIA PAIS ATACADO 
						
						else{//se o pais atacado nao existir
							text_color(4);
							printf("\t\t\t\t\t\t [ERRO] ESSE PAIS NAO EXISTE! Por favor, tente outro!\n");
							text_color(15);
						}
						
					} //FIM IF QTD DE TROPAS > 1
				
					else if(tropas_pais[posicao_pais_encontrado_ataque] == 1){//caso a quantidade de tropas seja insuficiente
						text_color(4);
						printf("\n\t\t\t\t\t\t[ERRO] NUMERO DE TROPAS INSUFICIENTE PARA ATAQUE! Por favor, tente outro.\n");
						text_color(15);
					}
				
				} //FIM IF PERTENCIMENTO  DO PAIS ATACANTE
				
				
				else //if(teste_dono_pais(pais_desejado_atacante) || teste_existencia_pais(pais_desejado_atacante)){ //caso o pais ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â± pertenÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§a ao jogador q estÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ jogando
				{	
					text_color(4);
					printf("\n\t\t\t\t\t\t[ERRO] ESSE PAIS NAO TE PERTENCE! Por favor, tente outro.\n");
					text_color(15);
				}	
				
			}//FIM IF EXISTENCIA PAIS ATACANTE
				
			else{ //se o pais atacante nao existir	
				text_color(4);
				printf("\n\t\t\t\t\t\t [ERRO] ESSE PAIS NAO EXISTE! Por favor tente outro!\n");
			}

		}//fim resposta != de 0
		
		//perguntando se deseja novo ataque
		text_color(15);
		printf("\n\t\t\t\t\t\t\t\t Deseja atacar novamente? [SIM][NAO]\n");
		printf("\t\t\t\t\t\t\t\t\t     :");
		scanf("%s", resposta_ataque);
				
	} //fim do while do ataque
		
}//fim da funcao (void)	
