/**************************************************************
Lab1:
Date:	April 14th, 2016
Author:	Anya (Anna) Houk, Kiera (Thi Xuan Ngan) Nguyen
**************************************************************/

#include "Wallet.h"
#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"
#include "CanadianDollar.h"
#include "Pound.h"
#include "Ruble.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));		// seed to generate random numbers for rand()
	int randWhole,		// randomizes the whole being +/-
		randFrac,		// randomizes the fraction being +/-
		randType,		// randomizes the type of currency being +/-
		binaryRand;		// randomizes if the currency is being + or -

	Wallet wallet;

	// Dynamically allocate space for currencies
	Currency* dollar = new Dollar();
	Currency* euro = new Euro();
	Currency* pound = new Pound();
	Currency* ruble = new Ruble();
	Currency* canadianDollar = new CanadianDollar();

	// If wallet is empty then add currency to it
	if (wallet.isEmpty())		//showing utilization of isEmpty function
	{
		wallet.add(euro);
		wallet.add(dollar);
		wallet.add(pound);
		wallet.add(ruble);
		wallet.add(canadianDollar);
	}

	// This loop is used to generate random numbers to add 
	// and subtract money from the wallet based on currencies
	for (int i = 0; i < 50; i++)
	{
		randType = rand() % 5 + 1;
		binaryRand = (rand() % 100) % 2;
		randWhole = rand() % 100;
		randFrac = rand() % 100;

		// Depending on the random number of randType (from 1 to 5: Dollar, Euro, Pound, Ruble, Canadian Dollar)
		// it will add or subtract money from the coresponding currencies
		// Add when binaryRand is even, and subtract when odd
		switch (randType)
		{
		case(1) :
		{
			Currency* randDollar = new Dollar(randWhole, randFrac);
			if (binaryRand == 0)
				wallet.add(randDollar);
			else
				wallet.subtract(randDollar);

			delete randDollar;
			break;
		}
		case(2) :
		{
			Currency* randEuro = new Euro(randWhole, randFrac);
			if (binaryRand == 0)
				wallet.add(randEuro);
			else
				wallet.subtract(randEuro);

			delete randEuro;
			break;
		}
		case(3) :
		{
			Currency* randPound = new Pound(randWhole, randFrac);
			if (binaryRand == 0)
				wallet.add(randPound);
			else
				wallet.subtract(randPound);

			delete randPound;
			break;
		}
		case(4) :
		{
			Currency* randRuble = new Ruble(randWhole, randFrac);
			if (binaryRand == 0)
				wallet.add(randRuble);
			else
				wallet.subtract(randRuble);

			delete randRuble;
			break;
		}
		case(5) :
		{
			Currency* randCanadianDollar = new CanadianDollar(randWhole, randFrac);
			if (binaryRand == 0)
				wallet.add(randCanadianDollar);
			else
				wallet.subtract(randCanadianDollar);

			delete randCanadianDollar;
			break;
		}

		}
	}

	cout << "\n\nThe wallet contains:\n"
		<< *dollar << endl << *euro << endl << *pound << endl
		<< *ruble << endl << *canadianDollar << endl << endl;

	// Remove all currencies from wallet
	wallet.emptyWallet();
	if (wallet.isEmpty())cout << ":)" << endl;

	// Free space used by 5 currencies
	delete dollar;
	delete euro;
	delete pound;
	delete ruble;
	delete canadianDollar;

	system("pause");
	return 0;
}