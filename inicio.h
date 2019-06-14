//Essa biblioteca contÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â©m as funÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Âµes que serÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o usadas apenas no inicio do jogo

/*int EsperarTempo(int i)
{

	for(i; i >= 0; i--)
	{
		printf("%i\n",i); // Escreve na tela o nÃƒÆ’Ã‚Âºmero atual da 'contagem'
		//Delay(i*1000); // Espera 1 segundo
	}
}*/
int Menu_inicial(){
	
	printf("\t\t\t\t\t\t\t\t\t  Escolha a opcao \n\n");
	printf("\t\t\t\t\t\t\t\t\t   (0) - Regras \n");
	printf("\t\t\t\t\t\t\t\t\t   (1) - jogar \n");
	printf("\t\t\t\t\t\t\t\t\t   :");
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

	return menu;
}

void cadastro_players(){ //funÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o que irÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡ cadastrar os players em nomes de usuario
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
	
	while(strcasecmp(player1,player2) == 0){
		text_color(4);
		printf("\t\t\t\t\t\t\t [ERRO] OS DOIS NOMES SAO IGUAIS. POR FAVOR DIGITE NOVAMENTE\n");
		text_color(15);
		printf("\t\t\t\t\t\t\t     ");
		system("pause");
		system("cls");
		
		printf("\t\t\t\t\t\t\t\t Bem-vindo ao MINI WAR. \\o/ \\o/ \\o/ \n\n");
		
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
void aleat_players(){ //funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o que define de forma aleatoria quem vai iniciar o jogo
	
	int num_aleatorio;
	
	srand(time(NULL));
	
	num_aleatorio = rand() % 2; //um nÃƒÆ’Ã‚Âºmero aleatÃƒÆ’Ã‚Â³rio que receberÃƒÆ’Ã‚Â¡ 0 ou 1
	
	if(num_aleatorio == 0){ //se o nÃƒÆ’Ã‚Âºmero aleatÃƒÆ’Ã‚Â³rio for 0, o jogo vai iniciar pelo player 1
		
		strcpy(player[0], player1); 
		
		strcpy(player[1], player2);
		
	}else if(num_aleatorio == 1){ //se o numero aletorio for 1, o jogo vai iniciar pelo player 2
		
		strcpy(player[0], player2); 
	
		strcpy(player[1], player1);
	
	}
	
}

void cria_paises(char pais[21][4]){ //funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o que nomearÃƒÆ’Ã‚Â¡ os vinte paises com 3 caracteres cada, distribuindo-os aleatoriamente para cada jogador
		
	int cont_nome_pais, num_aleatorio, qntd_paises_player1 = 0, qntd_paises_player2 = 0;
	
	srand(time(NULL));
	
	for(cont_nome_pais = 0; cont_nome_pais < 20; cont_nome_pais++){ //repete 20 vezes a operaÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o pra nomear todos os 20 paÃƒÆ’Ã‚Â­ses
		
		num_aleatorio = rand() % 2; //o numero aleatorio receberÃƒÆ’Ã‚Â¡ um numero entre 0 e 1
		
		if((num_aleatorio == 0 && qntd_paises_player1 < 10) || qntd_paises_player2 >= 10){ //se o numero aletorio receber 0 e o player 1 ainda nÃƒÆ’Ã‚Â£o tiver 10 paises sob seu controle ou se a quantidade de paises sob controle do player 2 tiver chegado a 10, o paÃƒÆ’Ã‚Â­s passarÃƒÆ’Ã‚Â¡ a ser do player 1
			
			strcpy(num_player, "1\0"); //copia 1 na variÃƒÆ’Ã‚Â¡vel num_player
			
			qntd_paises_player1++; //aumenta em 1 a quantidade de paises sob controle do player 1
			
		} else if((num_aleatorio == 1 && qntd_paises_player2 < 10) || qntd_paises_player1 >= 10){ //se o numero aletorio receber 1 e o player 2 ainda nÃƒÆ’Ã‚Â£o tiver 10 paises sob seu controle ou se a quantidade de paises sob controle do player 1 tiver chegado a 10, o paÃƒÆ’Ã‚Â­s passarÃƒÆ’Ã‚Â¡ a ser do player 2
		
			strcpy(num_player, "2\0"); //copia 2 na variavel num_player
			
			qntd_paises_player2++; //aumenta em 1 a quantidade de paises sob controle do player 2
			
		} letra_pais[0] = 65 + cont_nome_pais; //define a letra que cada paÃƒÆ’Ã‚Â­s vai receber, seguindo a tabela ASCII
		
		letra_pais[1] = '-'; //adiciona um hÃƒÆ’Ã‚Â­fen que separa a identificaÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o do paÃƒÆ’Ã‚Â­s das tropas
		
		letra_pais[2] = '\0'; //pÃƒÆ’Ã‚Âµe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
		
		strcat(num_player, letra_pais); //concatena a numeraÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o do player com a letra do paÃƒÆ’Ã‚Â­s e o hÃƒÆ’Ã‚Â­fen na variÃƒÆ’Ã‚Â¡vel num_player
		
		strcpy(pais[cont_nome_pais], num_player); //copia na matriz pais[21][4] a identificaÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o de cada paÃƒÆ’Ã‚Â­s e a qual player pertence 
		
		num_player[0] = '\0'; //pÃƒÆ’Ã‚Âµe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
		
		letra_pais[0] = '\0'; //pÃƒÆ’Ã‚Âµe um fim na string (nn sei qual a necessidade disso, mas se tirar buga)
	}
	
}
