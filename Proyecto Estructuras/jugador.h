#pragma once
#include "Nodo.h"
#include <iostream>
#include <stack>
using namespace std;
class jugador {

private:
	int nivel = 1;
public:
	Nodo* ini;
	Nodo*** mat;
	jugador();
	stack<char> PilaContadora;
	int fila;
	void crearLista(int x, int y);
	void crearNivel(char map[][9], int x, int y);
	void MenuInicio();
	void MenuNivelPasado();
	void gotoxy(int x, int y);
	void Nivel1();
	void Nivel2();
	void Nivel3();
	void Nivel4();
	void Nivel5();
	void Movimientos(int X, int Y);
};




























