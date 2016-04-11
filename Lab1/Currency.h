#include <iostream>
#include<string>
class Currency
{
private:
	std::string name;
	std::string fractionName;
	int whole;
	int fraction;

public:
	Currency(std::string,std::string,int,int);
	~Currency();
	std::string getName();
	std::string getFracName();
	Currency& operator+(Currency&);
	Currency& operator-(Currency&);
	friend std::ostream& operator<<(std::ostream&, const Currency&);
	friend std::ostream& operator>>(std::ostream&, const Currency&);//not sure what the use of this operator is

};

