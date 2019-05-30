#include "global.h"
#include "inicio.h"
#include "ferramentas.h"
#include "rodada.h"

int main(){
	
	cadastro_players();
	
	aleat_players();
	
	cria_paises(pais);
	
	print_mapa();
	
	printf("Cada pais possui uma numeracao seguido de uma letra.\nOs paises de numero 1 pertencem a %s.\nEnquanto os paises de numero 2 pertencem a %s.\n", player1, player2);
	
	system("pause");
	
	for(vez = 0; vez <= 1; vez++){ //laço de repetição que faz cada jogador adicionar suas tropas no inicio do jogo
		
		add_tropas();
		
		#include "global.h"
#include "inicio.h"
#include "ferramentas.h"
#include "rodada.h"
#include "ataque_defesa.h"

int main(){
	
	cadastro_players();
	
	aleat_players();
	
	cria_paises(pais);
	
	print_mapa();
	
	printf("Cada pais possui uma numeracao seguido de uma letra.\nOs paises de numero 1 pertencem a %s.\nEnquanto os paises de numero 2 pertencem a %s.\n", player1, player2);
	
	system("pause");
	
	for(vez = 0; vez <= 1; vez++){ //laÃ§o de repetiÃ§Ã£o que faz cada jogador adicionar suas tropas no inicio do jogo
		
		add_tropas();
		
		//ataque_defesa(); não funcionou depois q inseriu a letra do pais q vai atacar
		
	}
	
	return 0;
	
}
		
	}
	
	return 0;
	
}
