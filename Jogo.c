#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>	

int Jogador(){
	int SN;
	printf("Vc quer comprar uma carta?\n");
	printf("Sim (1)\nNao (0)\n");
	scanf("%d",&SN);
	system("cls");
	if (SN == 0){
		return 0;
	}
	else{
		int DeckJogador = ComprarCarta();
		return DeckJogador;
	}
}

int ComprarCarta(){
	srand(time(NULL)); 
	int CartaValor = rand() %10;
	CartaValor += 1;
	if(CartaValor == 11){
		int As;
		printf("Vc tem um As\n");
		printf("Digite o valor da opcao\n");
		printf("O As Vale:\nNumero 1:(1)\nNumero 11:(11)\n");
		scanf("%d",&CartaValor);
		
		system("cls");
	}
	srand(time(NULL));
	if(CartaValor == 1){
		int As;
		printf("Vc tem um As\n");
		printf("Digite o valor da opcao\n");
		printf("O As Vale:\nNumero 1:(1)\nNumero 11:(11)\n");
		scanf("%d",&CartaValor);
		
		system("cls");
	}
	srand(time(NULL)); 
	return CartaValor;
}

int main(){
	int Parada=0;
	int DeckJogador=0;
	int DeckBot=0;
	DeckJogador = ComprarCarta();
	do{
		int VerificarJogador;
		printf("Vc tem um total de %d\n\n", DeckJogador);
		if(DeckJogador >20){
			Parada=1;
		}
		else{
			VerificarJogador = Jogador();
		}
		if(VerificarJogador == 0){
			Parada=1;
		}
		else if(DeckJogador > 20){
			Parada=1;
		}
		else if(Parada==0){
			DeckJogador += VerificarJogador;
		}
	}while(Parada != 1);
	srand(time(NULL)); 
	int CartaBOT = rand() %18;//Maximo do valor do deck do bot 23
	CartaBOT += 5;//Minimo do valor do deck do bot 5
	if(CartaBOT == DeckJogador){
		printf("Empate");
	}
	else if(CartaBOT > 21){
		printf("Voce Ganhou");
	}
	else if(DeckJogador > 21){
		printf("Voce Perdeu");
	}
	else if(CartaBOT > DeckJogador){
		printf("Voce Perdeu");
	}
	else if(CartaBOT < DeckJogador){
		printf("Voce Ganhou");
	}
}
