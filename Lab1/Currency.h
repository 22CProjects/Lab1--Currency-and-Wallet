#ifndef CURRENCY
#define CURRENCY

#include <iostream>
#include<string>
class Currency
{
protected:
	std::string name;
	std::string fractionName;
	int whole;
	int fraction;
	Currency* next;

public:
	Currency();
	Currency(std::string, std::string);
	Currency(std::string,std::string,int,int);
	~Currency();
	std::string getName() const;
	std::string getFracName() const;
	Currency& operator+(Currency&);
	Currency& operator-(Currency&);
	void set_nextCurrency(Currency*);
	Currency* get_nextCurrency() const;
	friend std::ostream& operator<<(std::ostream&, const Currency&);
	friend std::istream& operator>>(std::istream&, Currency&);

};

#endif