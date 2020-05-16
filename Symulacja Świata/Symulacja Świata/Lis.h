#pragma once
#include "Zwierze.h"
class Lis :
	public Zwierze
{
public:
	Lis(Swiat* newSwiat, int y, int x, int newWiek);
	void akcja() override;
};

