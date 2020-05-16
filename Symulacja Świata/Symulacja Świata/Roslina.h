#pragma once
#include "Organizm.h"
class Roslina :
	public Organizm
{
public:
	int getPolozenie_X() override;
	int getPolozenie_Y() override;
	int getSila() override;
	int getInicjatywa() override;
	char getId() override;
	int getWiek() override;
	void setPolozenie_X(int newX) override;
	void setPolozenie_Y(int newY) override;
	void setSila(int newSila) override;
	void setInicjatywa(int newInicjatywa) override;
	void setId(char newId) override;
	void setWiek(int newWiek) override;
	void rysuj(int polozenie_Y, int polozenie_X) override;
	void akcja() override;
	void kolizja(Organizm* attacker, int old_Y, int old_X) override;
};

