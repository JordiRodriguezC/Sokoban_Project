#pragma once
using namespace std;
class Nodo {

private:
	char id;
	char PosId;
	int x, y;
	Nodo* Derecha;
	Nodo* Izquierda;
	Nodo* Arriba;
	Nodo* Abajo;
	
public:
	Nodo();
	void setId(char id);
	char getId();
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	void setDerecha(Nodo* Derecha);
	Nodo *getDerecha();
	void setIzquierda(Nodo* Izquierda);
	Nodo *getIzquierda();
	void setArriba(Nodo* Arriba);
	Nodo *getArriba();
	void setAbajo(Nodo* Abajo);
	Nodo *getAbajo();
	void setPosIniID(char ID);
	char getPosIniID();
};