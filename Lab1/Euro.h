#ifndef EURO
#define EURO

#include "Currency.h"

class Euro :
	public Currency
{
public:
	Euro();
	Euro(int w, int f);
	~Euro();
};
#endif
