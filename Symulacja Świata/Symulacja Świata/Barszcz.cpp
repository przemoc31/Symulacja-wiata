#include "Barszcz.h"
#include "Zwierze.h"
#include "Swiat.h"
#include <iostream>
using namespace std;

Barszcz::Barszcz(Swiat* newSwiat, int y, int x, int newWiek)
{
	this->setSila(10);
	this->setInicjatywa(0);
	this->setId('B');
	this->swiat = newSwiat;
	this->setPolozenie_Y(y);
	this->setPolozenie_X(x);
	this->wiek = newWiek;
}

void Barszcz::akcja()
{
	if (this->getPolozenie_Y() + 1 < this->swiat->getSize_Y())
	{
		if (dynamic_cast<Zwierze*>(this->swiat->getOrgMap(this->getPolozenie_Y() + 1, this->getPolozenie_X())) != nullptr)
		{
			cout << "Barszcz zabija " << this->swiat->getOrgMap(this->getPolozenie_Y() + 1, this->getPolozenie_X())->getId() << endl;
			this->swiat->setMap(this->getPolozenie_Y() + 1, this->getPolozenie_X(), NULL);
			this->swiat->zabijOrganizm(this->getPolozenie_Y() + 1, this->getPolozenie_X());			
		}
	}
	if (this->getPolozenie_Y() - 1 >= 0)
	{
		if (dynamic_cast<Zwierze*>(this->swiat->getOrgMap(this->getPolozenie_Y() - 1, this->getPolozenie_X())) != nullptr)
		{
			cout << "Barszcz zabija " << this->swiat->getOrgMap(this->getPolozenie_Y() - 1, this->getPolozenie_X())->getId() << endl;
			this->swiat->setMap(this->getPolozenie_Y() - 1, this->getPolozenie_X(), NULL);
			this->swiat->zabijOrganizm(this->getPolozenie_Y() - 1, this->getPolozenie_X());
		}
	}
	if (this->getPolozenie_X() + 1 < this->swiat->getSize_X())
	{
		if (dynamic_cast<Zwierze*>(this->swiat->getOrgMap(this->getPolozenie_Y(), this->getPolozenie_X() + 1)) != nullptr)
		{
			cout << "Barszcz zabija " << this->swiat->getOrgMap(this->getPolozenie_Y(), this->getPolozenie_X() + 1)->getId() << endl;
			this->swiat->setMap(this->getPolozenie_Y(), this->getPolozenie_X() + 1, NULL);
			this->swiat->zabijOrganizm(this->getPolozenie_Y(), this->getPolozenie_X() + 1);
		}
	}
	if (this->getPolozenie_X() - 1 >= 0)
	{
		if (dynamic_cast<Zwierze*>(this->swiat->getOrgMap(this->getPolozenie_Y(), this->getPolozenie_X() - 1)) != nullptr)
		{
			cout << "Barszcz zabija " << this->swiat->getOrgMap(this->getPolozenie_Y(), this->getPolozenie_X() - 1)->getId() << endl;
			this->swiat->setMap(this->getPolozenie_Y(), this->getPolozenie_X() - 1, NULL);
			this->swiat->zabijOrganizm(this->getPolozenie_Y(), this->getPolozenie_X() - 1);
		}
	}	
	cout << this->getId() << ": " << this->getPolozenie_Y() << " " << this->getPolozenie_X() << endl;
}
void Barszcz::kolizja(Organizm* attacker, int old_Y, int old_X)
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