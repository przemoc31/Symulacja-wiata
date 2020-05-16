#include "Wilk.h"

Wilk::Wilk(Swiat* newSwiat, int y, int x, int newWiek)
{
	this->setSila(9);
	this->setInicjatywa(5);
	this->setId('W');
	this->swiat = newSwiat;
	this->setPolozenie_Y(y);
	this->setPolozenie_X(x);
	this->wiek = newWiek;
}
