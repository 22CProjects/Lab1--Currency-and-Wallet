#include "Wallet.h"
#include "Currency.h"
#include  "Dollar.h"
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
	srand(time(0));
	int randWhole,//randomizes the whole being +/-
		randFrac,//randomizes the fraction being +/-
		randType,//randomizes the type of currency being +/-
		binaryRand;//randomizes if the currency is being + or -
	
	Wallet wallet;
	
	Currency* dollar = new Dollar();
	Currency* euro = new Euro();
	Currency* pound = new Pound();
	Currency* ruble = new Ruble();
	Currency* canadianDollar = new CanadianDollar();

	if (wallet.isEmpty())//showing utilization of isEmpty function
	{
		wallet.add(euro);
		wallet.add(dollar);
		wallet.add(pound);
		wallet.add(ruble);
		wallet.add(canadianDollar);
	}

	Currency* randDollar;
	Currency* randEuro;
	Currency* randPound;
	Currency* randRuble;
	Currency* randCanadianDollar;

	for (int i = 0; i < 50; i++)
	{
		randType = rand() % 5 +1;
		binaryRand = (rand() % 100) %2;
		randWhole = rand() % 100;
		randFrac = rand() % 100;
		switch(randType)
		{
			case(1) :
			{
				randDollar = new Dollar(randWhole, randFrac);
				if (binaryRand == 0)
				{
					wallet.add(randDollar);
				}
				else
				{
					wallet.subtract(randDollar);
				}
				
				delete randDollar;
				break;
			}
			case(2) :
			{
				randEuro = new Euro(randWhole, randFrac);
				if (binaryRand == 0)
				{
					wallet.add(randEuro);
				}
				else
				{
					wallet.subtract(randEuro);
				}

				delete randEuro;
				break;
			}
			case(3) :
			{
				randPound = new Pound(randWhole, randFrac);
				if (binaryRand == 0)
				{
					wallet.add(randPound);
				}
				else
				{
					wallet.subtract(randPound);
				}

				delete randPound;
				break;
			}
			case(4) :
			{
				randRuble = new Ruble(randWhole, randFrac);
				if (binaryRand == 0)
				{
					wallet.add(randRuble);
				}
				else
				{
					wallet.subtract(randRuble);
				}

				delete randRuble;
				break;
			}
			case(5) :
			{
				randCanadianDollar = new CanadianDollar(randWhole, randFrac);
				if (binaryRand == 0)
				{
					wallet.add(randCanadianDollar);
				}
				else
				{
					wallet.subtract(randCanadianDollar);
				}

				delete randCanadianDollar;
				break;
			}

		}
	}

	cout<<endl<<endl<<"The wallet contains:"<<endl<< *dollar << endl << *euro << endl << *pound << endl<<*ruble<< endl << *canadianDollar << endl<<endl;
	wallet.emptyWallet();
	if (wallet.isEmpty())cout << ":)"<<endl;

	delete dollar;
	delete euro;
	delete pound;
	delete ruble;
	delete canadianDollar;

	system("pause");
	return 0;
}
