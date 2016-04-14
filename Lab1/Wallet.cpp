#include "Wallet.h"

using namespace std;

Wallet::Wallet() : numCurrencies(0)
{
}


Wallet::~Wallet()
{
	cout << "Wallet dc";
}

int Wallet::getNumCurrencies()
{
	return numCurrencies;
}

int Wallet::inWallet(string type)
{
	Currency* temp = top;
	for (int i = 0; i < numCurrencies; i++)
	{
		if (type == temp->getName()) return i;
		temp = temp->get_nextCurrency();
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
	int pos = inWallet(cur->getName());
	if (pos != -1)
	{
		//do
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
			cout << "The wallet already contains 5 currencies";
		}
	}
	
}

void Wallet::subtract(Currency* cur)
{
	int pos = inWallet(cur->getName());
	if (pos != -1)
	{
		//do 
	}
	else
	{
		cout << "The wallet does not contain" << cur->getName();
	}
}


void Wallet::emptyWallet()
{
	Currency* temp = top;

	while (top!= nullptr)
	{
		temp = top;
		cout << "Removing " << temp->getName() << " from wallet" << endl;
		top = top->get_nextCurrency();
		numCurrencies--;
	}

	cout << "Wallet is now Empty"<<endl;
		
}