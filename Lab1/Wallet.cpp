#include "Wallet.h"

using namespace std;

Wallet::Wallet() : numCurrencies(0)
{
}


Wallet::~Wallet()
{
}

int Wallet::getNumCurrencies()
{
	return numCurrencies;
}

int Wallet::inWallet(Currency* type)
{
	int pos = 1;
	Currency* temp = top;
	while(temp != 0)
	{
		if (type->getName() == temp->getName()) return pos;
		temp = temp->get_nextCurrency();
		pos++;
	}
	return -1;
}

bool Wallet::isEmpty()
{
	if (numCurrencies == 0) return true;
	return false;
}

void Wallet::add(Currency* cur)
{
	Currency* temp = top;
	int pos = inWallet(cur);
	if (pos != -1)
	{
		for (int i = 1; i != pos; i++)
		{
			temp = temp->get_nextCurrency();
		}
		*temp + *cur;
	}

	else
	{
		if (numCurrencies < MAX)
		{
			cur->set_nextCurrency(top);
			top = cur;
			numCurrencies++;
			cout << cur->getName() << " added, numCurrencies is " <<numCurrencies<<endl;
		}
		else
		{
			cout << cur->getName()<<" The wallet already contains 5 currencies"<<endl;
		}
	}
	
}

void Wallet::subtract(Currency* cur)
{
	Currency* temp = top;
	int pos = inWallet(cur);
	if (pos != -1)
	{
		for (int i = 1; i != pos; i++)
		{
			temp = temp->get_nextCurrency();
		}
		*temp - *cur;
	}
	else
	{
		cout << "**The wallet does not contain" << cur->getName()<<"**"<<endl;
	}
}


void Wallet::emptyWallet()
{
	Currency* temp = top;

	while (top!= nullptr)
	{
		temp = top;
		numCurrencies--;
		cout << "--Removing " << temp->getName() << " from wallet--" << endl 
			<<"The wallet now contains "<<numCurrencies<<" Currencies"<<endl;
		top = top->get_nextCurrency();
	}

	cout << "Wallet is now Empty"<<endl;
		
}