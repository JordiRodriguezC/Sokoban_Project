#include "Nodo.h"
#include <iostream>
using namespace std;
Nodo::Nodo() {
	x=0, y = 0;
	Derecha = NULL;
	Izquierda = NULL;
	Arriba = NULL;
	Abajo = NULL;
	

}
void Nodo::setId(char id) {
	this->id = id;
}
void Nodo::setX(int x) {
	this->x = x;
}
void Nodo::setY(int y) {
	this->y = y;
}
void Nodo::setDerecha(Nodo* Derecha) {
	this->Derecha = Derecha;
}
void Nodo::setArriba(Nodo* Arriba) {
	this->Arriba = Arriba;
}
void Nodo::setIzquierda(Nodo* Izquierda) {
	this->Izquierda = Izquierda;
}
void Nodo::setAbajo(Nodo* Abajo) {
	this->Abajo = Abajo;
}

char Nodo::getId() {
	return id;
}
int Nodo::getX() {
	return x;
}
int Nodo::getY() {
	return y;
}
Nodo* Nodo::getAbajo() {
	return Abajo;
}
Nodo* Nodo::getArriba() {
	return Arriba;
}
Nodo* Nodo::getDerecha() {
	return Derecha;
}
Nodo* Nodo::getIzquierda() {
	return Izquierda;
}
