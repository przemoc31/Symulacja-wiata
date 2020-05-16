#pragma once
#include "Organizm.h"
#include "Zwierze.h"
#include <vector>
using namespace std;

class Swiat
{
public:
	Swiat(int n, int m);
	void wykonajTure();
	void rysujSwiat();
	void start();
	void ustawOrganizm(Organizm* organizm, int y, int x);
	void usunOrganizm(int y, int x);
	void zabijOrganizm(int y, int x);
	int getSize_X();
	int getSize_Y();
	char getMap(int y, int x);
	Organizm* getOrgMap(int y, int x);
	void setOrgMap(int y, int x, Organizm* newOrg);
	void setMap(int y, int x, char znak);
	vector<Organizm*> sortObjects(vector<Organizm*> objects);
	vector<Organizm*>  cleanObjects(vector<Organizm*> objects);
	~Swiat();
private:
	int size_X;
	int size_Y;
	char** map;
	Organizm*** orgMap;
	vector<Organizm*> objects;
};

