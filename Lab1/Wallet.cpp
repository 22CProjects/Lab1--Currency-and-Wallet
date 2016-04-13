#include "Wallet.h"

using namespace std;

Wallet::Wallet() 
{
}


Wallet::~Wallet()
{
}

int Wallet::getNumCurrencies()
{
	return Currencies.size();
}

int Wallet::inWallet(string type)
{
	for (int i = 0; i < Currencies.size(); i++)
	{
		if (type == Currencies[i].getName()) return i;
	}
	return -1;
}

bool Wallet::isEmpty()
{
	if (Currencies.empty()) return true;
	return false;
}

void Wallet::add(Currency cur)
{
	int pos = inWallet(cur.getName());
	if (pos != -1)
	{
		Currencies[pos] + cur;
	}
	else
	{
		if (Currencies.size() < 5)
		{
			Currencies.push_back(cur);
		}
		else
		{
			cout << "The wallet already contains 5 currencies";
		}
	}
}

void Wallet::subtract(Currency cur)
{
	int pos = inWallet(cur.getName());
	if (pos != -1)
	{
		Currencies[pos] - cur;
	}
	else
	{
		cout << "The wallet does not contain" << cur.getName();
	}
}


void Wallet::emptyWallet()
{
	Currencies.clear();
}