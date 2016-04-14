#include <iostream>

#include "Currency.h"

using namespace std;

Currency::Currency() : name("General Currency"), fractionName("General Fraction"), whole(0), fraction(0), next(0)
{
}

Currency::Currency(string n, string fn) : name(n), fractionName(fn), whole(0), fraction(0), next(0)
{
}

Currency::Currency(string n, string fn, int w, int f) : name(n), fractionName(fn), whole(w), fraction(f), next(0)
{
}

Currency::~Currency() 
{
}

void Currency::set_nextCurrency(Currency* ncur)
{
	next = ncur;
}

Currency* Currency::get_nextCurrency() const
{
	return next;
}

string Currency::getName() const
{
	return name;
}

string Currency::getFracName() const
{
	return fractionName;
}

Currency& Currency::operator+(Currency& cur)
{
	if (this->getName() == cur.getName())
	{
		this->whole += cur.whole;
		this->fraction += cur.fraction;
		if (this->fraction >= 100)
		{
			this->whole += this->fraction / 100;
			this->fraction = this->fraction % 100;
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
		if (this->whole - cur.whole < 0 )//since you cannot have negative a negative amount of currency,
		{										  //if the subtraction leads to a negative amount, set to zero
			this->whole = 0;
			this->fraction = 0;
			cout << "there is no currency of this type left";
		}

		else
		{
			if (this->fraction - cur.fraction < 0)
			{
				this->whole--;
				this->fraction = (100 + this->fraction) - cur.fraction;
			}
			else
			{
				this->fraction -= cur.fraction;
				this->whole -= cur.whole;
			}
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