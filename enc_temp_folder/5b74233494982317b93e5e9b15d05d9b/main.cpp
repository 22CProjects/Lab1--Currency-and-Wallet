#include "Wallet.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	int randWhole = 0;// rand() % 100;
	int randFraction = rand() % 100;
	int rd = rand() % 5;
	


	Currency CurrencyOptions[5] = { Currency("Dollars", "Cents", rand() % 100, randFraction), Currency("CanadianDollars", "Cents", rand() % 100, randFraction), Currency("Pounds", "Pence",randWhole, randFraction), Currency("Rubles", "Kopeks", randWhole, randFraction), Currency("Euro", "Cents",randWhole, randFraction) };

	enum CurTypes { DOLLAR, CANADIANDOLLAR, POUNDS, RUBLES, EURO };

	Wallet wallet;

	for (int i = 0; i < 20; i++)
	{
		/*randWhole = rand() % 100;
		randFraction = rand() % 100;
		rd = rand() % 5;*/
		wallet.add(CurrencyOptions[rd]);
		cout << CurrencyOptions[rd]<<endl;
		//wallet.subtract(CurrencyOptions[rd]);

	}
	vector<Currency> temp = wallet.getAllCurrencies();

	for (int i = 0; i < 5; i++)
	{
		cout << temp[i]<<endl;
	}

	system("pause");
	return 0;
}
