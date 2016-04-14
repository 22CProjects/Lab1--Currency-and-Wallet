#ifndef CANADIANDOLLAR
#define CANADIANDOLLAR

#include "Currency.h"
class CanadianDollar :
	public Currency
{
public:
	CanadianDollar() : Currency("Canadian Dollars", "Cents", 0, 0) {}
	CanadianDollar(int w, int f) : Currency("Canadian Dollars", "Cents", w, f) {}
	~CanadianDollar() {}
};

#endif