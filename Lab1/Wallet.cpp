#include "Wallet.h"

using namespace std;

// DEFAULT CONSTRUCTOR: set number of currencies to 0
Wallet::Wallet() : numCurrencies(0)
{
}

// DESTRUCTOR
Wallet::~Wallet()
{
}

// Return the number of currencies in the wallet
int Wallet::getNumCurrencies()
{
	return numCurrencies;
}

// Check if that currency is exist in the wallet, 
// if so return the index position, or return -1
int Wallet::inWallet(Currency* type)
{
	int pos = 1;
	Currency* temp = top;
	while (temp != 0)
	{
		if (type->getName() == temp->getName()) return pos;
		temp = temp->get_nextCurrency();
		pos++;
	}
	return -1;
}

// Check if the wallet is empty
bool Wallet::isEmpty()
{
	if (numCurrencies == 0) return true;
	return false;
}

/********************************************************
Definition of add
- It will do both adding new currency to the wallet
(if the total currency has not reached 5) and add
money of that currency to the wallet.
*********************************************************/
void Wallet::add(Currency* cur)
{
	Currency* temp = top;
	int pos = inWallet(cur);

	// if pos is different from 1 (means it exist), 
	// traverse through the wallet until it reaches the same pos then add new money value to the same currency
	if (pos != -1)
	{
		for (int i = 1; i != pos; i++)
		{
			temp = temp->get_nextCurrency();
		}
		*temp + *cur;
	}
	//If this cur currency is not in the wallet, add this new currency (if numCurrencies<5) in along with its money value
	else
	{
		if (numCurrencies < MAX)
		{
			cur->set_nextCurrency(top);
			top = cur;
			numCurrencies++;
			cout << cur->getName() << " added, numCurrencies is " << numCurrencies << endl;
		}
		else
		{
			cout << cur->getName() << " The wallet already contains 5 currencies" << endl;
		}
	}

}

/********************************************************
Definition of subtract
- It will subtract the amount of money in cur from
the same currency in the wallet
- If pos = -1, it will notify user that that currency
is not in the wallet
*********************************************************/
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
		cout << "**The wallet does not contain" << cur->getName() << "**" << endl;
	}
}

/********************************************************
Definition of emptyWallet()
- It cuts the link of all currencies in the wallet
by moving pointer top back to the head position until
top reaches nullptr
- (The real value of currencies is delete in main
because they are dynamically allocated space in main)
*********************************************************/
void Wallet::emptyWallet()
{
	Currency* temp = top;

	while (top != nullptr)
	{
		temp = top;
		numCurrencies--;
		cout << "--Removing " << temp->getName() << " from wallet--" << endl
			<< "The wallet now contains " << numCurrencies << " Currencies" << endl;
		top = top->get_nextCurrency();
	}

	cout << "Wallet is now Empty" << endl;

}