//dados de ataque e defesa (apos ter add as tropas aos seus devidos territorios
void ataque (int qtd_dados_ataque, qtd_dados_defesa){
	int cont_pais, cont_sorteio_dados, dado_ataque[qtd_dados_ataque] dado_defesa[qtd_dados_defesa]; 
	int maior_ataque[3] = {0, 0, 0}, maior_defesa[3] = {0, 0, 0};
	char pais_desejado_atacante[2], pais_desejado_atacado[2];
	printf("%s, chegou a sua vez de atacar! Para pular essa parte digite 0! Senao, prossiga normalmente o jogo!\n");
	while (pais_desejado_atacante != '0' || pais_desejado_atacado != '0'){ 
					// LOOPING DO ATAQUE
	
		printf("%s, Digite a letra do paÃ­s com o qual deseja atacar: ", player[vez]);
		scanf("%s", pais_desejado_atacante);
		fflsuh(stdin);		
		
		//---------------------parte de verificacao de pertencimento do pais ao jogador :
		if (teste_dono_pais (pais_desejado_atacante)){ //caso o pais pertenca ao player q ataca...
			printf("Nao eh possivel selecionar esse pais. Por favor, tente outro.\n");
						
			//pesquisa o pais correspondente 
			if(pais_desejado_atacante >= 97 && pais_desejado_atacante <= 116){
				pais_atacante = pais_desejado_atacante - 32; //transformando para caracter maiusculo
			}
			for(cont_pais = 0; cont_pais < 21; cont_pais++){ //relacionando com a posicao do pais e as tropas
				if(strcmp(pais[cont_pais][1], pais_desejado_atacante) == 0) {
					posicao_pais_encontrado_ataque = cont_pais;
				}
			}
		
			//se pertencer ao jogador
			if (tropas_pais[posicao_pais_encontrado_ataque] != 1) { //caso a qtd de tropas seja suficiente...
				//determinando a quantidade de dados maximo do jogador
			if(tropas_pais[posicao_pais_encontrado_ataque] == 2) qtd_dados_ataque = 1;
			else if (tropas_pais[posicao_pais_encontrado_ataque] == 3) qtd_dados_ataque = 2;
			else if (tropas_pais[posicao_pais_encontrado_ataque] >=4) qtd_dados_ataque = 3;
				
				//selecionando quem vai ser atacado
			printf("%s, digite a letra do pais adversario que voce deseja atacar: ", player[vez]);
			scanf("%s", pais_desejado_atacado);
			fflush(stdin);
			// verificando pertencimento de do pais a ser atacado (inimigo)
			if (teste_dono_pais (pais_desejado_atacado)) { //se pertencer ao inimigo
				//caso o pais Ã± pertenca ao player q defende...
				//pesquisa o pais correspondente 
				if(pais_atacado >= 97 && pais_atacado <= 116){
					pais_atacado = pais_atacado - 32; //transformando para caracter maiusculo
				}
				for(cont_pais = 0; cont_pais < 21; cont_pais++){
					if(strcmp(pais[cont_pais][1], pais_atacado) == 0) {
						posicao_pais_encontrado_defesa = cont_pais;
					}
				}
				// colocar funcao de teste de vizinhança
				
				//determinando a quantidade de dados para defesa do inimigo
				if(tropas_pais[posicao_pais_encontrado_defesa] == 1) {
					qtd_dados_defesa = 1;
				}
				else if (tropas_pais[posicao_pais_encontrado_defesa] == 2){
		 			qtd_dados_defesa = 2;
				}
				else if (tropas_pais[posicao_pais_encontrado_defesa] >= 3){
					qtd_dados_defesa = 3;
				}			
				
				//ATAQUE
				for (cont_sorteio_dados=0; cont_sorteio_dados<qtd_dados_ataque; cont_sorteio_dados++){
				srand(time(NULL));
				dado_ataque[cont_sorteio_dados] = (rand() % 5) + 1;
				}
	
				//colocando em ORDEM CRESCENTE os numeros sorteados pelos dados de ataque
				if (qtd_dados_ataque == 3){ //para 3 dados de ataque
					if (maior_ataque[0] < maior_ataque[1]) { //a<b
						if(maior_ataque[1] > maior_ataque[2]){ //a<b e c<b
							if (maior_ataque[0] > maior_ataque[2]){ //c<a<b
								menor = maior_ataque[2];
								maior_ataque[2] = maior_ataque[1];
								aux = maior_ataque[0];
								maior_ataque[0] = menor;
								maior_ataque[1] = aux;			 
							}
							if(maior_atque[0] < maior_ataque[2]){ //a<c<b
								aux = maior_ataque[1];
								maior_ataque[1] = maior_ataque[2];
								maior_ataque[2] = aux;
							}
						}
					}
					if(maior_ataque[1] < maior_ataque[0]){ //b<a
						if(maior_ataque[1] < maior_ataque[2] ) {//b<c
							if (maior_ataque[2] < maior_ataque[0]){ //b<c<a
								menor = maior_ataque[1];
								maior_ataque[1] = maior_ataque[2];
								aux = maior_ataque[0];
								maior_ataque[0] = menor;
								maior_ataque[2] = aux;
							}
							if (maior_ataque[2] > maior_ataque[0]){ //b<a<c
								menor = maior_ataque[1];
								maior_ataque[1] = maior_ataque[0];
								maior_ataque[0] = menor;
							}
						}
					}
	
					if (qtd_dados_ataque == 2){
						if(maior_ataque[0] > maior_ataque[1]){ // a>b
							menor = maior_ataque[1];
							aux = maior_ataque[0];
							maior_ataque[0] = menor;
							maior_ataque[1] = aux;
						}
					}
				}			
			
				//DEFESA
				for (cont_sorteio_dados = 0; cont_sorteio_dados < qtd_dados_defesa; cont_sorteio_dados++){
					srand(time(NULL));
					dado_defesa[i] = (rand() % 5) + 1;
				}
		
				//colocando em ordem crescente os numeros sorteados pelos dados de defesa
				if (qtd_dados_defesa == 3){ //para 3 dados de defesa
					if (maior_defesa[0] < maior_defesa[1]) { //a<b
						if(maior_defesa[1] > maior_defesa[2]){ //a<b e c<b
							if (maior_ataque[0] > maior_defesa[2]){ //c<a<b
								menor = maior_defesa[2];
								maior_defesa[2] = maior_defesa[1];
								aux = maior_defesa[0];
								maior_defesa[0] = menor;
								maior_defesa[1] = aux;			 
							}
							if(maior_defesa[0] < maior_defesa[2]){ //a<c<b
								aux = maior_defesa[1];
								maior_defesa[1] = maior_defesa[2];
								maior_defesa[2] = aux;
							}
						}
					}
					if(maior_defesa[1] < maior_defesa[0]){ //b<a
						if(maior_defesa[1] < maior_defesa[2] ) {//b<c
							if (maior_defesa[2] < maior_defesa[0]){ //b<c<a
								menor = maior_defesa[1];
								maior_defesa[1] = maior_defesa[2];
								aux = maior_defesa[0];
								maior_defesa[0] = menor;
								maior_defesa[2] = aux;
							}
							if (maior_defesa[2] > maior_defesa[0]){ //b<a<c
								menor = maior_defesa[1];
								maior_defesa[1] = maior_defesa[0];
								maior_defesa[0] = menor;
							}
						}
					}
				}	
	
				if (qtd_dados_defesa == 2){
					if(maior_defesa[0] > maior_defesa[1]){ // a>b
						menor = maior_defesa[1];
						aux = maior_defesa[0];
						maior_defesa[0] = menor;
						maior_defesa[1] = aux;
					}
				}
	
				//comparando valores de ataque e defesa (quem ganha/perde territorio)
				if(maior_ataque[2]<= maior_defesa[2]){ //perda ataque
					tropas_pais[posicao_pais_encontrado_ataque] = tropas_pais[posicao_pais_encontrado_ataque] - 1;
				}
				else{ //ganho ataque
					tropas_pais[posicao_pais_encontrado_defesa] = tropas_pais[posicao_pais_encontrado_defesa] - 1;
					if(tropas_pais[posicao_pais_encontrado_defesa] == 0){
						if(strcmp(player[vez], player1) == 0){ //se for a vez do player 1
							pais[posicao_pais_encontrado_defesa][0] = '1'; //player1 conquista o território do player2
						}
						else if(strcmp(player[vez], player2) == 0){ //se for player 2 
							pais[posicao_pais_encontrado_defesa][0] = '2'; //player2 conquista o territorio do player1
						}
					}
					
					if(maior_ataque[1] <= maior_defesa[1]){ //perda ataque
						tropas_pais[posicao_pais_encontrado_ataque] = tropas_pais[posicao_pais_encontrado_ataque] - 1;
					}
					else{ //ganho ataque
						tropas_pais[posicao_pais_encontrado_defesa] = tropas_pais[posicao_pais_encontrado_defesa] - 1;
						if(tropas_pais[posicao_pais_encontrado_defesa] == 0){
							if(strcmp(player[vez], player1) == 0){ //se for a vez do player 1
								pais[posicao_pais_encontrado_defesa][0] = '1'; //player1 conquista o território do player2
							}
							else if(strcmp(player[vez], player2) == 0){ //se for player 2 
							pais[posicao_pais_encontrado_defesa][0] = '2'; //player2 conquista o territorio do player1
							}
						}
					}
					
					if(maior_ataque[0] <=maior_ataque[0]){ //perda ataque
						tropas_pais[posicao_pais_encontrado_ataque] = tropas_pais[posicao_pais_encontrado_ataque] - 1;
					}
					else{ //ganho ataque
						tropas_pais[posicao_pais_encontrado_defesa] = tropas_pais[posicao_pais_encontrado_defesa] - 1;
						if(tropas_pais[posicao_pais_encontrado_defesa] == 0){
							if(strcmp(player[vez], player1) == 0){ //se for a vez do player 1
								pais[posicao_pais_encontrado_defesa][0] = '1'; //player1 conquista o território do player2
							}
							else if(strcmp(player[vez], player2) == 0){ //se for player 2 
								pais[posicao_pais_encontrado_defesa][0] = '2'; //player2 conquista o territorio do player1
							}
						}
					}
				}
						
			}//FIM IF PERTENCIMENTO DO PAIS ATACADO
		
		} //FIM IF QTD DE TROPAS >1
		
		else{//caso a quantidade de tropas seja insuficiente
			printf("Nao eh possivel selecionar esse pais. Por favor, tente outro.\n");
		}
		
	} //FIM IF PERTENCIMENTO  DO PAIS ATACANTE
	else{ //caso o pais ñ pertença ao jogador q está jogando
		printf("Nao eh possivel selecionar esse pais. Por favor, tente outro.\n");
	}
	
	//chamar funcao de remanejamento de tropas
				
	} //fim while 0
}//fim da funcao (void)
	
	
	
