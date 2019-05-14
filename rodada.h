//Essa biblioteca contém as funções principais de cada rodada do jogo

void add_tropas(){ //funÃ§Ã£o para adicionar as tropas no inicio de cada rodada
	
	char posicao_pais; //vai receber a letra do pais 
	
	unsigned int num_pais, cont_num_pais, tropas_player[3], num_tropas_add; 

	qntd_paises_player1 = 0; //zerando as variaveis para evitar erros
	
	qntd_paises_player2 = 0;

	for(cont_num_pais = 0; cont_num_pais < 21; cont_num_pais++){ //percorre a matriz pais[21][4] em busca dos numeros 1 e 2 que definirÃƒÂ£o a que player cada pais pertence
		
		if(pais[cont_num_pais][0] == '1'){ //se o pais tiver o numero 1, a variavel qntd_paises_player1 vai aumentar em 1
			
			qntd_paises_player1++;
			
		} else if(pais[cont_num_pais][0] == '2'){ //se o pais tiver o numero 2, a variavel qntd_paises_player2 vai aumentar em 1
			
			qntd_paises_player2++;
			
		}
		
	} if(qntd_paises_player1 <= 6){ //se o player 1 tiver 6 paises ou menos sob seu controle, irÃ¡ receber 3 tropas adicionais de qualquer forma
		
		tropas_player[0] = 3;
			
	} else{ //senao, a quantidade de tropas diposniveis para o player 1 sera igual a quantidade de paises sob seu controle dividido por dois
			
		tropas_player[0] = qntd_paises_player1 / 2; //armazena na variavel tropas_player[0] a quantidade de tropas que o player 1 tem disponivel para adicionar em seus paises
			
	} if(qntd_paises_player2 <= 6){ //se o player 2 tiver 6 paises ou menos sob seu controle, irÃ¡ receber 3 tropas adicionais de qualquer forma

		tropas_player[1] = 3;
			
	} else { //senao, a quantidade de tropas diposniveis para o player 2 sera igual a quantidade de paises sob seu controle dividido por dois
			
		tropas_player[1] = qntd_paises_player2 / 2; //armazena na variavel tropas_player[1] a quantidade de tropas que o player 2 tem disponivel para adicionar em seus paises
			
	}	
	
	while(tropas_player[vez] != 0){ //vai repetir o processo de adicionar as tropas atÃ© a quantidade de tropas disponiveis do player acabar
	
		printf("%s, voce possui %d tropas adicionais.\nDigite a letra do pais que deseja adicionar suas tropas:\n", player[vez], tropas_player[vez]); //diz a quantidade e quem vai comeÃ§ar a adicionar as tropas
		
		scanf("%s", &posicao_pais); //lÃª a letra do pais que o usuario quer adicionar as tropas
		
		fflush(stdin);
		
		if(teste_dono_pais(posicao_pais)){ //prossegue com o cÃ³digo apenas se o paÃ­s digitado pelo usuÃ¡rio pertencer a ele, senÃ£o pede pra digitar novamente
			
			if(posicao_pais >= 65 && posicao_pais <= 84){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃ¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais = posicao_pais - 65;
				
			} else if(posicao_pais >= 97 && posicao_pais <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que serÃ¡ usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais = posicao_pais - 97;
				
			}
			
			if(teste_existencia_pais(posicao_pais)){ //se a letra digitada estiver entre A e T maiusculo ou minusculo, o processo continua, senÃ£o pede pra digitar novamente
		
				printf("%s, voce possui %d tropas adicionais.\nDigite o numero de tropas que voce deseja adicionar nesse pais:\n", player[vez], tropas_player[vez]);
			
				scanf("%d", &num_tropas_add); // LÃª o nÃºmero de tropas que o player quer adicionar no pais
				
				if(num_tropas_add <= tropas_player[vez]){ //sÃ³ prossegue com o cÃ³digo se o nÃºmero de tropas que o player quer adicinonar for menor ou igual que o nÃºmero de tropas disponÃ­veis que ele possui, senÃ£o pede pra digitar novamente
					
					tropas_pais[num_pais] = tropas_pais[num_pais] + num_tropas_add; //adiciona a quantidade desejada de tropas no pais de interesse
					
					tropas_player[vez] = tropas_player[vez] - num_tropas_add; //diminui a quantidade de tropas disponiveis
					
					system ("cls"); //limpa a tela
			
					print_mapa(); //imprime o mapa com as novas tropas
					
				} else{
					
					printf("Voce apenas possui %d tropas. Digite novamente.\n", tropas_player[vez]);
					
				}
			
		} else{
				
				printf("Pais nao registrado. Digite novamente.\n"); //printa na tela essa mensagem caso a letra digitada nÃ£o seja referente a nenhum paÃ­s
				
			}
			
		} else{
			
			printf("O pais digitado nao te pertence. Digite novamente.\n"); //printa na tela essa mensagem caso o paÃ­s nÃ£o pertenÃ§a ao player da vez
		
		} 
		
	}
	
}
