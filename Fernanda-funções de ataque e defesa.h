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
