//Essa biblioteca contém as funções principais de cada rodada do jogo

void add_tropas(){ //função para adicionar as tropas no inicio de cada rodada
	
	char posicao_pais; //vai receber a letra do pais 
	
	int num_pais, cont_num_pais, qntd_paises_player1 = 0, qntd_paises_player2 = 0, tropas_player[3], num_tropas_add; 

	for(cont_num_pais = 0; cont_num_pais < 21; cont_num_pais++){ //percorre a matriz pais[21][4] em busca dos numeros 1 e 2 que definirão a que player cada pais pertence
		
		if(pais[cont_num_pais][0] == '1'){ //se o pais tiver o numero 1, a variavel qntd_paises_player1 vai aumentar em 1
			
			qntd_paises_player1++;
			
		} else{ //se o pais tiver o numero 2, a variavel qntd_paises_player2 vai aumentar em 1
			
			qntd_paises_player2++;
			
		}
		
	} tropas_player[0] = qntd_paises_player1 / 2; //armazena na variavel tropas_player[0] a quantidade de tropas que o player 1 tem disponivel para adicionar em seus paises
	
	tropas_player[1] = qntd_paises_player2 / 2; //armazena na variavel tropas_player[1] a quantidade de tropas que o player 2 tem disponivel para adicionar em seus paises

	while(tropas_player[vez] != 0){ //vai repetir o processo de adicionar as tropas até a quantidade de tropas disponiveis do player acabar
	
		printf("%s, voce possui %d tropas adicionais.\nDigite a letra do pais que deseja adicionar suas tropas:\n", player[vez], tropas_player[vez]); //diz a quantidade e quem vai começar a adicionar as tropas
		
		scanf("%s", &posicao_pais); //lê a letra do pais que o usuario quer adicionar as tropas
		
		fflush(stdin);
		
		if(teste_dono_pais(posicao_pais)){ //prossegue com o código apenas se o país digitado pelo usuário pertencer a ele, senão pede pra digitar novamente
			
			if(posicao_pais >= 65 && posicao_pais <= 84){ //se a letra digitada estiver entre A e T maiusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que será usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais = posicao_pais - 65;
				
			} else if(posicao_pais >= 97 && posicao_pais <= 116){ //se a letra digitada estiver entre a e t minusculas, a variavel num_pais vai armazanar um numero entre 0 e 19 que será usada posteiormente para representar as tropas de cada pais no vetor tropas_pais[21]
				
				num_pais = posicao_pais - 97;
				
			}
			
			if((posicao_pais >= 65 && posicao_pais <= 84) || (posicao_pais >= 97 && posicao_pais <= 116)){ //se a letra digitada estiver entre A e T maiusculo ou minusculo, o processo continua, senão pede pra digitar novamente
		
				printf("%s, voce possui %d tropas adicionais.\nDigite o numero de tropas que voce deseja adicionar nesse pais:\n", player[vez], tropas_player[vez]);
			
				scanf("%d", &num_tropas_add); // Lê o número de tropas que o player quer adicionar no pais
				
				if(num_tropas_add <= tropas_player[vez]){
					
					tropas_pais[num_pais] = tropas_pais[num_pais] + num_tropas_add; //adiciona a quantidade desejada de tropas no pais de interesse
					
					tropas_player[vez] = tropas_player[vez] - num_tropas_add; //diminui a quantidade de tropas disponiveis
					
					system ("cls"); //limpa a tela
			
					print_mapa(); //imprime o mapa com as novas tropas
					
				} else{
					
					printf("Voce apenas possui %d tropas. Digite novamente.\n", tropas_player[vez]);
					
				}
			
		} else{
				
				printf("Pais nao registrado. Digite novamente.\n"); //printa na tela essa mensagem caso a letra digitada não seja referente a nenhum país
				
			}
			
		} else{
			
			printf("O pais digitado nao te pertence. Digite novamente.\n"); //printa na tela essa mensagem caso o país não pertença ao player da vez
		
		} 
		
	}
	
}

//dados de ataque e defesa
int ataque (int qtd_dados){
	
	int dado_ataque[qtd_dados];
	
	int i;
	
	int maior_ataque = 0;
	
	for (i=0; i<qtd_dados; i++){
		
		srand(time(NULL));
		
		dado_ataque[i] = (rand() % 5) + 1;
		
		//pegando o maior numero sorteado pelos dados de ataque para compará-lo com o maior dos de defesa;
		if (maior_ataque < dado_ataque[i]) maior_ataque = dado_ataque[i];
					
	}
	
return maior_ataque; 

}


int defesa (int i, int dado_defesa[3], int maior_defesa){
	
	maior_defesa = 0;
	
	for (i=0; i<3; i++){
		
		srand(time(NULL));
		
		dado_defesa[i] = (rand() % 5) + 1;
		
		//pegando o maior numero sorteado pelos dados de ataque para compará-lo com o maior dos de defesa;
			
		if (maior_defesa < dado_defesa[i]) maior_defesa = dado_defesa[i];
				
	}
	
return maior_defesa; 

}
