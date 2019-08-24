#pragma once
#include "Nodo.h"
#include <iostream>
#include <stack>
#include <vector> 
#include<stdio.h>
#include<stdlib.h>

using namespace std;
class jugador {

private:
	int nivel = 1;
public:
	Nodo* ini;
	Nodo*** mat;
	jugador();
	stack<char> PilaContadora;
	vector <char> vector;
	int fila;
	void crearLista(int x, int y);
	void crearNivel(char map[][9], int x, int y);
	void MenuInicio();
	void MenuNivelPasado();
	void gotoxy(int x, int y);
	void Nivel1(bool repeticion);
	void Nivel2(bool repeticion);
	void Nivel3(bool repeticion);
	void Nivel4(bool repeticion);
	void Nivel5(bool repeticion);
	void Movimientos(int X, int Y);
	void repeticion(int X,int Y);
};




























