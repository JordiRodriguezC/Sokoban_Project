#include "Nodo.h"
#include "jugador.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

jugador::jugador() {
}

void jugador::crearLista(int x, int y) {
	 mat = new Nodo**[x];
	for (int i = 0; i < x;i++) {
		mat[i] = new Nodo*[y];
	}
;	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			mat[i][j] = new Nodo();
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (i > 0 && j > 0 && i < x-1 && j < y-1) {
				mat[i][j]->setArriba(mat[i - 1][j]);
				mat[i][j]->setAbajo(mat[i + 1][j]);
				mat[i][j]->setDerecha(mat[i][j + 1]);
				mat[i][j]->setIzquierda(mat[i][j - 1]);
				
			}
			else if (i == 0 && j < y) {
				if (j == 0) {
					mat[i][j]->setAbajo(mat[i + 1][j]);
					mat[i][j]->setDerecha(mat[i][j + 1]);
					
				}
				else if (j + 1 == y) {
					mat[i][j]->setAbajo(mat[i + 1][j]);
					mat[i][j]->setIzquierda(mat[i][j - 1]);
				
				}
				else {
					mat[i][j]->setIzquierda(mat[i][j - 1]);
					mat[i][j]->setDerecha(mat[i][j + 1]);
					mat[i][j]->setAbajo(mat[i + 1][j]);
				
				}
			}
			else if (i + 1 == x && j < y) {
				if (j == 0) {
					mat[i][j]->setArriba(mat[i - 1][j]);
					mat[i][j]->setDerecha(mat[i][j + 1]);
					
				}
				else if (j + 1 == y) {
					mat[i][j]->setIzquierda(mat[i][j - 1]);
					mat[i][j]->setArriba(mat[i - 1][j]);
					
				}
				else {
					mat[i][j]->setIzquierda(mat[i][j - 1]);
					mat[i][j]->setDerecha(mat[i][j + 1]);
					mat[i][j]->setArriba(mat[i - 1][j]);
					
				}
			}
			else if (j == 0) {
				mat[i][j]->setAbajo(mat[i + 1][j]);
				mat[i][j]->setDerecha(mat[i][j + 1]);
				mat[i][j]->setArriba(mat[i - 1][j]);
				
			}
			else if(j+1==y){
				mat[i][j]->setIzquierda(mat[i][j - 1]);
				mat[i][j]->setAbajo(mat[i + 1][j]);
				mat[i][j]->setArriba(mat[i - 1][j]);
				
			}
		}

	}
}


void jugador::crearNivel(char map[][9], int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {

			mat[i][j]->setId(map[i][j]);
			if (map[i][j] == '@') {
				ini = mat[i][j];
			}
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
		j1->Nivel2();		
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

void jugador::gotoxy(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
jugador* J1 = new jugador();
void jugador::Nivel1()
{	
	char map[8][9] =
	{
		{' ',' ','#','#','#',' ',' ',' ',' '},
		{' ',' ','#','.','#',' ',' ',' ',' '},
		{' ',' ','#',' ','#','#','#','#',' '},
		{'#','#','#','$',' ','$','.','#',' '},
		{'#','.',' ','$','@','#','#','#',' '},
		{'#','#','#','#','$','#',' ',' ',' '},
		{' ',' ',' ','#','.','#',' ',' ',' '},
		{' ',' ',' ','#','#','#',' ',' ',' '}
	};

	J1->crearLista(8, 9);
	cout << "MAPA 1" << endl << endl;
	J1->crearNivel(map, 8, 9);
	Movimientos(8,6);
}

void jugador::Nivel2()
{
	char map2[9][9] =
	{
		{ '#', '#', '#', '#', '#', ' ', ' ',' ', ' ' },
		{ '#', ' ', ' ', ' ', '#', ' ', ' ',' ', ' ' },
		{ '#', ' ', '$', ' ', '#', ' ', '#','#',  '#' },
		{ '#', ' ', '$', ' ', '#', ' ', '#','.' , '#'},
		{ '#', '#', '#', '!', '#', '#', '#','.' , '#'},
		{ ' ', '#', '#', ' ', '@', ' ', ' ','.' , '#'},
		{ ' ', '#', ' ', '$', ' ', '#', ' ',' ' , '#'},
		{ ' ', '#', ' ', ' ', ' ', '#', '#','#' , '#'},
		{ ' ', '#', '#', '#', '#', '#', ' ',' ' , ' '}
	};
	J1->crearLista(9, 9);
	cout << "MAPA 1" << endl << endl;
	J1->crearNivel(map2, 9, 9);
	Movimientos(8,7);
}

void jugador::Movimientos(int X, int Y)
{
#define DOWN 80
#define UP 72
#define RIGTH 77
#define LEFT 75
	bool sobrepunto = false;
	while (1) {	
		J1->ini->setX(X); J1->ini->setY(Y);
		gotoxy(J1->ini->getX(), J1->ini->getY());
	
		if (_kbhit()) {
			char tecla = _getch();
			switch (tecla) {
			case UP: {		
			if(J1->ini->getArriba()!=NULL)
				if (J1->ini->getArriba()->getId()==' '){
					if (sobrepunto) {
						J1->ini = J1->ini->getArriba();
						J1->ini->setId('@');
						J1->ini->getAbajo()->setId('.');
						Y--;
						J1->ini->setX(X); J1->ini->setY(Y);
						cout << J1->ini->getAbajo()->getId();
						gotoxy(J1->ini->getX(), J1->ini->getY());
						cout << J1->ini->getId();
						sobrepunto = false;
					}
					else {
						J1->ini = J1->ini->getArriba();
						J1->ini->setId('@');
						J1->ini->getAbajo()->setId(' ');
						Y--;
						J1->ini->setX(X); J1->ini->setY(Y);
						cout << J1->ini->getAbajo()->getId();
						gotoxy(J1->ini->getX(), J1->ini->getY());
						cout << J1->ini->getId();
					}
				}		
				else if (J1->ini->getArriba()->getId() == '$') {
					if (J1->ini->getArriba()->getArriba()->getId() == '.') {
						if (sobrepunto) {
							J1->ini = J1->ini->getArriba();
							J1->ini->setId('@');
							J1->ini->getAbajo()->setId('.');
							Y--;
							J1->ini->setX(X); J1->ini->setY(Y);
							cout << J1->ini->getAbajo()->getId();
							gotoxy(J1->ini->getX(), J1->ini->getY());
							cout << J1->ini->getId();
							sobrepunto = false;
						}
						else {
							J1->ini = J1->ini->getArriba();
							J1->ini->setId('@');
							J1->ini->getAbajo()->setId(' ');
							J1->ini->getArriba()->setId('!');
							Y--;
							J1->ini->setX(X); J1->ini->setY(Y);
							cout << J1->ini->getAbajo()->getId();
							gotoxy(J1->ini->getX(), J1->ini->getY());
							cout << J1->ini->getId();
							gotoxy(J1->ini->getX(), J1->ini->getY() - 1);
							cout << J1->ini->getArriba()->getId();
						}
					}
					else {
						if (J1->ini->getArriba()->getArriba()->getId() == ' ') {
							if (sobrepunto) {
								J1->ini = J1->ini->getArriba();
								J1->ini->setId('@');
								J1->ini->getAbajo()->setId('.');
								Y--;
								J1->ini->setX(X); J1->ini->setY(Y);
								cout << J1->ini->getAbajo()->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY());
								cout << J1->ini->getId();
								sobrepunto = false;
							}
							else {
								J1->ini = J1->ini->getArriba();
								J1->ini->setId('@');
								J1->ini->getAbajo()->setId(' ');
								J1->ini->getArriba()->setId('$');
								Y--;
								J1->ini->setX(X); J1->ini->setY(Y);
								cout << J1->ini->getAbajo()->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY());
								cout << J1->ini->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY() - 1);
								cout << J1->ini->getArriba()->getId();
							}
						}
					}
				}
				else {
					if (J1->ini->getArriba()->getId() == '!') {
						if (J1->ini->getArriba()->getArriba()->getId()==' ') {
							if (sobrepunto) {
								J1->ini = J1->ini->getArriba();
								J1->ini->setId('@');
								J1->ini->getAbajo()->setId('.');
								Y--;
								J1->ini->setX(X); J1->ini->setY(Y);
								cout << J1->ini->getAbajo()->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY());
								cout << J1->ini->getId();
								sobrepunto = false;
							}
							else {
								J1->ini = J1->ini->getArriba();
								sobrepunto = true;
								J1->ini->setId('@');
								J1->ini->getArriba()->setId('$');
								J1->ini->getAbajo()->setId(' ');
								Y--;
								J1->ini->setX(X); J1->ini->setY(Y);
								cout << J1->ini->getAbajo()->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY());
								cout << J1->ini->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY() - 1);
								cout << J1->ini->getArriba()->getId();
							}
						}
						else {
							if (J1->ini->getArriba()->getArriba()->getId() == '.') {
								if (sobrepunto) {
									J1->ini = J1->ini->getArriba();
									J1->ini->setId('@');
									J1->ini->getAbajo()->setId('.');
									Y--;
									J1->ini->setX(X); J1->ini->setY(Y);
									cout << J1->ini->getAbajo()->getId();
									gotoxy(J1->ini->getX(), J1->ini->getY());
									cout << J1->ini->getId();
									sobrepunto = false;
								}
								else {
									J1->ini = J1->ini->getArriba();
									sobrepunto = true;
									J1->ini->setId('@');
									J1->ini->getArriba()->setId('!');
									J1->ini->getAbajo()->setId(' ');
									Y--;
									J1->ini->setX(X); J1->ini->setY(Y);
									cout << J1->ini->getAbajo()->getId();
									gotoxy(J1->ini->getX(), J1->ini->getY());
									cout << J1->ini->getId();
									gotoxy(J1->ini->getX(), J1->ini->getY() - 1);
									cout << J1->ini->getArriba()->getId();
								}
							}
						}
					}
					else {
						if (J1->ini->getArriba()->getId() == '.') {
							J1->ini = J1->ini->getArriba();
							sobrepunto = true;
							J1->ini->setId('@');
							J1->ini->getAbajo()->setId(' ');
							Y--;
							J1->ini->setX(X); J1->ini->setY(Y);
							cout << J1->ini->getAbajo()->getId();
							gotoxy(J1->ini->getX(), J1->ini->getY());
							cout << J1->ini->getId();
						}
					}
				}
				break;
			}
			case DOWN: {
				if (J1->ini->getAbajo() != NULL)
					if (J1->ini->getAbajo()->getId() == ' ') {
						J1->ini = J1->ini->getAbajo();
						J1->ini->setId('@');
						J1->ini->getArriba()->setId(' ');
						Y++;
						J1->ini->setX(X); J1->ini->setY(Y);
						cout << J1->ini->getArriba()->getId();
						gotoxy(J1->ini->getX(), J1->ini->getY());
						cout << J1->ini->getId();
					}
					else if (J1->ini->getAbajo()->getId() == '$') {
						if (J1->ini->getAbajo()->getAbajo()->getId() == '.') {
							J1->ini = J1->ini->getAbajo();
							J1->ini->setId('@');
							J1->ini->getArriba()->setId(' ');
							J1->ini->getAbajo()->setId('!');
							Y++;
							J1->ini->setX(X); J1->ini->setY(Y);
							cout << J1->ini->getArriba()->getId();
							gotoxy(J1->ini->getX(), J1->ini->getY());
							cout << J1->ini->getId();
							gotoxy(J1->ini->getX(), J1->ini->getY()+1);
							cout << J1->ini->getAbajo()->getId();
						 }
						else {
							if (J1->ini->getAbajo()->getAbajo()->getId() == ' ') {
								J1->ini = J1->ini->getAbajo();
								J1->ini->setId('@');
								J1->ini->getArriba()->setId(' ');
								J1->ini->getAbajo()->setId('$');
								Y++;
								J1->ini->setX(X); J1->ini->setY(Y);
								cout << J1->ini->getArriba()->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY());
								cout << J1->ini->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY() + 1);
								cout << J1->ini->getAbajo()->getId();
							}
						}
					}
			
				break;
			}
			case RIGTH:{
				if (J1->ini->getDerecha() != NULL)
					if (J1->ini->getDerecha()->getId() == ' ') {
						J1->ini = J1->ini->getDerecha();
						J1->ini->setId('@');
						J1->ini->getIzquierda()->setId(' ');
						X++;
						X++;
						J1->ini->setX(X); J1->ini->setY(Y);
						cout << J1->ini->getIzquierda()->getId();
						gotoxy(J1->ini->getX(), J1->ini->getY());
						cout << J1->ini->getId();
						
					}
					else if (J1->ini->getDerecha()->getId() == '$' ) {
						if (J1->ini->getDerecha()->getDerecha()->getId() == '.') {
							J1->ini = J1->ini->getDerecha();
							J1->ini->setId('@');
							J1->ini->getIzquierda()->setId(' ');
							J1->ini->getDerecha()->setId('!');
							X++;
							X++;
							J1->ini->setX(X); J1->ini->setY(Y);
							cout << J1->ini->getIzquierda()->getId();
							gotoxy(J1->ini->getX(), J1->ini->getY());
							cout << J1->ini->getId();
							gotoxy(J1->ini->getX()+2, J1->ini->getY());
							cout << J1->ini->getDerecha()->getId();
						}
						else {
							if (J1->ini->getDerecha()->getDerecha()->getId() == ' ') {
								J1->ini = J1->ini->getDerecha();
								J1->ini->setId('@');
								J1->ini->getIzquierda()->setId(' ');
								J1->ini->getDerecha()->setId('$');
								X++;
								X++;
								J1->ini->setX(X); J1->ini->setY(Y);
								cout << J1->ini->getIzquierda()->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY());
								cout << J1->ini->getId();
								gotoxy(J1->ini->getX()+2, J1->ini->getY());
								cout << J1->ini->getDerecha()->getId();
							}
						}
					}
				break;
			}
			case LEFT:
				if (J1->ini->getIzquierda() != NULL)
					if (J1->ini->getIzquierda()->getId() == ' ') {
						J1->ini = J1->ini->getIzquierda();
						J1->ini->setId('@');
						J1->ini->getDerecha()->setId(' ');
						X--;
						X--;
						J1->ini->setX(X); J1->ini->setY(Y);
						cout << J1->ini->getDerecha()->getId();
						gotoxy(J1->ini->getX(), J1->ini->getY());
						cout << J1->ini->getId();
					}
					else if (J1->ini->getIzquierda()->getId() == '$' ) {
						if (J1->ini->getIzquierda()->getIzquierda()->getId() == '.') {
							J1->ini = J1->ini->getIzquierda();
							J1->ini->setId('@');
							J1->ini->getDerecha()->setId(' ');
							J1->ini->getIzquierda()->setId('!');
							X--;
							X--;
							J1->ini->setX(X); J1->ini->setY(Y);
							cout << J1->ini->getDerecha()->getId();
							gotoxy(J1->ini->getX(), J1->ini->getY());
							cout << J1->ini->getId();
							gotoxy(J1->ini->getX() - 2, J1->ini->getY());
							cout << J1->ini->getIzquierda()->getId();
						}
						else {
							if (J1->ini->getIzquierda()->getIzquierda()->getId() == ' ') {							
								J1->ini = J1->ini->getIzquierda();
								J1->ini->setId('@');
								J1->ini->getDerecha()->setId(' ');
								J1->ini->getIzquierda()->setId('$');
								X--;
								X--;
								J1->ini->setX(X); J1->ini->setY(Y);
								cout << J1->ini->getDerecha()->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY());
								cout << J1->ini->getId();
								gotoxy(J1->ini->getX() - 2, J1->ini->getY());
								cout << J1->ini->getIzquierda()->getId();
							}
						}
					}

				break;
			}
			

		}
}
}


