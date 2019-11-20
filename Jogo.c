#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>	

int JogoIniciado(){
	int Parada=0;
	int DeckJogador=0;
	int DeckBot=0;
	DeckJogador = ComprarCarta();
	do{
		int VerificarJogador
		Jogador();
		VerificarJogador = Jogador();
		if(VerificarJogador == 0){
			Parada=1;
		}
		else{
			DeckJogador += Jogador();
		}
	}while(Parada != 1);
	DeckBot= Bot();
	if(DeckBot == DeckJogador){
		printf("Empate");
	}
	else if(DeckBot >= 21){
		printf("Voce Ganhou");
	}
	else if(DeckJogador >= 21){
		printf("Voce Perdeu");
	}
	else if(DeckBot >= DeckJogador){
		printf("Voce Perdeu");
	}
	else if(DeckBot <= DeckJogador){
		printf("Voce Ganhou");
	}
}

int Jogador(){
	ComprarCarta();
	int DeckJogador = ComprarCarta();
	return DeckJogador;
}
int Bot(){
	srand(time(NULL)); 
	int CartaValor = rand() %18;//Maximo do valor do deck do bot 23
	CartaValor += 5;//Minimo do valor do deck do bot 5
	return DeckBot;
}


int ComprarCarta(){
	srand(time(NULL)); 
	int CartaValor = rand() %10;
	CartaValor += 1;
	if(CartaValor == 11){
		printf("As");
		CartaValor == 11;//temporario
	}
	return CartaValor;
}
