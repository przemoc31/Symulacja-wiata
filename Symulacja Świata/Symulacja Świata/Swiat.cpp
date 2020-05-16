#include "Swiat.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Jagody.h"
#include "Barszcz.h"
#include "Wilk.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Owca.h"
#include "Czlowiek.h"
#include <iostream>
using namespace std;

Swiat::Swiat(int n, int m)
{
	srand(time(NULL));

	this->orgMap = new Organizm** [n];
	this->map = new char* [n];
	this->size_X = m;
	this->size_Y = n;
	for (int i = 0; i < n; i++)
	{
		this->map[i] = new char [m];
		this->orgMap[i] = new Organizm* [m];
		for (int j = 0; j < m; j++)
		{
			map[i][j] = NULL;
			orgMap[i][j] = NULL;
		}
			
	}	
}
int Swiat::getSize_X() { return size_X; }
int Swiat::getSize_Y() { return size_Y; }
char Swiat::getMap(int y, int x)
{
	return this->map[y][x];
}
Organizm* Swiat::getOrgMap(int y, int x)
{
	return this->orgMap[y][x];
}
void Swiat::setMap(int y, int x, char znak)
{
	this->map[y][x] = znak;
}
void Swiat::setOrgMap(int y, int x, Organizm* newOrg)
{
	this->orgMap[y][x] = newOrg;
}
vector<Organizm*> Swiat::sortObjects(vector<Organizm*> objects)
{
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = 0; j < objects.size(); j++)
		{
			if (objects[i]->getInicjatywa() > objects[j]->getInicjatywa())
				swap(objects[i], objects[j]);
			else if ((objects[i]->getInicjatywa() == objects[j]->getInicjatywa()) && (objects[i]->getWiek() > objects[j]->getWiek()))
				swap(objects[i], objects[j]);
		}
	}
	cout << "sorted: ";
	for (int i = 0; i < objects.size(); i++)
	{
		cout << objects[i]->getId() << " ";
	}
	cout << endl;
	return objects;
}
void Swiat::wykonajTure()
{
	/*for (int i = 0; i < this->size_Y; i++)
	{
		for (int j = 0; j < this->size_X; j++)
		{
			if (orgMap[i][j] != NULL)
			{
				orgMap[i][j]->wykonano = true;
			}
		}
	}
	for (int i = 0; i < this->size_Y; i++)
	{
		for (int j = 0; j < this->size_X; j++)
		{
			if (orgMap[i][j] != NULL && orgMap[i][j]->wykonano == true)
			{
				orgMap[i][j]->wykonano = false;
				this->orgMap[i][j]->akcja();
				ustawOrganizm(orgMap[i][j], orgMap[i][j]->getPolozenie_Y(), orgMap[i][j]->getPolozenie_X());
				if(i != orgMap[i][j]->getPolozenie_Y() || j != orgMap[i][j]->getPolozenie_X())
					usunOrganizm(i, j);				
			}
		}	
	}	*/
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i] != NULL)
		{
			int old_Y = objects[i]->getPolozenie_Y();
			int old_X = objects[i]->getPolozenie_X();
			this->objects[i]->akcja();
			if (objects[i] != NULL)
			{
				ustawOrganizm(objects[i], objects[i]->getPolozenie_Y(), objects[i]->getPolozenie_X());
				if ((objects[i]->getPolozenie_Y() != old_Y) || (objects[i]->getPolozenie_X() != old_X))
					usunOrganizm(old_Y, old_X);
			}			
		}		
	}
}
void Swiat::rysujSwiat()
{
	for (int i = -1; i < (this->size_Y + 1); i++)
	{
		for (int j = -1; j < (this->size_X + 1); j++)
		{
			if ((i == -1 || i == this->size_Y) || (j == -1 || j == this->size_X))
				cout << "#";
			else
				cout << this->getMap(i, j);
		}
		cout << endl;
	}
}
void Swiat::ustawOrganizm(Organizm* organizm, int y, int x)
{
	organizm->rysuj(y, x);
	setOrgMap(y, x, organizm);
}
void Swiat::usunOrganizm(int y, int x)
{
	this->setOrgMap(y, x, NULL);
	this->setMap(y, x, NULL);
}
void Swiat::zabijOrganizm(int y, int x)
{
	usunOrganizm(y, x);
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->getPolozenie_Y() == y && objects[i]->getPolozenie_X() == x)
		{
			objects[i] = NULL;
			break;
		}			
	}
}
vector<Organizm*> Swiat::cleanObjects(vector<Organizm*> objects)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i] == NULL)
		{
			objects.erase(objects.begin() + i);
			i--;
		}
	}
	return objects;
}
void Swiat::start()
{
	objects.push_back(new Trawa(this, 1, 1, 0));
	objects.push_back(new Guarana(this, 2, 2, 0));
	objects.push_back(new Mlecz(this, 2, 3, 0));
	objects.push_back(new Jagody(this, 3, 2, 0));
	objects.push_back(new Barszcz(this, 3, 3, 0));
	objects.push_back(new Wilk(this, 4, 0, 1));
	objects.push_back(new Antylopa(this, 0, 0, 2));
	objects.push_back(new Zolw(this, 0, 7, 3));
	objects.push_back(new Owca(this, 1, 8, 4));
	objects.push_back(new Lis(this, 4, 6, 5));
	objects.push_back(new Czlowiek(this, 5, 11, 6));
	for (int i = 0; i < 11; i++)
		ustawOrganizm(objects[i], objects[i]->getPolozenie_Y(), objects[i]->getPolozenie_X());
	while (true)
	{
		rysujSwiat();
		objects = sortObjects(objects);
		char key = ' ';
		key = getchar();
		if (key == '\n')
		{
			this->wykonajTure();
			objects = cleanObjects(objects);
		}
		
	}
}
Swiat::~Swiat()
{
	delete[](map);
	delete[](orgMap);
}