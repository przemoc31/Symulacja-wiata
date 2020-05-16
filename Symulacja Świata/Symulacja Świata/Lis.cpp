#include "Lis.h"
#include "Swiat.h"
#include <iostream>
using namespace std;

Lis::Lis(Swiat* newSwiat, int y, int x, int newWiek)
{
	this->setSila(3);
	this->setInicjatywa(7);
	this->setId('L');
	this->swiat = newSwiat;
	this->setPolozenie_Y(y);
	this->setPolozenie_X(x);
	this->wiek = newWiek;
}
void Lis::akcja()
{
	int old_Y = this->getPolozenie_Y();
	int old_X = this->getPolozenie_X();
	cout << this->getId() << ": " << this->getPolozenie_Y() << " " << this->getPolozenie_X() << " -> ";
	bool tab[4] = { true, true, true, true };
	while (true)
	{
		int x = rand() % 4;
		if (x == 0 && tab[0] == true)
		{
			if ((this->polozenie_Y + 1 < this->swiat->getSize_Y()) && (((this->swiat->getOrgMap(this->polozenie_Y + 1, this->polozenie_X) == NULL) || this->getSila() >= this->swiat->getOrgMap(this->polozenie_Y + 1, this->polozenie_X)->getSila())))
			{
				this->setPolozenie_Y(this->polozenie_Y + 1);
				break;
			}
			else
			{
				tab[x] = false;
			}
		}
		else if (x == 1 && tab[1] == true)
		{
			if ((this->polozenie_Y - 1 > 0) && (((this->swiat->getOrgMap(this->polozenie_Y - 1, this->polozenie_X) == NULL) || this->getSila() >= this->swiat->getOrgMap(this->polozenie_Y - 1, this->polozenie_X)->getSila())))
			{
				this->setPolozenie_Y(this->polozenie_Y - 1);
				break;
			}
			else
			{
				tab[x] = false;
			}
		}
		else if (x == 2 && tab[2] == true)
		{
			if ((this->polozenie_X + 1 < this->swiat->getSize_X()) && (((this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X + 1) == NULL) || this->getSila() >= this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X + 1)->getSila())))
			{
				this->setPolozenie_X(this->polozenie_X + 1);
				break;
			}
			else
			{
				tab[x] = false;
			}
		}
		else if (x == 3 && tab[3] == true)
		{
			if ((this->polozenie_X - 1 > 0) && (((this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X - 1) == NULL) || this->getSila() >= this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X - 1)->getSila())))
			{
				this->setPolozenie_X(this->polozenie_X - 1);
				break;
			}
			else
			{
				tab[x] = false;
			}
		}
		else
		{
			if (!tab[0] && !tab[1] && !tab[2] && !tab[3])
				break;
		}
	}
	cout << this->getPolozenie_Y() << " " << this->getPolozenie_X() << endl;
	if (this->getPolozenie_Y() != old_Y || this->getPolozenie_Y() != old_X)
	{
		if (this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X) != NULL)
			this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X)->kolizja(this, old_Y, old_X);
	}	
}