#include "Nodo.h"
#include "jugador.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stack>
using namespace std;
jugador* J1 = new jugador();
jugador::jugador() {
}

void jugador::crearLista(int x, int y) {
	mat = new Nodo * *[x];
	for (int i = 0; i < x; i++) {
		mat[i] = new Nodo * [y];
	}
	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			mat[i][j] = new Nodo();
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (i > 0 && j > 0 && i < x - 1 && j < y - 1) {
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
			else if (j + 1 == y) {
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

			if (map[i][j]=='$'|| map[i][j] == '!') {
				J1->PilaContadora.push('$');
			}
			if (map[i][j] == '@') {
				ini = mat[i][j];
			}
			if (map[i][j] == '!') {
				mat[i][j]->setId(map[i][j]);
				mat[i][j]->setPosIniID('.');
			}
			else {
				mat[i][j]->setId(map[i][j]);
				mat[i][j]->setPosIniID(map[i][j]);
			}
		}
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << mat[i][j]->getId() << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "(S) Volver al menu principal" << endl;
	cout << "(G) Guardar Partida" << endl;
	cout << "(R) Reiniciar nivel" << endl;
	cout << "(ESC) SALIR" << endl;

}

void jugador::MenuNivelPasado() {
	system("cls");
	int Op;
	cout << "\t\t\t############# MENU #############\n\n";
	cout << "\t\t\t1- Siguiente Nivel\n";
	cout << "\t\t\t2- Repeticion\n";
	cout << "\t\t\t3- Salir\n\n";
	cin >> Op;
	switch (Op) {
	case 1: {
		nivel++;
		system("cls");
		switch (nivel) {
			case 2: {
				J1->Nivel2();
				break;
			}
			case 3: {
				J1->Nivel3();
				break;
			}
			case 4: {
				J1->Nivel4();
				break;
			}
			case 5: {
				J1->Nivel5();
				break;
			}
			case 6: {
				cout << "Felicidades..." << endl;
				system("pause");
				system("cls");
				nivel = 1;
				J1->MenuInicio();
				break;
			}
		}
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
		J1 = new jugador();
		system("cls");
		J1->Nivel1();
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
	fila = 8;
	Movimientos(8, 6);
}

void jugador::Nivel2()
{
	char map2[9][9] =
	{
		{ '#', '#', '#', '#', '#', ' ', ' ',' ', ' ' },
		{ '#', ' ', ' ', ' ', '#', ' ', ' ',' ', ' ' },
		{ '#', ' ', '$', ' ', '#', ' ', '#','#',  '#' },
		{ '#', ' ', '$', ' ', '#', ' ', '#','.' , '#'},
		{ '#', '#', '#', ' ', '#', '#', '#','.' , '#'},
		{ ' ', '#', '#', ' ', '@', ' ', ' ','.' , '#'},
		{ ' ', '#', ' ', '$', ' ', '#', ' ',' ' , '#'},
		{ ' ', '#', ' ', ' ', ' ', '#', '#','#' , '#'},
		{ ' ', '#', '#', '#', '#', '#', ' ',' ' , ' '}
	};
	J1->crearLista(9, 9);
	cout << "MAPA 2" << endl << endl;
	J1->crearNivel(map2, 9, 9);
	fila = 9;
	Movimientos(8, 7);
}

void jugador::Nivel3()
{
	char map3[8][9] =
	{
		{ ' ', '#', '#', '#', '#', ' ',' ',' ',' '},
		{ '#', '#', ' ', ' ', '#', ' ',' ',' ',' '},
		{ '#', ' ', ' ', '$', '#', ' ',' ',' ',' '},
		{ '#', '#', ' ', '@', '#', '#',' ',' ',' '},
		{ '#', '#', '$', '$', ' ', '#',' ',' ',' '},
		{ '#', '.', '$', ' ', ' ', '#',' ',' ',' '},
		{ '#', '.', '.', '!', '.', '#',' ',' ',' '},
		{ '#', '#', '#', '#', '#', '#',' ',' ',' '}
	};
	J1->crearLista(8, 9);
	cout << "MAPA 3" << endl << endl;
	J1->crearNivel(map3, 8, 9);
	fila = 8;
	Movimientos(6, 5);
}

void jugador::Nivel4()
{
	char map4[8][9] =
	{
		{ ' ', '#', '#', '#', '#', ' ',' ',' ',' '},
		{ ' ', '#', ' ', ' ', '#', '#','#',' ',' '},
		{ ' ', '#', ' ', '@', ' ', ' ','#',' ',' '},
		{ '#', '#', '#', '$', '#', ' ','#','#',' '},
		{ '#', '.', '#', ' ', '#', ' ',' ','#',' '},
		{ '#', '.', '$', ' ', ' ', '#',' ','#',' '},
		{ '#', '.', ' ', ' ', ' ', '$',' ','#',' '},
		{ '#', '#', '#', '#', '#', '#','#','#',' '}
	};
	J1->crearLista(8, 9);
	cout<< "MAPA 4" << endl << endl;
	J1->crearNivel(map4, 8, 9);
	fila = 8;
	Movimientos(6, 4);
}

void jugador::Nivel5()
{
	char map5[7][9] =
	{
		{ ' ', ' ', '#', '#', '#', '#','#','#',' '},
		{ ' ', ' ', '#', ' ', ' ', ' ',' ','#',' '},
		{ '#', '#', '#', '$', '$', '$',' ','#',' '},
		{ '#', '@', ' ', '$', '.', '.',' ','#',' '},
		{ '#', ' ', '$', '.', '.', '.','#','#',' '},
		{ '#', '#', '#', '#', ' ', ' ','#',' ',' '},
		{ ' ', ' ', ' ', '#', '#', '#','#',' ',' '}
	};
	J1->crearLista(7, 9);
	cout << "MAPA 5" << endl << endl;
	J1->crearNivel(map5, 7, 9);
	fila = 7;
	Movimientos(2, 5);
}


void jugador::Movimientos(int X, int Y)
{
#define SALIR 115
#define DOWN 80
#define UP 72
#define RIGTH 77
#define LEFT 75
#define RESTART 114
#define EXIT 27
	int ycont = 0;
	int ContCajas = 0;
	while (1) {
		J1->ini->setX(X);
		J1->ini->setY(Y);
		gotoxy(J1->ini->getX(), J1->ini->getY());
		if (_kbhit()) {
			char tecla = _getch();
			switch (tecla) {
			
			case UP: {
				
				if (J1->ini->getArriba() != NULL) {
					if (J1->ini->getArriba()->getId() == ' ' || J1->ini->getArriba()->getId() == '.') {
						J1->ini = J1->ini->getArriba();
						J1->ini->setId('@');
						if (J1->ini->getAbajo()->getPosIniID() == '.') {
							J1->ini->getAbajo()->setId('.');
						}
						else {
							J1->ini->getAbajo()->setId(' ');
						}

						Y--;
						J1->ini->setX(X);
						J1->ini->setY(Y);
						cout << J1->ini->getAbajo()->getId();
						gotoxy(J1->ini->getX(), J1->ini->getY());
						cout << J1->ini->getId();
					}
					else if (J1->ini->getArriba()->getId() == '$' || J1->ini->getArriba()->getId() == '!') {
						if (J1->ini->getArriba()->getArriba() != NULL) {
							if (J1->ini->getArriba()->getArriba()->getId() == ' ' || J1->ini->getArriba()->getArriba()->getId() == '.') {
								if (J1->ini->getArriba()->getArriba()->getId() == ' ') {
									J1->ini->getArriba()->getArriba()->setId('$');
									
								}
								else {
									J1->ini->getArriba()->getArriba()->setId('!');
									
								}
								J1->ini = J1->ini->getArriba();
								J1->ini->setId('@');
								if (J1->ini->getAbajo()->getPosIniID() == '.') {
									J1->ini->getAbajo()->setId('.');
								}
								else if (J1->ini->getAbajo()->getPosIniID() == ' ') {
									J1->ini->getAbajo()->setId(' ');
								}
								else {
									J1->ini->getAbajo()->setId(' ');
								}
								Y--;
								J1->ini->setX(X);
								J1->ini->setY(Y);

								cout << J1->ini->getAbajo()->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY());
								cout << J1->ini->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY() - 1);
								cout << J1->ini->getArriba()->getId();

							}
						}
					}
				}
				for (int i = 0; i < fila; i++) {
					for (int j = 0; j < 9; j++) {
						if (ContCajas < J1->PilaContadora.size()) {
							if (J1->mat[i][j]->getId() == '!') {
								ContCajas++;
								break;
							}
						}
					}
				}
				for (int i = 0; i < fila; i++) {
					for (int j = 0; j < 9; j++) {
						if (ContCajas > 0) {
							if (J1->mat[i][j]->getId() == '$') {
								ContCajas--;
							}
						}
					}
				}
				if (J1->PilaContadora.size() == ContCajas) {
					J1->MenuNivelPasado();
				}
				break;
			}

			case SALIR: {

				system("cls");
				J1->MenuInicio();

				break;
			}
			case DOWN: {
				
				if (J1->ini->getAbajo() != NULL) {
					if (J1->ini->getAbajo()->getId() == ' ' || J1->ini->getAbajo()->getId() == '.') {
						J1->ini = J1->ini->getAbajo();
						J1->ini->setId('@');
						if (J1->ini->getArriba()->getPosIniID() == '.') {
							J1->ini->getArriba()->setId('.');
						}
						else {
							J1->ini->getArriba()->setId(' ');
						}

						Y++;
						J1->ini->setX(X);
						J1->ini->setY(Y);
						cout << J1->ini->getArriba()->getId();
						gotoxy(J1->ini->getX(), J1->ini->getY());
						cout << J1->ini->getId();
					}
					else if (J1->ini->getAbajo()->getId() == '$' || J1->ini->getAbajo()->getId() == '!') {
						if (J1->ini->getAbajo()->getAbajo() != NULL) {
							if (J1->ini->getAbajo()->getAbajo()->getId() == ' ' || J1->ini->getAbajo()->getAbajo()->getId() == '.') {
								if (J1->ini->getAbajo()->getAbajo()->getId() == ' ') {
									J1->ini->getAbajo()->getAbajo()->setId('$');
									
								}
								else {
									J1->ini->getAbajo()->getAbajo()->setId('!');
									
								}

								if (J1->ini->getPosIniID() == '.') {
									J1->ini->setId('.');
								}
								else if (J1->ini->getPosIniID() == ' ') {
									J1->ini->setId(' ');
								}
								else {
									J1->ini->setId(' ');
								}

								J1->ini = J1->ini->getAbajo();
								J1->ini->setId('@');

								Y++;
								J1->ini->setX(X);
								J1->ini->setY(Y);
								cout << J1->ini->getArriba()->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY());
								cout << J1->ini->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY() + 1);
								cout << J1->ini->getAbajo()->getId();

							}
						}
					}
				}
				for (int i = 0; i < fila; i++) {
					for (int j = 0; j < 9; j++) {
						if (ContCajas < J1->PilaContadora.size()) {
							if (J1->mat[i][j]->getId() == '!') {
								ContCajas++;
								break;
							}
						}
					}
				}
				for (int i = 0; i < fila; i++) {
					for (int j = 0; j < 9; j++) {
						if (ContCajas > 0) {
							if (J1->mat[i][j]->getId() == '$') {
								ContCajas--;
							}
						}
					}
				}
				if (J1->PilaContadora.size() == ContCajas) {
					J1->MenuNivelPasado();
				}
				break;
			}

			case RESTART: {
				system("cls");
				switch (nivel) {
				case 1: {
					J1->Nivel1();
					break;
				}
				case 2: {
					J1->Nivel2();
					break;
				}
				case 3: {
					J1->Nivel3();
					break;
				}
				case 4: {
					J1->Nivel4();
					break;
				}
				case 5: {
					J1->Nivel5();
					break;
				}
				break;
				}

			}
			case EXIT: {
				system("cls");
				exit(1);
				break;
			}
			case RIGTH: {
				
				if (J1->ini->getDerecha() != NULL) {
					if (J1->ini->getDerecha()->getId() == ' ' || J1->ini->getDerecha()->getId() == '.') {
						J1->ini = J1->ini->getDerecha();
						J1->ini->setId('@');
						if (J1->ini->getIzquierda()->getPosIniID() == '.') {
							J1->ini->getIzquierda()->setId('.');
						}
						else {
							J1->ini->getIzquierda()->setId(' ');
						}

						X++;
						X++;
						J1->ini->setX(X);
						J1->ini->setY(Y);
						cout << J1->ini->getIzquierda()->getId();
						gotoxy(J1->ini->getX(), J1->ini->getY());
						cout << J1->ini->getId();

					}
					else if (J1->ini->getDerecha()->getId() == '$' || J1->ini->getDerecha()->getId() == '!') {
						if (J1->ini->getDerecha()->getDerecha() != NULL) {
							if (J1->ini->getDerecha()->getDerecha()->getId() == ' ' || J1->ini->getDerecha()->getDerecha()->getId() == '.') {
								if (J1->ini->getDerecha()->getDerecha()->getId() == '.') {
									J1->ini->getDerecha()->getDerecha()->setId('!');

								}
								else {
									J1->ini->getDerecha()->getDerecha()->setId('$');
								}
								J1->ini = J1->ini->getDerecha();
								J1->ini->setId('@');

								if (J1->ini->getIzquierda()->getPosIniID() == ' ') {
									J1->ini->getIzquierda()->setId(' ');
								}
								else if (J1->ini->getIzquierda()->getPosIniID() == '.') {
									J1->ini->getIzquierda()->setId('.');
								}
								else {
									J1->ini->getIzquierda()->setId(' ');
								}

								X++;
								X++;
								J1->ini->setX(X);
								J1->ini->setY(Y);
								cout << J1->ini->getIzquierda()->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY());
								cout << J1->ini->getId();
								gotoxy(J1->ini->getX() + 2, J1->ini->getY());
								cout << J1->ini->getDerecha()->getId();


							}
						}
					}
				}
				for (int i = 0; i < fila; i++) {
					for (int j = 0; j < 9; j++) {
						if (ContCajas < J1->PilaContadora.size()) {
							if (J1->mat[i][j]->getId() == '!') {
								ContCajas++;
								break;
							}
						}
					}
				}
				for (int i = 0; i < fila; i++) {
					for (int j = 0; j < 9; j++) {
						if (ContCajas > 0) {
							if (J1->mat[i][j]->getId() == '$') {
								ContCajas--;
							}
						}
					}
				}
				if (J1->PilaContadora.size() == ContCajas) {
					J1->MenuNivelPasado();
				}
				break;
			}
			case LEFT: {
				
				if (J1->ini->getIzquierda() != NULL) {
					if (J1->ini->getIzquierda()->getId() == ' ' || J1->ini->getIzquierda()->getId() == '.') {
						J1->ini = J1->ini->getIzquierda();
						J1->ini->setId('@');
						if (J1->ini->getDerecha()->getPosIniID() == '.') {
							J1->ini->getDerecha()->setId('.');
						}
						else {
							J1->ini->getDerecha()->setId(' ');
						}

						X--;
						X--;
						J1->ini->setX(X);
						J1->ini->setY(Y);
						cout << J1->ini->getDerecha()->getId();
						gotoxy(J1->ini->getX(), J1->ini->getY());
						cout << J1->ini->getId();

					}
					else if (J1->ini->getIzquierda()->getId() == '$' || J1->ini->getIzquierda()->getId() == '!') {
						if (J1->ini->getIzquierda()->getIzquierda() != NULL) {
							if (J1->ini->getIzquierda()->getIzquierda()->getId() == ' ' || J1->ini->getIzquierda()->getIzquierda()->getId() == '.') {
								if (J1->ini->getIzquierda()->getIzquierda()->getId() == '.') {
									J1->ini->getIzquierda()->getIzquierda()->setId('!');
								}
								else {
									J1->ini->getIzquierda()->getIzquierda()->setId('$');
								}
								J1->ini = J1->ini->getIzquierda();
								J1->ini->setId('@');

								if (J1->ini->getDerecha()->getPosIniID() == ' ') {
									J1->ini->getDerecha()->setId(' ');
								}
								else if (J1->ini->getDerecha()->getPosIniID() == '.') {
									J1->ini->getDerecha()->setId('.');
								}
								else {
									J1->ini->getDerecha()->setId(' ');
								}

								X--;
								X--;
								J1->ini->setX(X);
								J1->ini->setY(Y);
								cout << J1->ini->getDerecha()->getId();
								gotoxy(J1->ini->getX(), J1->ini->getY());
								cout << J1->ini->getId();
								gotoxy(J1->ini->getX() - 2, J1->ini->getY());
								cout << J1->ini->getIzquierda()->getId();

							}
						}
					}

				}
				for (int i = 0; i < fila; i++) {
					for (int j = 0; j < 9; j++) {
						if (ContCajas < J1->PilaContadora.size()) {
							if (J1->mat[i][j]->getId() == '!') {
								ContCajas++;
								break;
							}
						}
					}
				}
				for (int i = 0; i < fila; i++) {
					for (int j = 0; j < 9; j++) {
						if (ContCajas > 0) {
							if (J1->mat[i][j]->getId() == '$') {
								ContCajas--;
							}
						}
					}
				}
				if (J1->PilaContadora.size() == ContCajas) {
					J1->MenuNivelPasado();
				}
				break;
			}
			default:
				break;
			}

		}

	}
}




