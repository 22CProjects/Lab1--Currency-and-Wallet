#ifndef EURO
#define EURO

#include "Currency.h"

class Euro :
	public Currency
{
public:
	Euro():Currency("Euro", "Cents", 0, 0){}
	Euro(int w, int f) : Currency("Euro", "Cents", w, f){}
	~Euro() {}
};
#endif