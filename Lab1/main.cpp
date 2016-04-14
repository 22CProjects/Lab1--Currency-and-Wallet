#include "Wallet.h"
#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	Wallet wallet;
	
	Currency* dollar = new Dollar();
	Currency* euro = new Euro();
	
	wallet.add(euro);
	wallet.add(dollar);
	
	wallet.emptyWallet();

	wallet.add(dollar);

	delete dollar;
	delete euro;
	system("pause");
	return 0;
}
