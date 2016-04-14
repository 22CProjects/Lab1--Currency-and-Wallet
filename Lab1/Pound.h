#ifndef POUND
#define POUND

#include "Currency.h"
class Pound :
	public Currency
{
public:
	Pound() : Currency("Pounds", "Pence", 0, 0){}
	Pound(int w, int f) : Currency("Pounds", "Pence", w, f){}
	~Pound() {}
};

#endif