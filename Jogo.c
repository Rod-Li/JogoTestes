#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>	

int ComprarCarta(){
	srand(time(NULL)); 
	int CartaValor = rand() %10;
	CartaValor += 1;
	if(CartaValor == 11){
		int As;
		do{
			printf("Vc tem um As\n");
			printf("Digite o valor da opcao\n");
			printf("O As Vale:\nNumero 1:(1)\nNumero 11:(2)\n");
			scanf("%d",&CartaValor);
			if(CartaValor==1){
				CartaValor=1;
				As=1;
			}
			else if(CartaValor==2){
				CartaValor=11;
				As=1;
			}
			else{
				system("cls");
				printf("Digite Um Valor Valido\n\n");
			}
		}while(As!=1);
		
		system("cls");
	}
	srand(time(NULL));
	if(CartaValor == 1){
		int As;
		do{
			printf("Vc tem um As\n");
			printf("Digite o valor da opcao\n");
			printf("O As Vale:\nNumero 1:(1)\nNumero 11:(2)\n");
			scanf("%d",&CartaValor);
			if(CartaValor==1){
				CartaValor=1;
				As=1;
			}
			else if(CartaValor==2){
				CartaValor=11;
				As=1;
			}
			else{
				system("cls");
				printf("Digite Um Valor Valido\n\n");
			}
		}while(As!=1);
		
		system("cls");
	}
	srand(time(NULL)); 
	return CartaValor;
}
int Jogador(){
	int SN;
	int Ver=0;
	do{
		printf("Vc quer comprar uma carta?\n");
		printf("Sim (1)\nNao (2)\n");
		scanf("%d",&SN);
		if(SN ==1){
			SN=1;
			Ver=1;
		}
		else if(SN ==2){
			SN=2;
			Ver=1;
		}
		else{
			system("cls");
			printf("Digite Uma Opcao Valida\n\n");
		}
	}while(Ver!=1);
	system("cls");
	if (SN == 2){
		return 0;
	}
	else{
		int DeckJogador = ComprarCarta();
		return DeckJogador;
	}
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
