## Lab1--Currency-and-Wallet

#To create a local copy of the repository:


1. create an ssh key (google this) 
 

2. download and set up "gitbash"


3. you want to copy the repo into you VS project folder, so type:
    
    'cd Documents\"Visual Studio 2015"\Projects'       

*note: your file path may be different but its probably similar


4. now to copy the repo type:

    'git clone git@github.com/22CProjects/Lab1--Currency-and-Wallet.git'

Now, the code should be able to open up the code in VS

#To add my changes:

1.open up git bash


2. cd into the project 

    'cd Documents\"Visual Studio 2015"\Projects\Lab1(or whatever you called it )' 


3. make sure your project is up to date:

    'git status'   <--will show you what is not up to date


4. if you added things that you didnt yet commit run:

    'git stash' 


5.  'git pull'

     (you will probably be asked to enter your passphrase for your ssh key)


6.to view you uncommitted changes as well:

   'git pop stash'



#To add your changes to the code up to the remote repo (here) so that I can update my version on the code:

1.open up git bash


2. cd into the project 

    'cd Documents\"Visual Studio 2015"\Projects\Lab1(or whatever you called it )' 


3. make sure your project is up to date:
    'git status'   <--will show you what is not up to date


4.if it is not up to date, follow the above instructions "to add my changes"


5. type:

    'git add .'
    
    'git commit -m "some message (specify what you changd)"  '
    
    'git push'

thats basically it

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
