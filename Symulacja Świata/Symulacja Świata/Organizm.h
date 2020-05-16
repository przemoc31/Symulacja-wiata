#pragma once
#include <ctime>
#include <random>
class Swiat;

class Organizm
{
public:
	virtual int getPolozenie_X() = 0;
	virtual int getPolozenie_Y() = 0;
	virtual int getSila() = 0;
	virtual int getInicjatywa() = 0;
	virtual char getId() = 0;
	virtual int getWiek() = 0;
	virtual void setPolozenie_X(int newX) = 0;
	virtual void setPolozenie_Y(int newY) = 0;
	virtual void setSila(int newSila) = 0;
	virtual void setInicjatywa(int newInicjatywa) = 0;
	virtual void setId(char newId) = 0;
	virtual void setWiek(int newWiek) = 0;
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* attacker, int old_Y, int old_X) = 0;
	virtual void rysuj(int polozenie_Y, int polozenie_X) = 0;
protected:
	int sila;
	int inicjatywa;
	char id;
	int polozenie_X;
	int polozenie_Y;
	int wiek;
	Swiat* swiat;
};

