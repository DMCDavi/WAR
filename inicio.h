//Essa biblioteca contÃƒÂ©m as funÃƒÂ§ÃƒÂµes que serÃƒÂ£o usadas apenas no inicio do jogo

/*int EsperarTempo(int i)
{

	for(i; i >= 0; i--)
	{
		printf("%i\n",i); // Escreve na tela o nÃºmero atual da 'contagem'
		//Delay(i*1000); // Espera 1 segundo
	}
}*/
int Menu_inicial(){
	
	printf("\t\t\t\t\t\t\t\t\t  Escolha a opcao \n\n");
	printf("\t\t\t\t\t\t\t\t\t   (0) - Regras \n");
	printf("\t\t\t\t\t\t\t\t\t   (1) - jogar \n");
	scanf("%d",&menu);
	
	return menu;
}
void cadastro_players(){ //funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o que irÃƒÆ’Ã‚Â¡ cadastrar os players em nomes de usuario
	system("cls");
	printf("\t\t\t\t\t\t\t\t Bem-vindo ao MINI WAR! \\o/ \\o/ \\o/   \n\n");
	Menu_inicial();
	system("pause");
	system("cls");		
	//int k = 9;
	//sleep(2000);
	//EsperarTempo(k);
	
	text_color(10);	
	printf("Player 1, digite seu username: ");
	scanf(" %[^\n]s", &player1);
	system("cls");	
	
	text_color(1);
	printf("Player 2, digite seu username: ");
	scanf(" %[^\n]s", &player2);
	system("cls");
	
	if(strcasecmp(player1,player2) == 0){
		text_color(4);
		printf("[ERRO] OS DOIS NOMES SAO IGUAIS. POR FAVOR DIGITE NOVAMENTE\n");
		text_color(15);
		system("pause");
		system("cls");
		
		printf("\t\t\t\t\t Bem-vindo ao MINI WAR. \\o/ \\o/ \\o/ \n\n");
		
		text_color(10);
		printf("Player 1, digite seu username: ");
		scanf(" %[^\n]s", &player1);
	
		text_color(1);
		printf("Player 2, digite seu username: ");
		scanf(" %[^\n]s", &player2);
	text_color(15);
	system("pause");
	system("cls");
	}
	
}

void aleat_players(){ //funÃ§Ã£o que define de forma aleatoria quem vai iniciar o jogo
	
	int num_aleatorio;
	
	srand(time(NULL));
	
	num_aleatorio = rand() % 2; //um nÃºmero aleatÃ³rio que receberÃ¡ 0 ou 1
	
	if(num_aleatorio == 0){ //se o nÃºmero aleatÃ³rio for 0, o jogo vai iniciar pelo player 1
		
		strcpy(player[0], player1); 
		
		strcpy(player[1], player2);
		
	}else if(num_aleatorio == 1){ //se o numero aletorio for 1, o jogo vai iniciar pelo player 2
		
		strcpy(player[0], player2); 
	
		strcpy(player[1], player1);
	
	}
	
}

void cria_paises(char pais[21][4]){ //funÃ§Ã£o que nomearÃ¡ os vinte paises com 3 caracteres cada, distribuindo-os aleatoriamente para cada jogador
		
	int cont_nome_pais, num_aleatorio, qntd_paises_player1 = 0, qntd_paises_player2 = 0;
	
	srand(time(NULL));
	
	for(cont_nome_pais = 0; cont_nome_pais < 20; cont_nome_pais++){ //repete 20 vezes a operaÃ§Ã£o pra nomear todos os 20 paÃ­ses
		
		num_aleatorio = rand() % 2; //o numero aleatorio receberÃ¡ um numero entre 0 e 1
		
		if((num_aleatorio == 0 && qntd_paises_player1 < 10) || qntd_paises_player2 >= 10){ //se o numero aletorio receber 0 e o player 1 ainda nÃ£o tiver 10 paises sob seu controle ou se a quantidade de paises sob controle do player 2 tiver chegado a 10, o paÃ­s passarÃ¡ a ser do player 1
			
			strcpy(num_player, "1\0"); //copia 1 na variÃ¡vel num_player
			
			qntd_paises_player1++; //aumenta em 1 a quantidade de paises sob controle do player 1
			
		} else if((num_aleatorio == 1 && qntd_paises_player2 < 10) || qntd_paises_player1 >= 10){ //se o numero aletorio receber 1 e o player 2 ainda nÃ£o tiver 10 paises sob seu controle ou se a quantidade de paises sob controle do player 1 tiver chegado a 10, o paÃ­s passarÃ¡ a ser do player 2
		
			strcpy(num_player, "2\0"); //copia 2 na variavel num_player
			
			qntd_paises_player2++; //aumenta em 1 a quantidade de paises sob controle do player 2
			
		} letra_pais[0] = 65 + cont_nome_pais; //define a letra que cada paÃ­s vai receber, seguindo a tabela ASCII
		
		letra_pais[1] = '-'; //adiciona um hÃ­fen que separa a identificaÃ§Ã£o do paÃ­s das tropas
		
		letra_pais[2] = '\0'; //pÃµe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
		
		strcat(num_player, letra_pais); //concatena a numeraÃ§Ã£o do player com a letra do paÃ­s e o hÃ­fen na variÃ¡vel num_player
		
		strcpy(pais[cont_nome_pais], num_player); //copia na matriz pais[21][4] a identificaÃ§Ã£o de cada paÃ­s e a qual player pertence 
		
		num_player[0] = '\0'; //pÃµe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
		
		letra_pais[0] = '\0'; //pÃµe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
	}
	
}
