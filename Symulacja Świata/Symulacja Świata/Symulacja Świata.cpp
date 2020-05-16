#include <iostream>
#include "Swiat.h"

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	char** map = new char* [n];
	for (int i = 0; i < n; i++)
		map[i] = new char[m];
	Swiat* swiat = new Swiat(n, m);
	swiat->start();


	delete[](map);
	return 0;
}
