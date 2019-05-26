//verificacao do numero de tropas do pais que ataca

void relacao_atacante_tropas(){ 
	int cont_pais, posicao_pais_encontrado_ataque = 0;
	//pesquisa o pais correspondente 

	if(pais_atacante >= 97 && pais_atacante <= 116){
		pais_atacante = pais_atacante - 32; //transformando para caracter maiusculo
	}
	for(cont_pais = 0; cont_pais < 21; cont_pais++){
		if(strcmp(pais[cont_pais][1], pais_atacante) == 0) {
			posicao_pais_encontrado_ataque = cont_pais;
		}
	}

	
}

void verifica_tropa_pais(){
	if (tropas[posicao_pais_encontrado] 
}
void relacao_defesa_tropas(){ 
	int cont_pais, posicao_pais_encontrado_defesa = 0;
	//pesquisa o pais correspondente 

	if(pais_atacado >= 97 && pais_atacado <= 116){
		pais_atacado = pais_atacado - 32; //transformando para caracter maiusculo
	}
	for(cont_pais = 0; cont_pais < 21; cont_pais++){
		if(strcmp(pais[cont_pais][1], pais_atacado) == 0) {
			posicao_pais_encontrado_defesa = cont_pais;
		}
	}

	
}
