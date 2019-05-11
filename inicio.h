//Essa biblioteca contém as funções que serão usadas apenas no inicio do jogo

void cadastro_players(){ //função que irá cadastrar os players em nomes de usuario
	
	printf("Bem-vindo ao MINI WAR.\n");
		
	printf("Player 1, digite seu username: ");
	
	scanf(" %[^\n]s", &player1);
	
	printf("Player 2, digite seu username: ");
	
	scanf(" %[^\n]s", &player2);
	
	system("pause");
	
}

void aleat_players(){ //função que define de forma aleatoria quem vai iniciar o jogo
	
	int num_aleatorio;
	
	srand(time(NULL));
	
	num_aleatorio = rand() % 2; //um número aleatório que receberá 0 ou 1
	
	if(num_aleatorio == 0){ //se o número aleatório for 0, o jogo vai iniciar pelo player 1
		
		strcpy(player[0], player1); 
		
		strcpy(player[1], player2);
		
	}else if(num_aleatorio == 1){ //se o numero aletorio for 1, o jogo vai iniciar pelo player 2
		
		strcpy(player[0], player2); 
	
		strcpy(player[1], player1);
	
	}
	
}

void cria_paises(char pais[21][4]){ //função que nomeará os vinte paises com 3 caracteres cada, distribuindo-os aleatoriamente para cada jogador
		
	int cont_nome_pais, num_aleatorio, qntd_paises_player1 = 0, qntd_paises_player2 = 0;
	
	srand(time(NULL));
	
	for(cont_nome_pais = 0; cont_nome_pais < 20; cont_nome_pais++){ //repete 20 vezes a operação pra nomear todos os 20 países
		
		num_aleatorio = rand() % 2; //o numero aleatorio receberá um numero entre 0 e 1
		
		if((num_aleatorio == 0 && qntd_paises_player1 < 10) || qntd_paises_player2 >= 10){ //se o numero aletorio receber 0 e o player 1 ainda não tiver 10 paises sob seu controle ou se a quantidade de paises sob controle do player 2 tiver chegado a 10, o país passará a ser do player 1
			
			strcpy(num_player, "1\0"); //copia 1 na variável num_player
			
			qntd_paises_player1++; //aumenta em 1 a quantidade de paises sob controle do player 1
			
		} else if((num_aleatorio == 1 && qntd_paises_player2 < 10) || qntd_paises_player1 >= 10){ //se o numero aletorio receber 1 e o player 2 ainda não tiver 10 paises sob seu controle ou se a quantidade de paises sob controle do player 1 tiver chegado a 10, o país passará a ser do player 2
		
			strcpy(num_player, "2\0"); //copia 2 na variavel num_player
			
			qntd_paises_player2++; //aumenta em 1 a quantidade de paises sob controle do player 2
			
		} letra_pais[0] = 65 + cont_nome_pais; //define a letra que cada país vai receber, seguindo a tabela ASCII
		
		letra_pais[1] = '-'; //adiciona um hífen que separa a identificação do país das tropas
		
		letra_pais[2] = '\0'; //põe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
		
		strcat(num_player, letra_pais); //concatena a numeração do player com a letra do país e o hífen na variável num_player
		
		strcpy(pais[cont_nome_pais], num_player); //copia na matriz pais[21][4] a identificação de cada país e a qual player pertence 
		
		num_player[0] = '\0'; //põe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
		
		letra_pais[0] = '\0'; //põe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
	}
	
}
