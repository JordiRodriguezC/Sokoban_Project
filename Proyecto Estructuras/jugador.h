#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;
class jugador {

private:
	
public:
	Nodo* ini;
	Nodo*** mat;
	jugador();
	void crearLista(int x, int y);
	void crearNivel(char map[][9],int x, int y);
	void MenuInicio();
	void gotoxy(int x, int y);
	void Nivel1();
	void Nivel2();
	void Movimientos(int X, int Y);
};




























