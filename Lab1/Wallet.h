#ifndef WALLET
#define WALLET

#include <vector>
#include<cstdlib>

#include "Currency.h"

const int MAX = 5;

class Wallet
{
private:
	
	int numCurrencies;
	Currency* top;

public:
	Wallet();
	~Wallet();
	int getNumCurrencies();       //return # of currency types in wallet
	int inWallet(Currency*);	  //checks if currency type is in wallet
	bool isEmpty();		          //checks if wallet is empty
	void add(Currency*);           //adds currency
	void subtract(Currency*);	   //subtracts currency
	void emptyWallet();           //removes everything in the wallet
};

#endif