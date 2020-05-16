#pragma once
#include "Roslina.h"
class Trawa :
	public Roslina
{
public:
	Trawa(Swiat* newSwiat, int y, int x, int newWiek);
	void akcja() override;
};

