// Proyecto Estructuras.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>
#include "jugador.h"
#include "Nodo.h"
#include <conio.h>
using namespace std;

int main()
{
	jugador* j = new jugador();
	j->MenuInicio();
/*	char map[8][8] =
	{
		{ '#', '#', '#', '#', '#', '#', '#','#' },
		{ '#', '@', ' ', ' ', ' ', ' ', ' ','#' },
		{ '#', ' ', ' ', ' ', ' ', ' ', ' ','#' },
		{ '#', ' ', ' ', ' ', ' ', ' ', ' ','#' },
		{ '#', ' ', ' ', ' ', ' ', ' ', ' ','#' },
		{ '#', ' ', ' ', ' ', ' ', ' ', ' ','#' },
		{ '#', ' ', ' ', ' ', ' ', ' ', ' ','#' },
		{ '#', '#', '#', '#', '#', '#', '#','#' }
	};
/*
	int x = 1, y = 1;
	while (1) {

		if (GetAsyncKeyState(VK_DOWN)) {
			/*system("cls");
			gotoxy(x,y);
			cout << "@" << endl;
			gotoxy(0, 0);
			matriz();
			x--; */
	/*
			if (x < 6) {
				system("cls");
				map[x + 1][y] = map[x][y];
				map[x][y] = ' ';
				x++;
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						cout << map[i][j] << " ";
					}
					cout << endl;
				}
			}
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (y < 6) {
				system("cls");
				map[x][y + 1] = map[x][y];
				map[x][y] = ' ';
				y++;
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						cout << map[i][j] << " ";
					}
					cout << endl;
				}
			}
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			if (y > 1) {
				system("cls");
				map[x][y - 1] = map[x][y];
				map[x][y] = ' ';
				y--;
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						cout << map[i][j] << " ";
					}
					cout << endl;
				}
			}
		}
		if (GetAsyncKeyState(VK_UP)) {
			if (x > 1) {
				system("cls");
				map[x - 1][y] = map[x][y];
				map[x][y] = ' ';
				x--;
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						cout << map[i][j] << " ";
					}
					cout << endl;
				}
			}
		}
	}*/
	/*
	char map2[9][9] =
	{
		{ '#', '#', '#', '#', '#', ' ', ' ',' ', ' ' },
		{ '#', ' ', ' ', '.', '#', ' ', ' ',' ', ' ' },
		{ '#', ' ', '$', ' ', '#', ' ', '#','#',  '#' },
		{ '#', ' ', '$', ' ', '#', ' ', '#','.' , '#'},
		{ '#', '#', '#', ' ', '#', '#', '#','.' , '#'},
		{ ' ', '#', '#', ' ', '@', ' ', ' ','.' , '#'},
		{ ' ', '#', ' ', '$', ' ', '#', ' ',' ' , '#'},
		{ ' ', '#', ' ', ' ', ' ', '#', '#','#' , '#'},
		{ ' ', '#', '#', '#', '#', '#', ' ',' ' , ' '}
	};

	char map3[8][9] =
	{
		{ ' ', '#', '#', '#', '#', ' ',' ',' ',' '},
		{ '#', '#', ' ', '.', '#', ' ',' ',' ',' '},
		{ '#', ' ', ' ', '$', '#', ' ',' ',' ',' '},
		{ '#', '#', ' ', '@', '#', '#',' ',' ',' '},
		{ '#', '#', '$', '$', ' ', '#',' ',' ',' '},
		{ '#', '.', '$', ' ', ' ', '#',' ',' ',' '},
		{ '#', '.', '.', '!', '.', '#',' ',' ',' '},
		{ '#', '#', '#', '#', '#', '#',' ',' ',' '}
	};

	char map4[8][9] =
	{
		{ ' ', '#', '#', '#', '#', ' ',' ',' ',' '},
		{ ' ', '#', ' ', ' ', '#', '#','#',' ',' '},
		{ ' ', '#', ' ', '@', ' ', ' ','#',' ',' '},
		{ '#', '#', '#', '$', '#', '#','#','#',' '},
		{ '#', '.', '#', '$', '#', ' ',' ','#',' '},
		{ '#', '.', '$', ' ', ' ', '#',' ','#',' '},
		{ '#', '.', '.', '!', '.', '$',' ','#',' '},
		{ '#', '#', '#', '#', '#', '#','#','#',' '}
	};

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
	
	/*cout << endl << endl;
	cout << "MAPA 2" << endl << endl;

	Carlos->crearLista(9, 9);
	Carlos->crearNivel(map2, 9, 9);
	

	cout << endl << endl;
	cout << "MAPA 3" << endl << endl;

	Carlos->crearLista(8, 9);
	Carlos->crearNivel(map3, 8, 9);


	cout << endl << endl;
	cout << "MAPA 4" << endl << endl;

	Carlos->crearLista(8, 9);
	Carlos->crearNivel(map4, 8, 9);

	cout << endl << endl;
	cout << "MAPA 5" << endl << endl;

	Carlos->crearLista(7, 9);
	Carlos->crearNivel(map5, 7, 9);
	jugador* Jordi = new jugador();*/
	
	//return 0;
}


