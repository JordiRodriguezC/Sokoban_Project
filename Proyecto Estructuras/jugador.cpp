#include "Nodo.h"
#include "jugador.h"
#include <iostream>
#include <conio.h>
using namespace std;

jugador::jugador() {
	ini = NULL;	

}

void jugador::crearLista(int x, int y) {
	Nodo*** matriz = new Nodo**[x];
	for (int i = 0; i < x;i++) {
		matriz[i] = new Nodo*[y];
	}
;	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			matriz[i][j] = new Nodo();
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (i > 0 && j > 0 && i < x-1 && j < y-1) {
				matriz[i][j]->setArriba(matriz[i - 1][j]);
				matriz[i][j]->setAbajo(matriz[i + 1][j]);
				matriz[i][j]->setDerecha(matriz[i][j + 1]);
				matriz[i][j]->setIzquierda(matriz[i][j - 1]);
				
			}
			else if (i == 0 && j < y) {
				if (j == 0) {
					matriz[i][j]->setAbajo(matriz[i + 1][j]);
					matriz[i][j]->setDerecha(matriz[i][j + 1]);
					
				}
				else if (j + 1 == y) {
					matriz[i][j]->setAbajo(matriz[i + 1][j]);
					matriz[i][j]->setIzquierda(matriz[i][j - 1]);
				
				}
				else {
					matriz[i][j]->setIzquierda(matriz[i][j - 1]);
					matriz[i][j]->setDerecha(matriz[i][j + 1]);
					matriz[i][j]->setAbajo(matriz[i + 1][j]);
				
				}
			}
			else if (i + 1 == x && j < y) {
				if (j == 0) {
					matriz[i][j]->setArriba(matriz[i - 1][j]);
					matriz[i][j]->setDerecha(matriz[i][j + 1]);
					
				}
				else if (j + 1 == y) {
					matriz[i][j]->setIzquierda(matriz[i][j - 1]);
					matriz[i][j]->setArriba(matriz[i - 1][j]);
					
				}
				else {
					matriz[i][j]->setIzquierda(matriz[i][j - 1]);
					matriz[i][j]->setDerecha(matriz[i][j + 1]);
					matriz[i][j]->setArriba(matriz[i - 1][j]);
					
				}
			}
			else if (j == 0) {
				matriz[i][j]->setAbajo(matriz[i + 1][j]);
				matriz[i][j]->setDerecha(matriz[i][j + 1]);
				matriz[i][j]->setArriba(matriz[i - 1][j]);
				
			}
			else if(j+1==y){
				matriz[i][j]->setIzquierda(matriz[i][j - 1]);
				matriz[i][j]->setAbajo(matriz[i + 1][j]);
				matriz[i][j]->setArriba(matriz[i - 1][j]);
				
			}
		}

	}
	mat = matriz;
}


void jugador::crearNivel(char map[][9],int x,int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			mat[i][j]->setId(map[i][j]);
		}
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << mat[i][j]->getId() << " ";
		}
		cout << endl;
	}
}

void jugador::MenuInicio()
{
	int Op;
	cout << "\t\t\t############# MENU #############\n\n";
	cout << "\t\t\t1- Nuevo Juego\n";
	cout << "\t\t\t2- Cargar Partida\n";
	cout << "\t\t\t3- Salir\n\n";
	cin >> Op;
	switch (Op) {
	case 1: {
		jugador* j1 = new jugador();
		system("cls");
		j1->Nivel1();
		
		break;
	}
	case 2: {
		break;
	}
	case 3: {
		exit(1);
	}

	}
}

void jugador::Nivel1()
{
	jugador* J1 = new jugador();
	J1->crearLista(8, 9);
	char map[8][9] =
	{
		{ ' ', ' ', '#', '#', '#', ' ', ' ',' ',' '},
		{ ' ', ' ', '#', '.', '#', ' ', ' ',' ',' '},
		{ ' ', ' ', '#', ' ', '#', '#', '#','#',' '},
		{ '#', '#', '#', '$', ' ', '$', '.','#',' '},
		{ '#', '.', ' ', '$', '@', '#', '#','#',' '},
		{ '#', '#', '#', '#', '$', '#', ' ',' ',' '},
		{ ' ', ' ', ' ', '#', '.', '#', ' ',' ',' '},
		{ ' ', ' ', ' ', '#', '#', '#', ' ',' ',' '}
	};
	cout << "MAPA 1" << endl << endl;
	J1->crearNivel(map, 8, 9);
	Movimientos();

}

void jugador::Movimientos()
{
#define DOWN 80
#define UP 72
#define RIGTH 77
#define LEFT 75
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			if (mat[i][j]->getId() =='@') {
				cout << "encontrado";
			}
		}
	}
	while (1) {
		if (_kbhit()) {
			char tecla = _getch();
			switch (tecla) {
			case UP: {
			
				cout << "ARRIBA";
				
				break;
			}
			case DOWN: {
				cout << "ABAJO";
				break;
			}
			case RIGTH:{
				cout << "DERECHA";
				break;
			}
			case LEFT:
				cout << "IZQUIERDA";
				break;
			}
			

		}
}
}


