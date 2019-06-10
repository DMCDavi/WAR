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
	//jogo acontecendo
	//colocar laco para o jogo so parar quando um dos jogadores conquistar o mundo
		cadastro_players();

		aleat_players();

		cria_paises(pais);

		print_mapa();

		printf("Cada pais possui uma numeracao seguido de uma letra.\nOs paises de numero 1 pertencem a %s.\nEnquanto os paises de numero 2 pertencem a %s.\n", player1, player2);

		system("pause");

		for(vez = 0; vez <= 1; vez++){ //laÃƒÆ’Ã‚Â§o de repetiÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o que faz cada jogador adicionar suas tropas no inicio do jogo
        
        printf("\t\t\t\t\t\t\t\tTurno de %s! ", player[vez]);
        
			add_tropas();

		}
		
		for(vez = 0; vez <= 1; vez++){ //laÃƒÆ’Ã‚Â§o de repetiÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o que faz cada jogador adicionar suas tropas no inicio do jogo
		
		printf("\t\t\t\t\t\t\t\tTurno de %s! ", player[vez]);
		
			ataque_defesa(); //so ataca paises que nao tiveram tropas adicionadas
			
			remanejar_tropas(); // remaneja as tropas ao fim do turno 

		}
	
		//colocar apos a segunda rodada de tropas adicionadas
	
	} 
	
	return 0;
	
}
