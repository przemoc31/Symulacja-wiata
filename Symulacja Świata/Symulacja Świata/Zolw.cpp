#include "Zolw.h"
#include <iostream>
using namespace std;

Zolw::Zolw(Swiat* newSwiat, int y, int x, int newWiek)
{
	this->setSila(2);
	this->setInicjatywa(1);
	this->setId('Z');
	this->swiat = newSwiat;
	this->setPolozenie_Y(y);
	this->setPolozenie_X(x);
	this->wiek = newWiek;
}
void Zolw::akcja()
{
	int y = rand() % 4;
	if (y == 3)
		Zwierze::akcja();
	else
		cout << this->getId() << ": " << this->getPolozenie_Y() << " " << this->getPolozenie_X() << " -> "<< this->getPolozenie_Y() << " " << this->getPolozenie_X() << endl;
		
}
void Zolw::kolizja(Organizm* attacker, int old_Y, int old_X)
{
	if (attacker->getSila() < 5)
	{
		cout << attacker->getId() << " zaatakowal " << this->id << endl;
		attacker->setPolozenie_Y(old_Y);
		attacker->setPolozenie_X(old_X);
		cout << this->id << " odepchnal "<< attacker->getId() <<" na jego stare pole "<<old_Y <<" "<< old_X << endl;
	}
	else
	{
		Zwierze::kolizja(attacker, old_Y, old_X);
	}
}