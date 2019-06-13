void add_tropas(){ //funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o para adicionar as tropas no inicio de cada rodada
	
	char posicao_pais; //vai receber a letra do pais 
	
	unsigned int num_pais, cont_num_pais, tropas_player[3], num_tropas_add; 

	contar_paises();

	if(qntd_paises_player1 <= 6){ //se o player 1 tiver 6 paises ou menos sob seu controle, irÃƒÆ’Ã‚Â¡ receber 3 tropas adicionais de qualquer forma
		
		tropas_player[0] = 3;
			
	} else{ //senao, a quantidade de tropas diposniveis para o player 1 sera igual a quantidade de paises sob seu controle dividido por dois
			
		tropas_player[0] = qntd_paises_player1 / 2; //armazena na variavel tropas_player[0] a quantidade de tropas que o player 1 tem disponivel para adicionar em seus paises
			
	} if(qntd_paises_player2 <= 6){ //se o player 2 tiver 6 paises ou menos sob seu controle, irÃƒÆ’Ã‚Â¡ receber 3 tropas adicionais de qualquer forma

		tropas_player[1] = 3;
			
	} else { //senao, a quantidade de tropas diposniveis para o player 2 sera igual a quantidade de paises sob seu controle dividido por dois
			
		tropas_player[1] = qntd_paises_player2 / 2; //armazena na variavel tropas_player[1] a quantidade de tropas que o player 2 tem disponivel para adicionar em seus paises
			
	}	
	
	while(tropas_player[vez] != 0){ //vai repetir o processo de adicionar as tropas atÃƒÆ’Ã‚Â© a quantidade de tropas disponiveis do player acabar
	
		printf("\n%s, voce possui %d tropas adicionais.\n", player[vez], tropas_player[vez]); //diz a quantidade e quem vai comeÃƒÆ’Ã‚Â§ar a adicionar as tropas
		
		printf("\t\t\t\t\t\t\tDigite a letra do pais que deseja adicionar suas tropas:\n");
		
		scanf("%s", &posicao_pais); //lÃƒÆ’Ã‚Âª a letra do pais que o usuario quer adicionar as tropas
		
		fflush(stdin);
		
		if(teste_dono_pais(posicao_pais)){ //prossegue com o cÃƒÆ’Ã‚Â³digo apenas se o paÃƒÆ’Ã‚Â­s digitado pelo usuÃƒÆ’Ã‚Â¡rio pertencer a ele, senÃƒÆ’Ã‚Â£o pede pra digitar novamente
			
			if(posicao_pais >= 65 && posicao_pais <= 84){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais = posicao_pais - 65;
				
			} else if(posicao_pais >= 97 && posicao_pais <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃƒÆ’Ã‚Â¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais = posicao_pais - 97;
				
			}
			
			if(teste_existencia_pais(posicao_pais)){ //se a letra digitada estiver entre A e T maiusculo ou minusculo, o processo continua, senÃƒÆ’Ã‚Â£o pede pra digitar novamente
				if(bonus_tropas_pais()){
					if(player[vez] == player1){ //se for a vez do player1
						tropas_player[vez] += qntd_tropas_bonus_player1; 
					}
					else{
						tropas_player[vez] += qntd_tropas_bonus_player2;
					}
				}
					
				printf("\n%s, voce possui %d tropas adicionais.\nDigite o numero de tropas que voce deseja adicionar nesse pais:\n", player[vez], tropas_player[vez]);
			
				scanf("%d", &num_tropas_add); // LÃƒÆ’Ã‚Âª o nÃƒÆ’Ã‚Âºmero de tropas que o player quer adicionar no pais
				
				if(num_tropas_add <= tropas_player[vez]){ //sÃƒÆ’Ã‚Â³ prossegue com o cÃƒÆ’Ã‚Â³digo se o nÃƒÆ’Ã‚Âºmero de tropas que o player quer adicinonar for menor ou igual que o nÃƒÆ’Ã‚Âºmero de tropas disponÃƒÆ’Ã‚Â­veis que ele possui, senÃƒÆ’Ã‚Â£o pede pra digitar novamente
								
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
					
					printf("Voce apenas possui %d tropas. Digite novamente.\n", tropas_player[vez]);
					
				}
			
		} else{
				
				printf("Pais nao registrado. Digite novamente.\n"); //printa na tela essa mensagem caso a letra digitada nÃƒÆ’Ã‚Â£o seja referente a nenhum paÃƒÆ’Ã‚Â­s
				
			}
			
		} else{
			
			printf("O pais digitado nao te pertence. Digite novamente.\n"); //printa na tela essa mensagem caso o paÃƒÆ’Ã‚Â­s nÃƒÆ’Ã‚Â£o pertenÃƒÆ’Ã‚Â§a ao player da vez
		
		} 
		
	}
	
}
