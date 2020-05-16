#include "Mlecz.h"

Mlecz::Mlecz(Swiat* newSwiat, int y, int x, int newWiek)
{
	this->setSila(0);
	this->setInicjatywa(0);
	this->setId('M');
	this->swiat = newSwiat;
	this->setPolozenie_Y(y);
	this->setPolozenie_X(x);
	this->wiek = newWiek;
}

void Mlecz::akcja()
{

}