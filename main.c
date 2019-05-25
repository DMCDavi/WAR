#include "global.h"
#include "inicio.h"
#include "ferramentas.h"
#include "rodada.h"

int main(){ //Deu certo
	
	cadastro_players();
	
	aleat_players();
	
	cria_paises(pais);
	
	print_mapa();
	
	printf("Cada pais possui uma numeracao seguido de uma letra.\nOs paises de numero 1 pertencem a %s.\nEnquanto os paises de numero 2 pertencem a %s.\n", player1, player2);
	
	system("pause");
	
	for(vez = 0; vez <= 1; vez++){ //laço de repetição que faz cada jogador adicionar suas tropas no inicio do jogo
		
		add_tropas();
		
	}
	
	return 0;
	
}
