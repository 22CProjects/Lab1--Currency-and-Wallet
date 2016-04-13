#ifndef WALLET
#define WALLET

#include <vector>
#include<cstdlib>

#include "Currency.h"


class Wallet
{
private:
	std::vector <Currency> Currencies; //vector containing the currency types

public:
	Wallet();
	~Wallet();
	int getNumCurrencies();       //return # of curreny types in wallet
	int inWallet(std::string);	  //checks if currency type is in wallet
	bool isEmpty();		          //checks if wallet is empty
	void add(Currency);           //adds currency
	void subtract(Currency);	   //subtracts currency
	void emptyWallet();           //removes everything in the wallet
	std::vector<Currency> getAllCurrencies() { return Currencies; }

};

#endif