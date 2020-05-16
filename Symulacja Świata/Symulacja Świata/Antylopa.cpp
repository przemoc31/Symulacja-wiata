#include "Antylopa.h"
#include "Swiat.h"
#include <iostream>
using namespace std;

Antylopa::Antylopa(Swiat* newSwiat, int y, int x, int newWiek)
{
	this->setSila(4);
	this->setInicjatywa(4);
	this->setId('A');
	this->swiat = newSwiat;
	this->setPolozenie_Y(y);
	this->setPolozenie_X(x);
	this->wiek = newWiek;
}
void Antylopa::akcja()
{
	int old_Y = this->getPolozenie_Y();
	int old_X = this->getPolozenie_X();
	cout << this->getId() << ": " << this->getPolozenie_Y() << " " << this->getPolozenie_X() << " -> ";

	while (true)
	{
		int x = rand() % 4;
		if (x == 0)
		{
			if (this->polozenie_Y + 2 < this->swiat->getSize_Y())
			{
				this->setPolozenie_Y(this->polozenie_Y + 2);
				break;
			}							
		}
		else if (x == 1)
		{
			if (this->polozenie_Y - 2 > 0)
			{
				this->setPolozenie_Y(this->polozenie_Y - 2);
				break;
			}			
		}
		else if (x == 2)
		{
			if (this->polozenie_X + 2 < this->swiat->getSize_X())
			{
				this->setPolozenie_X(this->polozenie_X + 2);
				break;
			}
		}
		else
		{
			if (this->polozenie_X - 2 > 0)
			{
				this->setPolozenie_X(this->polozenie_X - 2);
				break;
			}
		}
	}
	cout << this->getPolozenie_Y() << " " << this->getPolozenie_X() << endl;

	if (this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X) != NULL)
		this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X)->kolizja(this, old_Y, old_X);
}
void Antylopa::kolizja(Organizm* attacker, int old_Y, int old_X)
{
	int x = rand() % 2;
	if (x)
		Zwierze::kolizja(attacker, old_Y, old_X);
	else
	{
		cout << attacker->getId() << " zaatakowal " << this->id << endl;
		bool tab[4] = { true, true, true, true };
		while (true)
		{
			int x = rand() % 4;
			if (x == 0 && tab[0] == true)
			{
				if ((this->polozenie_Y + 1 < this->swiat->getSize_Y()) && (this->swiat->getOrgMap(this->polozenie_Y + 1, this->polozenie_X) == NULL))
				{
					this->setPolozenie_Y(this->polozenie_Y + 1);
					cout << this->id << " ucieka na pole " << this->polozenie_Y << " " << this->polozenie_X << endl;
					this->swiat->ustawOrganizm(this, this->polozenie_Y, this->polozenie_X);
					break;
				}
				else
				{
					tab[x] = false;
				}
			}
			else if (x == 1 && tab[1] == true)
			{
				if ((this->polozenie_Y - 1 > 0) && (this->swiat->getOrgMap(this->polozenie_Y - 1, this->polozenie_X) == NULL))
				{
					this->setPolozenie_Y(this->polozenie_Y - 1);
					cout << this->id << " ucieka na pole " << this->polozenie_Y << " " << this->polozenie_X << endl;
					this->swiat->ustawOrganizm(this, this->polozenie_Y, this->polozenie_X);
					break;
				}
				else
				{
					tab[x] = false;
				}
			}
			else if (x == 2 && tab[2] == true)
			{
				if ((this->polozenie_X + 1 < this->swiat->getSize_X()) && (this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X + 1) == NULL))
				{
					this->setPolozenie_X(this->polozenie_X + 1);
					cout << this->id << " ucieka na pole " << this->polozenie_Y << " " << this->polozenie_X << endl;
					this->swiat->ustawOrganizm(this, this->polozenie_Y, this->polozenie_X);
					break;
				}
				else
				{
					tab[x] = false;
				}
			}
			else if (x == 3 && tab[3] == true)
			{
				if ((this->polozenie_X - 1 > 0) && (this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X - 1) == NULL))
				{
					this->setPolozenie_X(this->polozenie_X - 1);
					cout << this->id << " ucieka na pole " << this->polozenie_Y << " " << this->polozenie_X << endl;
					this->swiat->ustawOrganizm(this, this->polozenie_Y, this->polozenie_X);
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
				{
					Zwierze::kolizja(attacker, old_Y, old_X);
					break;
				}
					
			}
		}
	}

}