#include "Jagody.h"
#include "Swiat.h"
#include <iostream>
using namespace std;

Jagody::Jagody(Swiat* newSwiat, int y, int x, int newWiek)
{
	this->setSila(99);
	this->setInicjatywa(0);
	this->setId('J');
	this->swiat = newSwiat;
	this->setPolozenie_Y(y);
	this->setPolozenie_X(x);
	this->wiek = newWiek;
}

void Jagody::akcja()
{

}
void Jagody::kolizja(Organizm* attacker, int old_Y, int old_X)
{
	cout << attacker->getId() << " zjada " << this->id << endl;
	cout << this->id << " zabija " << attacker->getId() << endl;
	int thisY = this->polozenie_Y;
	int thisX = this->polozenie_X;
	attacker->setPolozenie_Y(old_Y);
	attacker->setPolozenie_X(old_X);
	this->swiat->zabijOrganizm(thisY, thisX);
	this->swiat->zabijOrganizm(old_Y, old_X);
}