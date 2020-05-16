#include "Roslina.h"
#include "Swiat.h"
#include <iostream>
using namespace std;

int Roslina::getPolozenie_X() { return this->polozenie_X; }
int Roslina::getPolozenie_Y() { return this->polozenie_Y; }
int Roslina::getSila() { return this->sila; }
int Roslina::getInicjatywa() { return this->inicjatywa; }
char Roslina::getId() { return this->id; }
int Roslina::getWiek() { return this->wiek; }
void Roslina::setPolozenie_X(int newX) { this->polozenie_X = newX; }
void Roslina::setPolozenie_Y(int newY) { this->polozenie_Y = newY; }
void Roslina::setSila(int newSila) { this->sila = newSila; }
void Roslina::setInicjatywa(int newInicjatywa) { this->inicjatywa = newInicjatywa; }
void Roslina::setId(char newId) { this->id = newId; }
void Roslina::setWiek(int newWiek) { this->wiek = newWiek; }
void Roslina::rysuj(int polozenie_Y, int polozenie_X)
{
	this->swiat->setMap(polozenie_Y, polozenie_X, this->getId());
}
void Roslina::akcja()
{
	
}
void Roslina::kolizja(Organizm* attacker, int old_Y, int old_X)
{
	cout << attacker->getId() << " zjada " << this->id << endl;
	int thisY = this->polozenie_Y;
	int thisX = this->polozenie_X;
	attacker->setPolozenie_Y(old_Y);
	attacker->setPolozenie_X(old_X);
	this->swiat->zabijOrganizm(thisY, thisX);
	attacker->setPolozenie_Y(thisY);
	attacker->setPolozenie_X(thisX);
}