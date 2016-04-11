#include <iostream>

#include "Currency.h"

using namespace std;

Currency::Currency(string n, string fn, int w, int f) : name(n), fractionName(fn), whole(w), fraction(f)
{
}

Currency::~Currency() 
{
}

string Currency::getName()
{
	return name;
}

string Currency::getFracName()
{
	return fractionName;
}

Currency& Currency::operator+(Currency& cur)
{
	if (this->getName() == cur.getName())
	{
		this->whole += cur.whole;
		if (this->fraction + cur.fraction > 100)
		{
			this->fraction = 100 - (this->fraction + cur.fraction);
			this->whole++;
		}
		else 
		{
			this->fraction += cur.whole;
		}
	}
	else
	{
		cout << "currency is not of same type";
	}
	return *this;
}

Currency& Currency::operator-(Currency& cur) 
{
	if (this->getName() == cur.getName())
	{
		if (cur.fraction > this->fraction)
		{
			this->whole--;
			this->fraction + 100;
			this->fraction -= cur.fraction;
		}
		this->whole -= cur.whole;
		if (this->whole < 0)
		{
			this->whole = 0;
			this->fraction = 0;
		}
	}
	else
	{
		cout << "currency is not of same type";
	}
	return *this;
}
ostream& operator<<(std::ostream& s, const Currency& curr) 
{
	s << curr.whole << " " << curr.name << " and " << curr.fraction << " " << curr.fractionName;
	return s;
}
ostream& operator>>(std::ostream&, const Currency&) {}//not sure what the use of this operator is