#ifndef DOLLAR
#define DOLLAR

#include "Currency.h"
class Dollar :
	public Currency
{
public:
	Dollar() : Currency("Dollars", "Cents", 0, 0){}
	Dollar(int w, int f) : Currency("Dollars", "Cents", w, f){}
	~Dollar() {}
};

#endif