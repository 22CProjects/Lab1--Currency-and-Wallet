#ifndef CURRENCY
#define CURRENCY

#include <iostream>
#include<string>

class Currency
{
protected:
	std::string name;			// To hold the name of currency
	std::string fractionName;	// To hold the fraction name of currency
	int whole;					// To hold the whole value of currency
	int fraction;				// To hold the fraction value (cents..) of the amount of money
	Currency* next;				// Pointer to point to the next currency of the list [To link one currency to another when added to wallet]

public:
	// Constructors:
	Currency();
	Currency(std::string, std::string);
	Currency(std::string, std::string, int, int);

	// Destructor
	~Currency();

	// Mutators:
	std::string getName() const;
	std::string getFracName() const;
	void set_nextCurrency(Currency*);

	//Accessors:
	Currency* get_nextCurrency() const;

	// Overloading operators:
	Currency& operator+(Currency&);
	Currency& operator-(Currency&);
	friend std::ostream& operator<<(std::ostream&, const Currency&);
	friend std::istream& operator>>(std::istream&, Currency&);

};

#endif