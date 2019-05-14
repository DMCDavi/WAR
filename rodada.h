//Essa biblioteca contém as funções principais de cada rodada do jogo

void add_tropas(){ //funÃ§Ã£o para adicionar as tropas no inicio de cada rodada
	
	char posicao_pais; //vai receber a letra do pais 
	
	unsigned int num_pais, cont_num_pais, qntd_paises_player1 = 0, qntd_paises_player2 = 0, tropas_player[3], num_tropas_add; 

	for(cont_num_pais = 0; cont_num_pais < 21; cont_num_pais++){ //percorre a matriz pais[21][4] em busca dos numeros 1 e 2 que definirÃ£o a que player cada pais pertence
		
		if(pais[cont_num_pais][0] == '1'){ //se o pais tiver o numero 1, a variavel qntd_paises_player1 vai aumentar em 1
			
			qntd_paises_player1++;
			
		} else{ //se o pais tiver o numero 2, a variavel qntd_paises_player2 vai aumentar em 1
			
			qntd_paises_player2++;
			
		}
		
	} if(qntd_paises_player1 <= 6){ //se o player 1 tiver 6 paises ou menos sob seu controle, irá receber 3 tropas adicionais de qualquer forma
		
		tropas_player[0] = 3;
			
	} else{ //senao, a quantidade de tropas diposniveis para o player 1 sera igual a quantidade de paises sob seu controle dividido por dois
			
		tropas_player[0] = qntd_paises_player1 / 2; //armazena na variavel tropas_player[0] a quantidade de tropas que o player 1 tem disponivel para adicionar em seus paises
			
	} if(qntd_paises_player2 <= 6){ //se o player 2 tiver 6 paises ou menos sob seu controle, irá receber 3 tropas adicionais de qualquer forma

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

//dados de ataque e defesa (apos ter add as tropas aos seus devidos territorios
void ataque (int qtd_dados_ataque, qtd_dados_defesa){
	int ataque = 0, defesa = 0;
	char pais_desejado_atacante[2], pais_desejado_atacado[2];
	printf("%s, chegou a sua vez de atacar! Para pular essa parte digite 0! Senao, prossiga normalmente o jogo!\n");
	while (pais_desejado_atacante != 0 || pais_desejado_atacado != 0){ // looping do ataque
	
	printf("%s, digite a letra do país com o qual deseja atacar: ", player[vez]);
	scanf("%s", pais_desejado_atacante);
	fflsuh(stdin);
	//parte de verificacao de pertencimento do pais ao jogador :
	bool teste_dono_pais (char letra) //ñ entendi essa parte
	bool teste_existencia_pais (char pais_desejado_atacado) 
	
	if (tropas_pais[num_pais] == 1) printf("nao eh possivel atacar com o pais selecionado. Por favor digite escolha outro!\n");
	
	//determinando a quantidade de dados maximo do jogador
	if(tropas_pais[num_pais] == 2) qtd_dados_ataque = 1;
	else if (tropas_pais[num_pais] == 3) qtd_dados_ataque = 2;
	else if (tropas_pais[num_pais] >=4) qtd_dados_ataque = 3;
	printf("%s, digite a letra do pais adversario que voce deseja atacar: ", player[vez]);
	scanf("%s", pais_desejado_atacado);
	fflush(stdin);
	bool teste_dono_pais (char letra) // coloca variavel "letra" mesmo ou pode colocar "pais_desejado_atacado"?
	bool teste_existencia_pais (char pais_desejado_atacado)
	//verificacao de pertencimento ao pais inimigo
	
	//determinando a quantidade de dados para defesa do inimigo
	if(tropas_pais[num_pais] == 1) qtd_dados_defesa = 1;
	else if (tropas_pais[num_pais] == 2) qtd_dados_defesa = 2;
	else if (tropas_pais[num_pais] >=3) qtd_dados_defesa = 3;
	int dado_defesa[qtd_dados_defesa];
	int i, maior_ataque[3] = {0, 0, 0}, , maior_defesa[3] = {0, 0, 0};

	//---------------------------------------------------------ataque
	for (i=0; i<qtd_dados_ataque; i++){
		srand(time(NULL));
		dado_ataque[i] = (rand() % 5) + 1;
	}
	
	//colocando em ordem crescente os numeros sorteados pelos dados de ataque
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
	
	
	//-------------------------------------------------defesa
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
			else ataque++;
		}
		//comparando vezes que o ataque ganhou da defesa ou vice-versa
		if (defesa >= ataque) tropas_pais[num_pais] = tropas_pais[num_pais] - (defesa - ataque); //caso de ganho da defesa
		else {
			tropas_pais[num_pais] = tropas_pais[num_pais] - (ataque - defesa); //caso de ganho ataque
			if(tropas_pais[num_pais] <= 1 ) num_pais[0] == player[vez]; //conquista de territorio
			
			//ainda falta colocar "automaticamente" o numero de tropas para 1 nesse territorio conquistado!!!
		}
	}
	
	if(qtd_dados_defesa == qtd_dados_ataque == 2){
		for(i=0; i<2; i++){
			if (maior_ataque[i] <= maior_defesa[i]){ 
				defesa++;
			}
			else ataque++; 
		}
		
		//comparando vezes que o ataque ganhou da defesa ou vice-versa
		if (defesa >= ataque) tropas_pais[num_pais] = tropas_pais[num_pais] - (maior_defesa - maior_ataque); //caso de ganho da defesa
		else {
			tropas_pais[num_pais] = tropas_pais[num_pais] - (ataque - defesa); //caso de ganho ataque
			if(tropas_pais[num_pais] <= 1 ) num_pais[0] == player[vez]; //conquista de territorio
			//ainda falta colocar "automaticamente" o numero de tropas para 1 nesse territorio conquistado!!!
		}
	}
	if(qtd_dados_defesa == 3 && qtd_dados_ataque == 2){
		if(maior_ataque[1] <= maior_defesa[2] ) defesa++;
		if(maior_ataque[0] <= maior_defesa[1] || maior_ataque[0] <= maior_defesa[0]) defesa++;
		else ataque++; 
		
		//comparando vezes que o ataque ganhou da defesa ou vice-versa
		if (defesa >= ataque) tropas_pais[num_pais] = tropas_pais[num_pais] - (maior_defesa - maior_ataque); //caso de ganho da defesa
		else {
			tropas_pais[num_pais] = tropas_pais[num_pais] - (ataque - defesa); //caso de ganho ataque
			if(tropas_pais[num_pais] <= 1 ) num_pais[0] == player[vez]; //conquista de territorio
			//ainda falta colocar "automaticamente" o numero de tropas para 1 nesse territorio conquistado!!!
		}
	}
	if(qtd_dados_defesa == 2 && qtd_dados_ataque == 1){
		if(maior_ataque[0] <= maior_defesa[1] || ) defesa++;
		else if(maior_ataque[0] > maior_defesa[1]){
			if ( maior_ataque[0] <= maior_defesa[0] ) defesa++;
			if(maior_ataque[0] > maior_defesa[0]) ataque++; //ataque ganhou
		}
		else ataque++; // ataque ganhando
		
		//comparando vezes que o ataque ganhou da defesa ou vice-versa
		if (defesa >= ataque) tropas_pais[num_pais] = tropas_pais[num_pais] - (maior_defesa - maior_ataque); //caso de ganho da defesa
		else {
			tropas_pais[num_pais] = tropas_pais[num_pais] - (ataque - defesa); //caso de ganho ataque
			if(tropas_pais[num_pais] <= 1 ) num_pais[0] == player[vez]; //conquista de territorio
			//ainda falta colocar "automaticamente" o numero de tropas para 1 nesse territorio conquistado!!!
		}
	}
 
	}
	
}
//chamar a funcao de remanejamento de tropas
