//dados de ataque e defesa (apos ter add as tropas aos seus devidos territorios
void ataque (int qtd_dados_ataque, qtd_dados_defesa){
	int ataque = 0, defesa = 0;
	char pais_desejado_atacante[2], pais_desejado_atacado[2];
	printf("%s, chegou a sua vez de atacar! Para pular essa parte digite 0! Senao, prossiga normalmente o jogo!\n");
	while (pais_desejado_atacante != '0' || pais_desejado_atacado != '0'){ 
					// LOOPING DO ATAQUE
	
		printf("%s, Digite a letra do país com o qual deseja atacar: ", player[vez]);
		scanf("%s", pais_desejado_atacante);
		fflsuh(stdin);
		
		//-------------------------------parte de verificacao de pertencimento do pais ao jogador :
		//caso o pais ñ pertenca ao player q ataca...
		while(!=teste_dono_pais(pais_desejado_atacante)){ //looping do n pertencimento
			printf("Nao eh possivel selecionar esse pais. Por favor, tente outro.\n");
			scanf("%s", pais_desejado_atacante);
			fflsuh(stdin);
		}
		//if (teste_dono_pais (pais_desejado_atacante)){ 
		//se pertencer ao jogador
		//caso a qtd de tropas seja insuficiente...
		while(tropas_pais[posicao_pais_encontrado_ataque] == 1){ // looping tropas = 1
			printf("Nao eh possivel selecionar esse pais. Por favor, tente outro.\n");
			scanf("%s", pais_desejado_atacante);
			fflsuh(stdin);
		}
		//if (tropas_pais[posicao_pais_encontrado_ataque] != 1) { 
				//colocar funcao de relacao_atacante_tropas
								
				//determinando a quantidade de dados maximo do jogador
		if(tropas_pais[posicao_pais_encontrado_ataque] == 2) qtd_dados_ataque = 1;
		else if (tropas_pais[posicao_pais_encontrado_ataque] == 3) qtd_dados_ataque = 2;
		else if (tropas_pais[posicao_pais_encontrado_ataque] >=4) qtd_dados_ataque = 3;
				
				//selecionando quem vai ser atacado
		printf("%s, digite a letra do pais adversario que voce deseja atacar: ", player[vez]);
		scanf("%s", pais_desejado_atacado);
		fflush(stdin);
		
		//caso o pais ñ pertenca ao player q defende...
		while( != teste_dono_pais(pais_desejado_atacado) ){ //looping do n pertencimento
			printf("Nao eh possivel selecionar esse pais. Por favor, tente outro.\n");
			scanf("%s", pais_desejado_atacado);
			fflsuh(stdin);
		}
				
			// verificando pertencimento de do pais a ser atacado (inimigo)
		//if (teste_dono_pais (pais_desejado_atacado)) { //se pertencer ao inimigo
					
					//determinando a quantidade de dados para defesa do inimigo
		if(tropas_pais[num_pais] == 1) {
			qtd_dados_defesa = 1;
			}
		else if (tropas_pais[num_pais] == 2){
		 	qtd_dados_defesa = 2;
		}
		else if (tropas_pais[num_pais] >= 3){
			qtd_dados_defesa = 3;
		}
		int dado_defesa[qtd_dados_defesa];
		int i, maior_ataque[3] = {0, 0, 0}, , maior_defesa[3] = {0, 0, 0};
					
				//colocar funcao relacao_defesa_tropas

		//---------------------------------------ATAQUE
		for (i=0; i<qtd_dados_ataque; i++){
			srand(time(NULL));
			dado_ataque[i] = (rand() % 5) + 1;
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
			
			
				//-------DEFESA
		for (i=0; i<qtd_dados_defesa; i++){
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
	
		//-----------------------------------comparando valores de ataque e defesa (quem ganha/perde territorio)
		if(qtd_dados_defesa == qtd_dados_ataque == 3){ //3 de cada
			for(i=0; i<3; i++){
				if (maior_ataque[i] <= maior_defesa[i]){ //defesa ganhando
					defesa++;
				}
				else {
					ataque++;	
				}
			}
			//comparando vezes que o ataque ganhou da defesa ou vice-versa
			if (defesa >= ataque) {
				tropas_pais[num_pais] = tropas_pais[num_pais] - (defesa - ataque); //caso de ganho da defesa
				}
			else {
				tropas_pais[num_pais] = tropas_pais[num_pais] - (ataque - defesa); //caso de ganho ataque
				if(tropas_pais[num_pais] <= 1 ) {
					num_pais[0] == player[vez]; //conquista de territorio
				}
				//ainda falta colocar "automaticamente" o numero de tropas para 1 nesse territorio conquistado!!!
			}
		}
	
		if(qtd_dados_defesa == qtd_dados_ataque == 2){
			for(i=0; i<2; i++){
				if (maior_ataque[i] <= maior_defesa[i]){ 
					defesa++;
				}
				else{
					ataque++;	
				}  
			}
		
			//comparando vezes que o ataque ganhou da defesa ou vice-versa
			if (defesa >= ataque) {
				tropas_pais[num_pais] = tropas_pais[num_pais] - (maior_defesa - maior_ataque); //caso de ganho da defesa
			}
			else {
				tropas_pais[num_pais] = tropas_pais[num_pais] - (ataque - defesa); //caso de ganho ataque
				if(tropas_pais[num_pais] <= 1 ) {
					num_pais[0] == player[vez]; //conquista de territorio
				}
				//ainda falta colocar "automaticamente" o numero de tropas para 1 nesse territorio conquistado!!!
			}
		}
		
		if(qtd_dados_defesa == 3 && qtd_dados_ataque == 2){
			if(maior_ataque[1] <= maior_defesa[2] ){
				defesa++;
			}
			if(maior_ataque[0] <= maior_defesa[1] || maior_ataque[0] <= maior_defesa[0]){
				defesa++;	
			}
			else{
				ataque++;	
			}  
		
			//comparando vezes que o ataque ganhou da defesa ou vice-versa
			if (defesa >= ataque){
				tropas_pais[num_pais] = tropas_pais[num_pais] - (maior_defesa - maior_ataque); //caso de ganho da defesa
			}
			else {
				tropas_pais[num_pais] = tropas_pais[num_pais] - (ataque - defesa); //caso de ganho ataque
				if(tropas_pais[num_pais] <= 1 ){
					num_pais[0] == player[vez]; //conquista de territorio
				}
				//ainda falta colocar "automaticamente" o numero de tropas para 1 nesse territorio conquistado!!!
			}
		}
		if(qtd_dados_defesa == 2 && qtd_dados_ataque == 1){
			if(maior_ataque[0] <= maior_defesa[1] || ){
				defesa++;	
			} 
			else if(maior_ataque[0] > maior_defesa[1]){
				if ( maior_ataque[0] <= maior_defesa[0] ) {
					defesa++;	
				}
				if(maior_ataque[0] > maior_defesa[0]){  //ataque ganhou
					ataque++; 
				}
				else {  // ataque ganhando
					ataque++; 
				}		
			//comparando vezes que o ataque ganhou da defesa ou vice-versa
				if (defesa >= ataque){ //caso de ganho da defesa
					tropas_pais[num_pais] = tropas_pais[num_pais] - (maior_defesa - maior_ataque); 
				}
				else {
					tropas_pais[num_pais] = tropas_pais[num_pais] - (ataque - defesa); //caso de ganho ataque
					if(tropas_pais[num_pais] <= 1 ){
						num_pais[0] == player[vez]; //conquista de territorio
					}
				//ainda falta colocar "automaticamente" o numero de tropas para 1 nesse territorio conquistado!!!
				}
			}
 
		}		
			
			//chamar funcao de remanejamento de tropas
		}
				
	} //fim da funcao (void)
	
	
	
