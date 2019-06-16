#include "global.h"
#include "inicio.h"
#include "ferramentas.h"
#include "rodada.h"

//VSF DAVIR VC È GAY
int main(){
	
		
	
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
			for(vez = 0; vez <= 1; vez++){ //laco de repeticao que faz cada jogador adicionar suas tropas no inicio do jogo
      				
			  	if(strcmp(player[vez],player1) == 0){ //se for a vez do player1
					
					text_color(10); 
				}
				else if(strcmp(player[vez],player2) == 0){
					
					text_color(1);
				}
				printf("\t\t\t\t\t\t\t\t\tTurno de %s! ", player[vez]);
   				add_tropas();
	
			} vez = 0;
		
			while(qntd_paises_player1 != 20 && qntd_paises_player2 != 20){ //laco que faz cada jogador adicionar suas tropas no inicio do jogo
				
				if(strcmp(player[vez],player1) == 0){ //se for a vez do player1
						
					text_color(10); 
				}
				else if(strcmp(player[vez],player2) == 0){
						
					text_color(1);
				}
			
				printf("\t\t\t\t\t\t\t\t\tTurno de %s! ", player[vez]);
				
				add_tropas();
		
				ataque_defesa(); //so ataca paises que nao tiveram tropas adicionadas
				
				remanejar_tropas(); // remaneja as tropas ao fim do turno
				
				if(vez == 1){
					
					vez = 0;
					
				}else if(vez == 0){
					
					vez = 1;
					
				}	
				
			}
		
				
		} //fim do jogo		 
	
	}
	return 0;
	
}
