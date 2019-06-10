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
	
		cadastro_players();

		aleat_players();

		cria_paises(pais);

		print_mapa();
		
		printf("\t\t\t\t\t\t\tCada pais possui uma numeracao seguido de uma letra.");
		text_color(10);
		printf("\n\t\t\t\t\t\t\t   Os paises de numero 1 pertencem a %s.",player1);
		text_color(1);
		printf("\n\t\t\t\t\t\t\t   Os paises de numero 2 pertencem a %s.\n",player2);
		printf("\t\t\t\t\t\t\t");
		text_color(15);
		system("pause");
		
		//comeca o jogo
		while(qntd_paises_player1 <20 || qntd_paises_player2 < 20){
			for(vez = 0; vez <= 1; vez++){ //laÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§o de repetiÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o que faz cada jogador adicionar suas tropas no inicio do jogo
      				text_color(10);
  				printf("\t\t\t\t\t\t\t\t\tTurno de %s! ", player[vez]);
   				add_tropas();
	
			}
		
			for(vez = 0; vez <= 1; vez++){ //laÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§o de repetiÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o que faz cada jogador adicionar suas tropas no inicio do jogo
				text_color(1);
			
				printf("\t\t\t\t\t\t\t\t\tTurno de %s! ", player[vez]);
				
				add_tropas();
		
				ataque_defesa(); //so ataca paises que nao tiveram tropas adicionadas
				
				remanejar_tropas(); // remaneja as tropas ao fim do turno	
				
			}
		
			//colocar apos a segunda rodada de tropas adicionadas
		
		} //fim do jogo
		
		//fim do jogo
		if(qntd_paises_player1 == 20){ //se o player1 ganhar
			printf("\n\n\t\t\t\t\t\t\t\t\t");
			printf("%s, voce dominou o mundo!!!\n", player1);
		}
		else if(qntd_paises_player2 == 20){ //se o player2 ganhar
			printf("\n\n\t\t\t\t\t\t\t\t\t");
			printf("%s, voce dominou o mundo!!!\n", player2);
		}		 
	
	return 0;
	
}
