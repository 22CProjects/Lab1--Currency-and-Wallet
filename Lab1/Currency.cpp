#include <iostream>

#include "Currency.h"

using namespace std;

// DEFAUlT CONSTRUCTOR: Set name to General name and numbers to 0
Currency::Currency() : name("General Currency"), fractionName("General Fraction"), whole(0), fraction(0), next(0)
{
}

// CONSTRUCTOR 2: receive names of currency and fraction as parameters 
// and pass it to the names of currency and fraction, set other variables to 0
Currency::Currency(string n, string fn) : name(n), fractionName(fn), whole(0), fraction(0), next(0)
{
}

// CONSTRUCTOR 3: receive names of currency, fraction and value of whole
// and fraction part as parameter and pass them on the coresponding variables
Currency::Currency(string n, string fn, int w, int f) : name(n), fractionName(fn), whole(w), fraction(f), next(0)
{
}

// DESTRUCTOR
Currency::~Currency()
{
}

// Definition of set_nextCurrency: 
// It receives a currency pointer as parameter, and point pointer "next" to that currency
void Currency::set_nextCurrency(Currency* ncur)
{
	next = ncur;
}

// Definition of get_nextCurrency: 
// It returns the address of pointer "next"
Currency* Currency::get_nextCurrency() const
{
	return next;
}

// Definition of getName()
// It returns the name of the currency
string Currency::getName() const
{
	return name;
}

// Definition of getFracName()
// It returns the name of the fraction part
string Currency::getFracName() const
{
	return fractionName;
}


/********************************************************
Definition of overloading operator+
- It allows user to add currencies variables directly
instead of having to operate for the whole part
and the fraction part later.
- It only add money to the same currency.
- If the fraction is over 100, it will divide fraction
by 100, add the result to whole part and set the
remain value to fraction part
*********************************************************/
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


/********************************************************
Definition of overloading operator-
- It is similart to operator +
- Except if the result of the fraction part is negative,
it subtract 1 from whole part.
*********************************************************/
Currency& Currency::operator-(Currency& cur)
{
	if (this->getName() == cur.getName())
	{
		if (this->whole - cur.whole < 0)//since you cannot have negative a negative amount of currency,
		{										  //if the subtraction leads to a negative amount, set to zero
			this->whole = 0;
			this->fraction = 0;
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

/********************************************************
Definition of overloading output operator <<
- It prints out all variables of Currency class
just by one operator << (cout << currencyVariable;)
*********************************************************/
ostream& operator<<(std::ostream& s, const Currency& curr)
{
	s << curr.whole << " " << curr.name << " and " << curr.fraction << " " << curr.fractionName;
	return s;
}

/*****************************************************************
Definition of overloading input operator >>
- When we operate input operator like cin >> currencyVariable
it will let user enter values for all 4 variables at a time
seperated by space or enter, until user input enough values
******************************************************************/
istream& operator>>(istream& s, Currency& cur)
{
	s >> cur.fractionName >> cur.whole >> cur.fraction >> cur.fractionName;
	return s;
}