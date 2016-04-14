#ifndef DOLLAR
#define DOLLAR

#include "Currency.h"
class Dollar :
	public Currency
{
public:
	Dollar();
	Dollar(int, int);
	~Dollar();
};

#endif