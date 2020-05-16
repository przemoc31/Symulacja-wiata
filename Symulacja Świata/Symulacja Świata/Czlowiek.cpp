#pragma warning(disable : 4996)
#include "Czlowiek.h"
#include "Swiat.h"
#include <iostream>
#include <conio.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Czlowiek::Czlowiek(Swiat* newSwiat, int y, int x, int newWiek)
{
	this->setSila(5);
	this->setInicjatywa(4);
	this->setId('C');
	this->swiat = newSwiat;
	this->setPolozenie_Y(y);
	this->setPolozenie_X(x);
	this->wiek = newWiek;
}
void Czlowiek::akcja()
{
    cout << "Tura czlowieka, rusz sie: ";
    int old_Y = this->getPolozenie_Y();
    int old_X = this->getPolozenie_X();
    cout << this->getId() << ": " << this->getPolozenie_Y() << " " << this->getPolozenie_X() << " -> ";
    int key;
    key = getch();
    while (!(key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT))
        key = getch();

        switch (key) {
        case KEY_UP:
            if (this->polozenie_Y - 1 < 0)
                this->setPolozenie_Y(this->polozenie_Y + 1);
            else
                this->setPolozenie_Y(this->polozenie_Y - 1);
            break;
        case KEY_DOWN:
            if (this->polozenie_Y + 1 == this->swiat->getSize_Y())
                this->setPolozenie_Y(this->polozenie_Y - 1);
            else
                this->setPolozenie_Y(this->polozenie_Y + 1);
            break;
        case KEY_LEFT:
            if (this->polozenie_X - 1 < 0)
                this->setPolozenie_X(this->polozenie_X + 1);
            else
                this->setPolozenie_X(this->polozenie_X - 1);
            break;
        case KEY_RIGHT:
            if (this->polozenie_X + 1 == this->swiat->getSize_X())
                this->setPolozenie_X(this->polozenie_X - 1);
            else
                this->setPolozenie_X(this->polozenie_X + 1);
            break;
        default:
            cout << endl << "bad input, you lost a round" << endl;  // not arrow
            break;
        }  	
        cout << this->getPolozenie_Y() << " " << this->getPolozenie_X() << endl;

        if (this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X) != NULL)
            this->swiat->getOrgMap(this->polozenie_Y, this->polozenie_X)->kolizja(this, old_Y, old_X);
}
void Czlowiek::kolizja(Organizm* attacker, int old_Y, int old_X)
{
	Zwierze::kolizja(attacker, old_Y, old_X);

}