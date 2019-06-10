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
	
	printf("\n\t\t\t\t\t\t\t");
	printf("%s, chegou a sua vez de atacar! Para pular essa parte digite 0! Senao, prossiga normalmente o jogo!\n\n", player[vez]);
	
	while (strcmp(resposta_ataque, "sim") == 0 || strcmp(resposta_ataque, "SIM") == 0){ // LOOPING DO ATAQUE
		int maior_ataque[3] = {0, 0, 0}, maior_defesa[3] = {0, 0, 0}, dado_ataque[3] = {0, 0, 0}, dado_defesa[3] = {0, 0, 0}; 
		//vetores que armazenarao valores sorteados em ordem crescente		
		printf("%s, Digite a letra do pais com o qual deseja atacar:", player[vez]);
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
						printf("%s, digite a letra do pais adversario que voce deseja atacar:\n", player[vez]);
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
									printf("%s\n", player1);
								}
								else if(strcmp(player[vez], player2) == 0){
									printf("%s\n", player2);
								}
								for (cont_sorteio_dados=0; cont_sorteio_dados<qtd_dados_ataque; cont_sorteio_dados++){
									
									dado_ataque[cont_sorteio_dados] = (rand() % 6) + 1;
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
								if(strcmp(player[vez], player1) == 0){
									printf("%s\n", player2);
								}
								else if(strcmp(player[vez], player2) == 0){
									printf("%s\n", player1);
								}
								for (cont_sorteio_dados = 0; cont_sorteio_dados < qtd_dados_defesa; cont_sorteio_dados++){
									
									dado_defesa[cont_sorteio_dados] = (rand() % 6) + 1;
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
										printf("%s\tx\t%s\n", player1, player2);
									}
									else if(strcmp(player[vez], player2) == 0){
										printf("\n\n\t\t\t\t\t\t\t\t\t");
										printf("%s\tx\t%s\n", player2, player1);
									}
									printf("\n\n\t\t\t\t\t\t\t\t\t");
									printf("%d\tx\t%d\n", maior_ataque[cont_sorteio_dados], maior_defesa[cont_sorteio_dados]);
									
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
									system("pause");
									//atualizando o mapa...
									system("cls"); //limpando a tela
									print_mapa(); //reimprime o mapa
									
									while(tropas_pais[posicao_pais_encontrado_defesa] == 0){
										
										if(tropas_pais[posicao_pais_encontrado_defesa] == 0){ //se o a defesa nao tiver mais tropas...
										
											printf("%s, quantas tropas voce deseja colocar no territorio conquistado?\n", player[vez]);
											scanf("%d", &tropas_realocar);
											
											if(tropas_realocar < tropas_pais[posicao_pais_encontrado_ataque] && tropas_realocar <= qtd_dados_ataque){
												
												tropas_pais[posicao_pais_encontrado_defesa] += tropas_realocar;
												tropas_pais[posicao_pais_encontrado_ataque] -= tropas_realocar;
												system("cls"); //limpando a tela
												print_mapa(); //reimprime o mapa
												
											}else{
												text_color(4);
												printf("[ERRO] O NUMERO DE TROPAS EXCEDE A QUANTIDADE DE TROPAS DE SEU PAIS. Digite novamente\n");
												
											}
																
										}
									}
															
								} //fim for print dos dados em ordem crescente								
							
							}//FIM IF PERTENCIMENTO AO INIMIGO
							
							else{ //caso o pais nao pertenca ao inimigo
								text_color(4);
								printf("[ERRO] NAO EH POSSIVEL SELECIONAR ESSE PAIS! Por favor, tente outro.\n");
							}
							
						}//FIM IF EXISTENCIA PAIS ATACADO 
						
						else{//se o pais atacado nao existir
							text_color(4);
							printf("[ERRO] ESSE PAIS NAO EXISTE! Por favor, tente outro!\n");
						}
						
					} //FIM IF QTD DE TROPAS > 1
				
					else if(tropas_pais[posicao_pais_encontrado_ataque] == 1){//caso a quantidade de tropas seja insuficiente
						text_color(4);
						printf("[ERRO] NUMERO DE TROPAS INSUFICIENTE PARA ATAQUE! Por favor, tente outro.\n");
					}
				
				} //FIM IF PERTENCIMENTO  DO PAIS ATACANTE
				
				
				else //if(teste_dono_pais(pais_desejado_atacante) || teste_existencia_pais(pais_desejado_atacante)){ //caso o pais ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â± pertenÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§a ao jogador q estÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ jogando
				{	
					text_color(4);
					printf("[ERRO] ESSE PAIS NAO TE PERTENCE! Por favor, tente outro.\n");
				}	
				
			}//FIM IF EXISTENCIA PAIS ATACANTE
				
			else{ //se o pais atacante nao existir	
				text_color(4);
				printf("[ERRO] ESSE PAIS NAO EXISTE! Por favor tente outro!\n");
			}

		}//fim resposta != de 0
		
		//perguntando se deseja novo ataque
		text_color(15);
		printf("\nDeseja atacar novamente? [SIM][NAO]\n");
		scanf("%s", resposta_ataque);
				
	} //fim do while do ataque
		
}//fim da funcao (void)	
