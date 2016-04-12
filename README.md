# Lab1--Currency-and-Wallet

To create a local copy of the repository:


1. create an ssh key (google this) 
 

2. download and set up "gitbash"


3. you want to copy the repo into you VS project folder, so type:
    
    'cd Documents\"Visual Studio 2015"\Projects'       

*note: your file path may be different but its probably similar


4. now to copy the repo type:

    'git clone git@github.com/22CProjects/Lab1--Currency-and-Wallet.git'

...
will add futher instructions





##TODO:
- [ ]Currency baseclass
   - [x]operator+
   - [x]operator-
   - [x]operator<<
   - [ ]operator>>
- [ ]Derived Currency classes
- [ ]Wallet Class
   - [ ]numCurrencies (number of existing currency types)
   - [ ]inWallet (check if currency is in wallet)
   - [ ]add (add money by currency)
   - [ ]subtract (subtract money by currency)
   - [ ]remove (remove money by currency)
   - [ ]emptyWallet (empty the wallet)
   - [ ]isEmplty (check if wallet is empty)
- [ ] main
   - [ ]add/sub currencies using base-clase array
   - [ ]random num generator to add/remove amounts between 0-99 for wholes and fractions
   - [ ]enum to generate type of currency 
   - [ ]output contents of wallet
   - [ ]empty wallet
   - [ ]print process of emptying wallet
