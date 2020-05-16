#include "Zwierze.h"
#include "Swiat.h"
#include <iostream>
using namespace std;

int Zwierze::getPolozenie_X() { return this->polozenie_X; }
int Zwierze::getPolozenie_Y() { return this->polozenie_Y; }
int Zwierze::getSila() { return this->sila; }
int Zwierze::getInicjatywa() { return this->inicjatywa; }
char Zwierze::getId() { return this->id; }
int Zwierze::getWiek() { return this->wiek; }
void Zwierze::setPolozenie_X(int newX) { this->polozenie_X = newX; }
void Zwierze::setPolozenie_Y(int newY) { this->polozenie_Y = newY; }
void Zwierze::setSila(int newSila) { this->sila = newSila; }
void Zwierze::setInicjatywa(int newInicjatywa) { this->inicjatywa = newInicjatywa; }
void Zwierze::setId(char newId) { this->id = newId; }
void Zwierze::setWiek(int newWiek) { this->wiek = newWiek; }
void Zwierze::rysuj(int polozenie_Y, int polozenie_X)
{
	this->swiat->setMap(polozenie_Y, polozenie_X, this->getId());
}
void Zwierze::akcja()
{
	int old_Y = this->getPolozenie_Y();
	int old_X = this->getPolozenie_X();
	cout << this->getId() << ": " << this->getPolozenie_Y() << " " << this->getPolozenie_X() << " -> ";

	int x = rand() % 4;
	if (x == 0)
	{
		if(this->polozenie_Y + 1 == this->swiat->getSize_Y())
			this->setPolozenie_Y(this->polozenie_Y - 1);
		else
			this->setPolozenie_Y(this->polozenie_Y + 1);
	}		
	else if (x == 1)
	{
		if (this->polozenie_Y - 1 < 0)
			this->setPolozenie_Y(this->polozenie_Y + 1);
		else
			this->setPolozenie_Y(this->polozenie_Y - 1);
	}
	else if (x == 2)
	{
		if (this->polozenie_X + 1 == this->swiat->getSize_X())
			this->setPolozenie_X(this->polozenie_X - 1);
		else
			this->setPolozenie_X(this->polozenie_X + 1);
	}		
	else
	{
		if (this->polozenie_X - 1 < 0)
			this->setPolozenie_X(this->polozenie_X + 1);			
		else
			this->setPolozenie_X(this->polozenie_X - 1);
	}
	cout << this->getPolozenie_Y() << " " << this->getPolozenie_X() <<endl;

	if (this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X) != NULL)
		this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X)->kolizja(this, old_Y, old_X);
}
void Zwierze::kolizja(Organizm* attacker, int old_Y, int old_X)
{
	if (this->sila > attacker->getSila())
	{
		cout << this->id << " zabija " << attacker->getId() << endl;
		attacker->setPolozenie_Y(old_Y);
		attacker->setPolozenie_X(old_X);
		this->swiat->zabijOrganizm(old_Y, old_X);
	}
	else
	{
		cout << attacker->getId() << " zabija " << this->id << endl;
		int thisY = this->polozenie_Y;
		int thisX = this->polozenie_X;
		attacker->setPolozenie_Y(old_Y);
		attacker->setPolozenie_X(old_X);
		this->swiat->zabijOrganizm(thisY, thisX);
		attacker->setPolozenie_Y(thisY);
		attacker->setPolozenie_X(thisX);
	}
		
}