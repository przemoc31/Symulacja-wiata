#include "Owca.h"

Owca::Owca(Swiat* newSwiat, int y, int x, int newWiek)
{
	this->setSila(4);
	this->setInicjatywa(4);
	this->setId('O');
	this->swiat = newSwiat;
	this->setPolozenie_Y(y);
	this->setPolozenie_X(x);
	this->wiek = newWiek;
}
