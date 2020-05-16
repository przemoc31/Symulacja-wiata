#pragma once
#include "Roslina.h"
class Mlecz :
	public Roslina
{
public:
	Mlecz(Swiat* newSwiat, int y, int x, int newWiek);
	void akcja() override;
};

