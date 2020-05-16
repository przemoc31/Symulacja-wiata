#include "Guarana.h"
#include <iostream>
using namespace std;

Guarana::Guarana(Swiat* newSwiat, int y, int x, int newWiek)
{
	this->setSila(0);
	this->setInicjatywa(0);
	this->setId('G');
	this->swiat = newSwiat;
	this->setPolozenie_Y(y);
	this->setPolozenie_X(x);
	this->wiek = newWiek;
}

void Guarana::akcja()
{

}
void Guarana::kolizja(Organizm* attacker, int old_Y, int old_X)
{
	attacker->setSila(attacker->getSila() + 3);
	Roslina::kolizja(attacker, old_Y, old_X);
	cout << this->id << " dodaje 3 sily " << attacker->getId() << " dzieki czemu ma " << attacker->getSila() << " sily" << endl;
}