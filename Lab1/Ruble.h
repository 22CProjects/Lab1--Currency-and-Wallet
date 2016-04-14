#ifndef RUBLE
#define RUBLE

#include "Currency.h"
class Ruble :
	public Currency
{
public:
	Ruble() : Currency("Rubles", "Kopects", 0, 0){}
	Ruble(int w, int f) : Currency("Rubles", "Kopects", w, f){}
	~Ruble() {}
};

#endif