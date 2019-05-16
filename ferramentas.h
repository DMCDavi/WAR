//Essa biblioteca contém as funções que serão usadas como ferramentas úteis às outras

void print_mapa(){ //função que printa na tela o mapa
	
	system("color 1F"); //define as cores do mapa
	
	int cont_tropas = 0, cont_linhas, cont_colunas, cont_pais = 0, mapa[40][75] = {
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,7,0,7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,5,2,2,2,6,4,5,2,2,2,6,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,
3,3,3,3,3,3,3,7,0,7,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,0,7,7,0,7,3,7,0,7,7,0,7,7,0,7,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,8,2,2,2,9,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,8,2,2,2,9,4,8,2,2,2,9,8,2,2,2,9,8,2,2,2,9,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,4,5,2,2,2,6,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,0,7,3,7,0,7,7,0,7,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,4,8,2,2,2,9,8,2,2,2,9,8,2,2,2,9,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,3,3,3,7,0,7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,7,0,7,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,0,7,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,7,0,7,7,0,7,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,8,2,2,2,9,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
};
	
	for(cont_linhas = 0; cont_linhas < 40; cont_linhas++ ){ //percorre a matriz mapa toda e substitui seus valores por um caracter especial
		
		for(cont_colunas = 0 ; cont_colunas < 75; cont_colunas++ ){
			
			if(mapa[cont_linhas][cont_colunas] == NEVE){
				
				printf("%c%c",219,219);
					
			}else if(mapa[cont_linhas][cont_colunas] == AGUA){
				
				printf("%c%c",32,32);
										
			}else if(mapa[cont_linhas][cont_colunas] == HORIZONTAL){
				
				printf("%c%c",205,205);
										
			}else if(mapa[cont_linhas][cont_colunas] == VERTICAL){
				
				printf("%c%c",186,186);
										
			}else if(mapa[cont_linhas][cont_colunas] == CANTINFESQ){
				
				printf("%c%c",200,200);
										
			}else if(mapa[cont_linhas][cont_colunas] == CANTINFDIR){
				
				printf("%c%c",188,188);
										
			}else if(mapa[cont_linhas][cont_colunas] == CANTSUPESQ){
				
				printf("%c%c",201,201);	
									
			}else if(mapa[cont_linhas][cont_colunas] == CANTSUPDIR){
				
				printf("%c%c",187,187);
										
			}else if(mapa[cont_linhas][cont_colunas] == CAMINHOHOR){
				
				printf("%c%c",196,196);	
									
			}else if(mapa[cont_linhas][cont_colunas] == CAMINHOVER){
				
				printf("%c%c",124,124);	
									
			}else if(mapa[cont_linhas][cont_colunas] == PAIS){
						
				printf("%s%.3d", pais[cont_pais], tropas_pais[cont_tropas]);	//quando o valor 0 é encontrado na matriz, printa a identificação de cada país seguido da quantidade de tropas
			
				cont_pais++;
				
				cont_tropas++;
			}
				
		}printf("\n");
		
	} printf("======================================================================================================================================================\n");
	
}

bool teste_dono_pais(char letra){ //funÃ§Ã£o que testa se o paÃ­s pertence ao player ou nÃ£o, retornando true ou false
	
	bool true_false = true; //essa variavel fica armazenada como true, pois caso a letra digitada nÃ£o se refira a nenhum paÃ­s, o cÃ³digo irÃ¡ continuar, jÃ¡ que o erro do usuÃ¡rio nÃ£o foi selecionar uma paÃ­s que nÃ£o Ã© seu, mas sim um paÃ­s que nem existe
	
	int cont_matriz_pais; //variavel contadora que percorrerÃ¡ a matriz pais[21][4]
	
	if(letra >= 97 && letra <= 116){ //se a letra for minuscula de acordo com a tabela ascii, ela serÃ¡ tranformada em maiuscula para poder ser comparada com a letra do paÃ­s na matriz pais[21][4]
		
		letra = letra - 32; //transforma a letra minuscula em maiuscula
		
	}
	
	for(cont_matriz_pais = 0; cont_matriz_pais < 21; cont_matriz_pais++){ //percorre os 20 paises da matriz pais[21][4]
		
		if(pais[cont_matriz_pais][1] == letra){ //caso encontre a letra digitada, prosseguirÃ¡ a anÃ¡lise
		
			if(strcmp(player[vez], player1) == 0){ //a anÃ¡lise continua se a vez da rodada for do jogador 1
			
				if(pais[cont_matriz_pais][0] == '1'){ //se o nÃºmero encontrado no paÃ­s tiver a numeraÃ§Ã£o 1, a funÃ§Ã£o retornarÃ¡ true, senÃ£o retornarÃ¡ false
					
					true_false = true;
					
					break; //para de percorrer a matriz caso a resposta seja obtida
					
				} else{
					
					true_false = false;
					
					break; //para de percorrer a matriz caso a resposta seja obtida
					
				}
			
			} else if(strcmp(player[vez], player2) == 0){ //a anÃ¡lise continua se a vez da rodada for do jogador 2 
				
				if(pais[cont_matriz_pais][0] == '2'){ //se o nÃºmero encontrado no paÃ­s tiver a numeraÃ§Ã£o 2, a funÃ§Ã£o retornarÃ¡ true, senÃ£o retornarÃ¡ false
					
					true_false = true;
					
					break; //para de percorrer a matriz caso a resposta seja obtida
					
				} else{
					
					true_false = false;
					
					break; //para de percorrer a matriz caso a resposta seja obtida
					
				}
				
			}
			
		}
		
	}
	
	return true_false;
}

bool teste_existencia_pais(char letra){ //função que testa se a letra digitada esta entre A e T maiusculo ou minusculo
	
	bool true_false;
	
	if((letra >= 65 && letra <= 84) || (letra >= 97 && letra <= 116)){
		
		true_false = true;
		
	} else{
		
		true_false = false;
		
	} return true_false;
		
}

bool teste_vizinhanca_pais(char pais_origem, char pais_destino){
	
	bool true_false;
	
	if(pais_origem >= 97 && pais_origem <= 116){ //se a letra for minuscula de acordo com a tabela ascii, ela será tranformada em maiuscula para poder ser comparada posteriormente
		
		pais_origem = pais_origem - 32; //transforma a letra minuscula em maiuscula
		
	} if(pais_destino >= 97 && pais_destino <= 116){ //se a letra for minuscula de acordo com a tabela ascii, ela será tranformada em maiuscula para poder ser comparada posteriormente
		
		pais_destino = pais_destino - 32; //transforma a letra minuscula em maiuscula
		
	} if(pais_origem == 'A'){
		
		if(pais_destino == 'C' || pais_destino == 'D'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'B'){
		
		if(pais_destino == 'H' || pais_destino == 'C' || pais_destino == 'I'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'C'){
		
		if(pais_destino == 'A' || pais_destino == 'B'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'D'){
		
		if(pais_destino == 'A' || pais_destino == 'E'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'E'){
		
		if(pais_destino == 'D' || pais_destino == 'F' || pais_destino == 'J'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}	
		
	} else if(pais_origem == 'F'){
		
		if(pais_destino == 'E' || pais_destino == 'G' || pais_destino == 'K'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'G'){
		
		if(pais_destino == 'F' || pais_destino == 'H' || pais_destino == 'L'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'H'){
		
		if(pais_destino == 'G' || pais_destino == 'B' || pais_destino == 'M'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'I'){
		
		if(pais_destino == 'B' || pais_destino == 'N'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'J'){
		
		if(pais_destino == 'E' || pais_destino == 'K' || pais_destino == 'P'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'K'){
		
		if(pais_destino == 'J' || pais_destino == 'F' || pais_destino == 'L'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'L'){
		
		if(pais_destino == 'K' || pais_destino == 'G' || pais_destino == 'M'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'M'){
		
		if(pais_destino == 'H' || pais_destino == 'L' || pais_destino == 'S'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'N'){
		
		if(pais_destino == 'I' || pais_destino == 'Q' || pais_destino == 'O'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'O'){
		
		if(pais_destino == 'N' || pais_destino == 'P'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'P'){
		
		if(pais_destino == 'O' || pais_destino == 'R' || pais_destino == 'J'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'Q'){
		
		if(pais_destino == 'N'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'R'){
		
		if(pais_destino == 'P'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'S'){
		
		if(pais_destino == 'T' || pais_destino == 'M'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'T'){
		
		if(pais_destino == 'S'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	}

}
