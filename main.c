#include "global.h"
#include "inicio.h"
#include "ferramentas.h"
#include "rodada.h"
#include "ataque_defesa.h"

int main(){
	
	if(Menu_inicial == 0){
	// as regras vao entrar aqui, colocarei-as assim que eu tiver tempo e principalmente paciencia :)
		printf("regras vou botar depois\n");
		system("pause");
		system("cls");
		menu = 1;	
	}	
	
	if(Menu_inicial != 0){
	
	cadastro_players();
	
	aleat_players();
	
	cria_paises(pais);
	
	print_mapa();
	
	printf("Cada pais possui uma numeracao seguido de uma letra.\nOs paises de numero 1 pertencem a %s.\nEnquanto os paises de numero 2 pertencem a %s.\n", player1, player2);
	
	system("pause");
	
	for(vez = 0; vez <= 1; vez++){ //laÃƒÂ§o de repetiÃƒÂ§ÃƒÂ£o que faz cada jogador adicionar suas tropas no inicio do jogo
		
		add_tropas();
		
	}
	
	for(vez = 0; vez <= 1; vez++){
			
		ataque_defesa(); //so ataca paises que nao tiveram tropas adicionadas
	}
	
	} 
	
	return 0;
	
}
