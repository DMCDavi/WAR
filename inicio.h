//Essa biblioteca contÃƒÆ’Ã‚Â©m as funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Âµes que serÃƒÆ’Ã‚Â£o usadas apenas no inicio do jogo

/*int EsperarTempo(int i)
{

	for(i; i >= 0; i--)
	{
		printf("%i\n",i); // Escreve na tela o nÃƒÂºmero atual da 'contagem'
		//Delay(i*1000); // Espera 1 segundo
	}
}*/
int Menu_inicial(){
	
	printf("\t\t\t\t\t\t\t\t\t  Escolha a opcao \n\n");
	printf("\t\t\t\t\t\t\t\t\t   (0) - Regras \n");
	printf("\t\t\t\t\t\t\t\t\t   (1) - jogar \n");
	printf("\t\t\t\t\t\t\t\t\t    :");
	scanf("%d",&menu);
	if(menu == 0){
		printf("\n\t\t\t\t\t\t\t\t\t REGRAS: \t\t\t\t\t\t\t\t\t\n");
		printf("\n 1 - O jogo possui 20 paises. Cada jogador comecara inicialmente com a quantidade de paises no total dividido por 2(ou seja, 10). \n");
		printf("\n 2 - Todo turno, o jogador da rodada tem o direito de adicionar tropas em seus paises. A quantidade de tropas a adicionar eh igual ao numero de paises em posse do jogador dividido por 2!(arredondado para baixo.) \n");
		printf("\n 3 - O jogador da vez tem o direito de atacar o oponente ou nao, a depender de sua vontade! \n");
		printf("\n 4 - Ao final da parte de ataque, o jogador podera remanejar tropas ou nao, para ter como atacar com mais confianca no proximo turno ou se proteger do ataque do inimigo! \n");
		printf("\n 5 - Por ser uma mini versao do jogo, o unico objetivo eh conquistar TODOS os territorios existentes! \n");
		printf("\n 6 - Boa sorte e que venca o melhor!!! \n");
	}
/*	if(menu != int){
		printf("");
		Menu_inicial();
	}*/
	return menu;
}

void cadastro_players(){ //funÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o que irÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ cadastrar os players em nomes de usuario
	system("cls");
	printf("\t\t\t\t\t\t\t\t Bem-vindo ao MINI WAR! \\o/ \\o/ \\o/   \n\n");
	Menu_inicial();
	printf("\t\t\t\t\t\t\t     ");
	system("pause");
	system("cls");		
	//int k = 9;
	//sleep(2000);
	//EsperarTempo(k);
	
	text_color(10);	
	fflush(stdin);
	printf("\t\t\t\t\t\t\t\t Player 1, digite seu username: ");
	
	scanf(" %[^\n]s", &player1);
	system("cls");	
	
	text_color(1);
	printf("\t\t\t\t\t\t\t\t Player 2, digite seu username: ");
	
	scanf(" %[^\n]s", &player2);
	system("cls");
	
	if(strcasecmp(player1,player2) == 0){
		text_color(4);
		printf("\t\t\t\t\t\t\t\t [ERRO] OS DOIS NOMES SAO IGUAIS. POR FAVOR DIGITE NOVAMENTE\n");
		text_color(15);
		printf("\t\t\t\t\t\t\t     ");
		system("pause");
		system("cls");
		
		printf("\t\t\t\t\t Bem-vindo ao MINI WAR. \\o/ \\o/ \\o/ \n\n");
		
		text_color(10);
		printf("\t\t\t\t\t\t\t\t Player 1, digite seu username: ");
		scanf(" %[^\n]s", &player1);
	
		text_color(1);
		printf("\t\t\t\t\t\t\t\t Player 2, digite seu username: ");
		scanf(" %[^\n]s", &player2);
	text_color(15);
	printf("\t\t\t\t\t\t\t     ");
	system("pause");
	system("cls");
	}
	
}
void aleat_players(){ //funÃƒÂ§ÃƒÂ£o que define de forma aleatoria quem vai iniciar o jogo
	
	int num_aleatorio;
	
	srand(time(NULL));
	
	num_aleatorio = rand() % 2; //um nÃƒÂºmero aleatÃƒÂ³rio que receberÃƒÂ¡ 0 ou 1
	
	if(num_aleatorio == 0){ //se o nÃƒÂºmero aleatÃƒÂ³rio for 0, o jogo vai iniciar pelo player 1
		
		strcpy(player[0], player1); 
		
		strcpy(player[1], player2);
		
	}else if(num_aleatorio == 1){ //se o numero aletorio for 1, o jogo vai iniciar pelo player 2
		
		strcpy(player[0], player2); 
	
		strcpy(player[1], player1);
	
	}
	
}

void cria_paises(char pais[21][4]){ //funÃƒÂ§ÃƒÂ£o que nomearÃƒÂ¡ os vinte paises com 3 caracteres cada, distribuindo-os aleatoriamente para cada jogador
		
	int cont_nome_pais, num_aleatorio, qntd_paises_player1 = 0, qntd_paises_player2 = 0;
	
	srand(time(NULL));
	
	for(cont_nome_pais = 0; cont_nome_pais < 20; cont_nome_pais++){ //repete 20 vezes a operaÃƒÂ§ÃƒÂ£o pra nomear todos os 20 paÃƒÂ­ses
		
		num_aleatorio = rand() % 2; //o numero aleatorio receberÃƒÂ¡ um numero entre 0 e 1
		
		if((num_aleatorio == 0 && qntd_paises_player1 < 10) || qntd_paises_player2 >= 10){ //se o numero aletorio receber 0 e o player 1 ainda nÃƒÂ£o tiver 10 paises sob seu controle ou se a quantidade de paises sob controle do player 2 tiver chegado a 10, o paÃƒÂ­s passarÃƒÂ¡ a ser do player 1
			
			strcpy(num_player, "1\0"); //copia 1 na variÃƒÂ¡vel num_player
			
			qntd_paises_player1++; //aumenta em 1 a quantidade de paises sob controle do player 1
			
		} else if((num_aleatorio == 1 && qntd_paises_player2 < 10) || qntd_paises_player1 >= 10){ //se o numero aletorio receber 1 e o player 2 ainda nÃƒÂ£o tiver 10 paises sob seu controle ou se a quantidade de paises sob controle do player 1 tiver chegado a 10, o paÃƒÂ­s passarÃƒÂ¡ a ser do player 2
		
			strcpy(num_player, "2\0"); //copia 2 na variavel num_player
			
			qntd_paises_player2++; //aumenta em 1 a quantidade de paises sob controle do player 2
			
		} letra_pais[0] = 65 + cont_nome_pais; //define a letra que cada paÃƒÂ­s vai receber, seguindo a tabela ASCII
		
		letra_pais[1] = '-'; //adiciona um hÃƒÂ­fen que separa a identificaÃƒÂ§ÃƒÂ£o do paÃƒÂ­s das tropas
		
		letra_pais[2] = '\0'; //pÃƒÂµe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
		
		strcat(num_player, letra_pais); //concatena a numeraÃƒÂ§ÃƒÂ£o do player com a letra do paÃƒÂ­s e o hÃƒÂ­fen na variÃƒÂ¡vel num_player
		
		strcpy(pais[cont_nome_pais], num_player); //copia na matriz pais[21][4] a identificaÃƒÂ§ÃƒÂ£o de cada paÃƒÂ­s e a qual player pertence 
		
		num_player[0] = '\0'; //pÃƒÂµe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
		
		letra_pais[0] = '\0'; //pÃƒÂµe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
	}
	
}
