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
		if (this->fraction + cur.fraction > 99)
		{
			this->fraction = 100 - (this->fraction + cur.fraction);
			this->whole++;
		}
		else 
		{
			this->fraction += cur.fraction;
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
			cout << "there is no currency of this type left";
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

istream& operator>>(istream& s, Currency& cur) 
{
	s >> cur.fractionName >> cur.whole >> cur.fraction >> cur.fractionName;
	return s;
}