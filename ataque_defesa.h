//dados de ataque e defesa (apos ter add as tropas aos seus devidos territorios)
void ataque_defesa (){
	int qtd_dados_ataque;
	int qtd_dados_defesa;
	int cont_pais, cont_sorteio_dados, posicao_pais_encontrado_ataque, posicao_pais_encontrado_defesa, dado_ataque[3], dado_defesa[3]; //contadores para o for e dados de defesa e ataque
	int maior_ataque[3] = {0, 0, 0}, maior_defesa[3] = {0, 0, 0}; //vetores que armazenarao valores sorteados em ordem crescente
	char pais_desejado_atacante, pais_desejado_atacado; //variaveis que receberao os nomes dos paises de ataque e defesa selecionados pelo player
	printf("%s, chegou a sua vez de atacar! Para pular essa parte digite 0! Senao, prossiga normalmente o jogo!\n");
	while (pais_desejado_atacante != '0' || pais_desejado_atacado != '0'){ // LOOPING DO ATAQUE
		
		printf("%s, Digite a letra do pais com o qual deseja atacar: ", player[vez]);
		scanf("%s", pais_desejado_atacante); //variavel que recebe o pais de ataque
		fflush(stdin);		
		
		//parte de verificacao de pertencimento do pais ao jogador :
		if (teste_dono_pais (pais_desejado_atacante)){ //caso o pais pertenca ao player q ataca...
									
			//pesquisa do país correspondente 
			if(pais_desejado_atacante >= 97 && pais_desejado_atacante <= 116){ //entre a e t (minúsculo mesmo)
				pais_desejado_atacante = pais_desejado_atacante - 32; //transformando para caracter maiusculo
			}
		
			for(cont_pais = 0; cont_pais < 21; cont_pais++){ //relacionando com a posicao do pais e as tropas
				if(pais[cont_pais][1] == pais_desejado_atacante) {
					posicao_pais_encontrado_ataque = cont_pais;
				}
			}
		
			//se pertencer ao jogador:
			//fará a verificacao se o numero de tropas eh suficiente para atacar
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
					//caso o pais atacado pertenca ao player q defende...
					//pesquisa o pais correspondente na matriz
					if(pais_desejado_atacado >= 97 && pais_desejado_atacado <= 116){
						pais_desejado_atacado = pais_desejado_atacado - 32; //transformando para caracter maiusculo
					}
					for(cont_pais = 0; cont_pais < 21; cont_pais++){
						if(pais[cont_pais][1] == pais_desejado_atacado) {
							posicao_pais_encontrado_defesa = cont_pais;
						}
					}
					// colocar funcao de teste de vizinhanÃ§a
				
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
					for (cont_sorteio_dados=0; cont_sorteio_dados<qtd_dados_ataque; cont_sorteio_dados++){
						srand(time(NULL));
						dado_ataque[cont_sorteio_dados] = (rand() % 5) + 1;
						printf("%d ", dado_ataque[cont_sorteio_dados]);
					}
	
					//colocando em ORDEM CRESCENTE os numeros sorteados pelos dados de ataque
					if (qtd_dados_ataque == 3){ //para 3 dados de ataque
						if (dado_ataque[0] < dado_ataque[1]) { //a<b 0<1
							if(dado_ataque[1] > dado_ataque[2]){ //a<b e c<b 0<1 e 2<1
								if (dado_ataque[0] > dado_ataque[2]){ //c<a<b 2<0<1
									maior_ataque[0] = dado_ataque[2];
									maior_ataque[1] = dado_ataque[0];			 
								}
								if(dado_ataque[0] < dado_ataque[2]){ //a<c<b 0<2<1
									maior_ataque[0] = dado_ataque[0];
									maior_ataque[1] = dado_ataque[2];
								}
								maior_ataque[2] = dado_ataque[1];
							}
						}
						else if(maior_ataque[1] < maior_ataque[0]){ //b<a 1<0
							if(maior_ataque[1] < maior_ataque[2] ) {//b<c 1<2
								if (maior_ataque[2] < maior_ataque[0]){ //b<c<a 1<2<0
									maior_ataque[1] = dado_ataque[2];
									maior_ataque[2] = dado_ataque[0];
								}
								else if (maior_ataque[2] > maior_ataque[0]){ //b<a<c 1<0<2
									maior_ataque[1] = dado_ataque[0];
									maior_ataque[2] = dado_ataque[2];
								}
								maior_ataque[0] = dado_ataque[1];
							}
							else if(dado_ataque[1] > dado_ataque[2]){ // c<b 2<1 ---> c<b<a 2<1<0
								maior_ataque[0] = dado_ataque[2];
								maior_ataque[1] = dado_ataque[1];
								maior_ataque[2] = dado_ataque[0];
							}
						}
						
						else{ //a<b<c 0<1<2
							maior_ataque[0] = dado_ataque[0];
							maior_ataque[1] = dado_ataque[1];
							maior_ataque[2] = dado_ataque[2];
						}
	
						if (qtd_dados_ataque == 2){ //para 2 dados de ataque
							if(dado_ataque[0] > dado_ataque[1]){ // b<a 1<0
								maior_ataque[1] = dado_ataque[1];
								maior_ataque[2] = dado_ataque[0];
							}
							else{ // a<b 0<1
								maior_ataque[1] = dado_ataque[0];
								maior_ataque[2] = dado_ataque[1];
							}
						}
						
						if(qtd_dados_ataque == 1){ //para apenas 1 dado de ataque
							maior_ataque[2]= dado_ataque[0];
						}
					}			
			
					//sorteando dados da DEFESA
					for (cont_sorteio_dados = 0; cont_sorteio_dados < qtd_dados_defesa; cont_sorteio_dados++){
						srand(time(NULL));
						dado_defesa[cont_sorteio_dados] = (rand() % 5) + 1;
						printf("%d ", dado_defesa[cont_sorteio_dados]);
					}
		
					//colocando em ordem crescente os numeros sorteados pelos dados de defesa
						if (qtd_dados_defesa == 3){ //para 3 dados de defesa
						if (dado_defesa[0] < dado_defesa[1]) { //a<b 0<1
							if(dado_ataque[1] > dado_ataque[2]){ //a<b e c<b 0<1 e 2<1
								if (dado_defesa[0] > dado_defesa[2]){ //c<a<b 2<0<1
									maior_defesa[0] = dado_defesa[2];
									maior_defesa[1] = dado_defesa[0];			 
								}
								if(dado_defesa[0] < dado_defesa[2]){ //a<c<b 0<2<1
									maior_defesa[0] = dado_defesa[0];
									maior_defesa[1] = dado_defesa[2];
								}
								maior_defesa[2] = dado_defesa[1];
							}
						}
						else if(maior_ataque[1] < maior_ataque[0]){ //b<a 1<0
							if(maior_defesa[1] < maior_defesa[2] ) {//b<c 1<2
								if (maior_defesa[2] < maior_defesa[0]){ //b<c<a 1<2<0
									maior_defesa[1] = dado_defesa[2];
									maior_defesa[2] = dado_defesa[0];
								}
								else if (maior_ataque[2] > maior_defesa[0]){ //b<a<c 1<0<2
									maior_defesa[1] = dado_defesa[0];
									maior_defesa[2] = dado_defesa[2];
								}
								maior_defesa[0] = dado_defesa[1];
							}
							else if(dado_defesa[1] > dado_defesa[2]){ // c<b 2<1 ---> c<b<a 2<1<0
								maior_defesa[0] = dado_defesa[2];
								maior_defesa[1] = dado_defesa[1];
								maior_defesa[2] = dado_defesa[0];
							}
						}
						
						else{ //a<b<c 0<1<2
							maior_defesa[0] = dado_defesa[0];
							maior_defesa[1] = dado_defesa[1];
							maior_defesa[2] = dado_defesa[2];
						}
	
						if (qtd_dados_defesa == 2){ //para 2 dados de defesa
							if(dado_defesa[0] > dado_defesa[1]){ // b<a 1<0
								maior_defesa[1] = dado_defesa[1];
								maior_defesa[2] = dado_defesa[0];
							}
							else{ // a<b 0<1
								maior_defesa[1] = dado_defesa[0];
								maior_defesa[2] = dado_defesa[1];
							}
						}
						
						if(qtd_dados_defesa == 1){ //para apenas 1 dado de defesa
							maior_defesa[2]= dado_defesa[0];
						}
					}			
					
	
					//comparando valores de ataque e defesa (quem ganha/perde territorio)
					if(maior_ataque[2]<= maior_defesa[2]){ //perda ataque
						tropas_pais[posicao_pais_encontrado_ataque] = tropas_pais[posicao_pais_encontrado_ataque] - 1; //redução de tropas
					}
					
					else{ //ganho ataque
						tropas_pais[posicao_pais_encontrado_defesa] = tropas_pais[posicao_pais_encontrado_defesa] - 1; //redução de tropas
						if(tropas_pais[posicao_pais_encontrado_defesa] == 0){ //se o a defesa ñ tiver mais tropas...
							if(strcmp(player[vez], player1) == 0){ //se for a vez do player 1
								pais[posicao_pais_encontrado_defesa][0] = '1'; //player1 conquista o territorio do player2
							}
							else if(strcmp(player[vez], player2) == 0){ //se for player 2 
								pais[posicao_pais_encontrado_defesa][0] = '2'; //player2 conquista o territorio do player1
							}
							//atualizando o mapa...
							system("cls"); //limpando a tela
							print_mapa(); //reimprime o mapa
						}
					}
					
					
					if(maior_ataque[1]<= maior_defesa[1] && (maior_ataque[1] != 0 || maior_defesa[1] != 0)){ //perda ataque
					// o "!= 0" é para que ñ compare com as posicoes do vetor q ñ foram preenchidas, caso a defesa ou ataque ñ possua 3 dados
						tropas_pais[posicao_pais_encontrado_ataque] = tropas_pais[posicao_pais_encontrado_ataque] - 1;
					}
		
					else{ //ganho ataque
						tropas_pais[posicao_pais_encontrado_defesa] = tropas_pais[posicao_pais_encontrado_defesa] - 1;
						if(tropas_pais[posicao_pais_encontrado_defesa] == 0){ //se o a defesa ñ tiver mais tropas...
							if(strcmp(player[vez], player1) == 0){ //se for a vez do player 1
								pais[posicao_pais_encontrado_defesa][0] = '1'; //player1 conquista o territÃ³rio do player2
							}
							else if(strcmp(player[vez], player2) == 0){ //se for player 2 
								pais[posicao_pais_encontrado_defesa][0] = '2'; //player2 conquista o territorio do player1
							}
							//atualizando o mapa...
							system("cls"); //limpando a tela
							print_mapa(); //reimprime o mapa
						}
					}
		
					
					if(maior_ataque[0]<= maior_defesa[0] && (maior_ataque[0] != 0 || maior_defesa[0] != 0)){ //perda ataque
					// o "!= 0" é para que ñ compare com as posicoes do vetor q ñ foram preenchidas, caso a defesa ou ataque ñ possua 3 dados
						tropas_pais[posicao_pais_encontrado_ataque] = tropas_pais[posicao_pais_encontrado_ataque] - 1;
					}
		
					else{ //ganho ataque
						tropas_pais[posicao_pais_encontrado_defesa] = tropas_pais[posicao_pais_encontrado_defesa] - 1;
						if(tropas_pais[posicao_pais_encontrado_defesa] == 0){ //se o a defesa ñ tiver mais tropas...
							if(strcmp(player[vez], player1) == 0){ //se for a vez do player 1
								pais[posicao_pais_encontrado_defesa][0] = '1'; //player1 conquista o territorio do player2
							}
							else if(strcmp(player[vez], player2) == 0){ //se for player 2 
								pais[posicao_pais_encontrado_defesa][0] = '2'; //player2 conquista o territorio do player1
							}
							//atualizando o mapa...
							system("cls"); //limpando a tela
							print_mapa(); //reimprime o mapa
						}
					}
		
						
				}//FIM IF PERTENCIMENTO AO INIMIGO
	
				else{ //caso o país ñ pertença ao inimigo
					printf("[ERRO] Nao eh possivel selecionar esse pais! Por favor, tente outro.\n");
				}
		
			} //FIM IF QTD DE TROPAS >1
		
			else{//caso a quantidade de tropas seja insuficiente
				printf("[ERRO] Nao eh possivel selecionar esse pais! Por favor, tente outro.\n");
			}
		
		} //FIM IF PERTENCIMENTO  DO PAIS ATACANTE
		else{ //caso o pais Ã± pertenÃ§a ao jogador q estÃ¡ jogando
			printf("[ERRO] Nao eh possivel selecionar esse pais! Por favor, tente outro.\n");
		}
	
	//chamar funcao de remanejamento de tropas
				
	} //fim do while do ataque
	
}//fim da funcao (void)	
