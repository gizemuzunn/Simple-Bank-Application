# Simple-Bank-Application
Simple Bank Application With Using C++

A simple bank application has been made in this project. In this project, we have 'source file' named 'source.cpp' and 'header file' named 'Account .h'. source.cpp contains our main function and ‘Acconut.h’ contains the classes I created. There is the base class 'Account', the subclasses 'Overdraft' and 'buy Dollar'. Subclasses named 'Overdraft' and 'buy Dollar' inherit the 'Account' class. In addition, there is a function in the project that will convert the entered value to capital letters if the user's name is entered in lowercase.

When the project is run, the user is asked to create a name and account number and the received name and account number are sent to the Account class with the ‘myAccount’ object. After the required information is entered, the list of actions that the user wants to do appears on the screen and the user is expected to enter a number between 1 and 8 for the action he wants to do. The 8 transactions offered for the user to choose are as follows; Deposit, Withdraw, Add Interest, Get Balance, Money Transfer, Dollar Current Account, Write Account Information to File and Exit. The contents of these transactions are as follows. 

1 - Deposit: In this transaction, the user is asked for the amount he wants to deposit into his current Turkish Lira account, and the amount entered by the user is sent to the 'Account' class with the 'myAccount' object and added to the current amount of money.

2 - Withdraw: This process is used to withdraw money from the account the user is in. The amount determined by the user is sent to the ‘myAccount’ object withdraw function and the amount entered by the user is deducted from the account. If the user's account does not have the amount he wants to withdraw, it reduces the balance in his account to negative with 5% interest deduction.

3 - Add Interest: The amount of money in the Turkish Lira account is multiplied by the value in the 'rate' variable defined in the Account class and added to the current amount of money and makes an interest transaction.

4 - Get Balance: It prints the balance of the user's Turkish Lira account on the console screen.

5 - Money Transfer: It transfers money from the user's current account to the account number entered by the user. This process is done by using the function we use in the 'withdraw' transaction.

6 - Dollar Current Account: If the user does not have an existing dollar account, it allows the user to open a dollar account. If the user opens this account for the first time, the $ 50 fee is reflected in the dollar account as a minus. After opening a dollar account, the user can deposit dollars to the dollar account, withdraw dollars, view the dollar amount in his account, or buy dollars into the dollar account using the money in the Turkish lira account.

7 - Write Account Information to File: In this process, the balance and account information of the user is printed in the txt file to the directory where the project is located.

8 - Exit: terminates the project.