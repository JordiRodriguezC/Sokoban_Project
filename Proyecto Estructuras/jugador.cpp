#include "Nodo.h"
#include "jugador.h"
#include <iostream>
using namespace std;

jugador::jugador() {
	//ini = NULL;	
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


