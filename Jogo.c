#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>	

int posicaoJogo = 1;
int teclaPressionadaJogo = 0;

void setaJogo(int posicaoApontadaJogo, int posicaoDesejadaJogo){	/*FUNÃ‡ÃƒO: seta no jogo (somente o desenho, nÃ£o movimentos)*/	//posicaoApontadaJogo = posiÃ§Ã£o em que a seta aponta; posicaoDesejadaJogo = posiÃ§Ã£o que eu quero que a seta aponte
	
	if(posicaoApontadaJogo == posicaoDesejadaJogo){
		printf("    %c ", 16);
	}
	else{
		printf("    ");
	}
	
}

int ComprarCarta(){
	srand(time(NULL)); 
	int CartaValor = rand() %10;
	CartaValor += 1;
	if(CartaValor == 11){
		int As;
		do{
			printf("Vc tem um As\n");
			printf("Digite o valor da opcao\n");
			printf("O As Vale:\n");
			setaJogo(1, posicaoJogo); printf(" Numero 1\t\t");
			setaJogo(2, posicaoJogo); printf(" Numero 11\t\t");
			
			teclaPressionadaJogo = getch();	
				if(teclaPressionadaJogo == 75 && posicaoJogo == 2){		/*75 representa a tecla esquerda*/
					printf("\a");
					posicaoJogo--;
				}
				else{
					if(teclaPressionadaJogo == 77 && posicaoJogo == 1){	/*77 representa a tecla direita*/
						printf("\a");
						posicaoJogo++;
					}
					else{
						posicaoJogo = posicaoJogo;
					}						
				}
			
			
			if(teclaPressionadaJogo ==13 && posicaoJogo == 1){
				CartaValor=1;
				As=1;
			}
			else if(teclaPressionadaJogo ==13 && posicaoJogo == 2){
				CartaValor=11;
				As=1;
			}
			else{
				system("cls");
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
			printf("O As Vale:\n");
			setaJogo(1, posicaoJogo); printf(" Numero 1\t\t");
			setaJogo(2, posicaoJogo); printf(" Numero 11\t\t");
			
			teclaPressionadaJogo = getch();	
				if(teclaPressionadaJogo == 75 && posicaoJogo == 2){		/*75 representa a tecla esquerda*/
					printf("\a");
					posicaoJogo--;
				}
				else{
					if(teclaPressionadaJogo == 77 && posicaoJogo == 1){	/*77 representa a tecla direita*/
						printf("\a");
						posicaoJogo++;
					}
					else{
						posicaoJogo = posicaoJogo;
					}						
				}
			
			
			if(teclaPressionadaJogo ==13 && posicaoJogo == 1){
				CartaValor=1;
				As=1;
			}
			else if(teclaPressionadaJogo ==13 && posicaoJogo == 2){
				CartaValor=11;
				As=1;
			}
			else{
				system("cls");
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
	printf("Vc quer comprar uma carta?\n");
	setaJogo(1, posicaoJogo); printf(" Comprar carta\t\t");
	setaJogo(2, posicaoJogo); printf(" Terminar jogada");
	
	teclaPressionadaJogo = getch();	
		if(teclaPressionadaJogo == 75 && posicaoJogo == 2){		/*75 representa a tecla esquerda*/
			printf("\a");
			posicaoJogo--;
		}
		else{
			if(teclaPressionadaJogo == 77 && posicaoJogo == 1){	/*77 representa a tecla direita*/
				printf("\a");
				posicaoJogo++;
			}
			else{
				posicaoJogo = posicaoJogo;
			}						
		}
	
	if(teclaPressionadaJogo ==13 && posicaoJogo == 1){
		SN=1;
		Ver=1;
	}
	else if(teclaPressionadaJogo ==13 && posicaoJogo == 2){
		SN=2;
		Ver=1;
	}
	system("cls");
	if(Ver ==1){
		if (SN == 2){
			return 404;
		}
		else{
			int DeckJogador = ComprarCarta();
			return DeckJogador;
		}
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
		if(VerificarJogador == 404){
			Parada=1;
		}
		else if(VerificarJogador != 0){
			if(DeckJogador > 20){
				Parada=1;
			}
			else if(Parada==0){
				DeckJogador += VerificarJogador;
			}
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
