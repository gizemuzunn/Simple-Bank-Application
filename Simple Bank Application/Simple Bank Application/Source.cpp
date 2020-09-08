/////////////////////////////////Source.cpp/////////////////////////////////////////////
#include "Account.h"
#include <fstream> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	char isim[100];
	string name;
	long int accountNumber, accountNumber2;
	double balance, money;
	int operationNumber;

	cout << "----------------------------------------" << endl;
a5:cout << "Please Enter Your Name : ";
	gets_s(isim);
	if (isim[0] == NULL)
	{
		cout << "Cannot Go Blank" << endl;
		goto a5;
	}
	cout << "Please Enter Your Account Number : ";
	cin >> accountNumber;
	Account myAccount(name, accountNumber);
	Overdraft ov;
	buyDolar buy;
	bool basvuru = false;
	bool basvuru2 = false;
	bool overdraft = false;
a1: cout << "----------------------------------------" << endl;
	cout << "Dear ";  myAccount.isim(isim); cout << " Account Number : <" << accountNumber << ">" << endl;
	cout << "----------------------------------------" << endl;
	cout << " >> Select The Action You Want To Do" << endl;
	cout << "<1> - Deposit" << endl;
	cout << "<2> - Withdraw " << endl;
	cout << "<3> - Addinterest " << endl;
	cout << "<4> - Get Balance" << endl;
	cout << "<5> - Money Transfer " << endl;
	cout << "<6> - Dollar Currency Account " << endl;
	cout << "<7> - Write Account Information To File" << endl;
	cout << "<8> - Exit" << endl;
	cout << "Your Choose : ";
	cin >> operationNumber;

	if (operationNumber == 1){
		cout << "How Much Money Do You Want To Deposit : ";
		cin >> money;
		system("cls");
		cout << "Dear "; myAccount.isim(isim); cout << " Transaction Is Succesfull And Your New Balance Is : " << myAccount.deposit(money) << " TL" << endl;
		goto a1;
	}
	if (operationNumber == 2){
		cout << "How Much Money Do You Want To Withdraw : ";
		cin >> money;
		char answer3;
		if (money <= myAccount.getBalance())
		{
			myAccount.withdraw(money);
		}
		if (money >= myAccount.getBalance()){
			cout << "Dear " << myAccount.name; cout << "\nWithdrawing " << money << " will overdraft your account and accrue a %5 overdraft fee." << endl;
			cout << "Do you wish to continue with this transaction? [Y/N]? ";
			cin >> answer3;
			if (answer3 == 'Y' || answer3 == 'y')
			{
				ov.overdraft(money, myAccount);
				overdraft = true;
			}
			else if (answer3 == 'N' || answer3 == 'n')
			{
				system("cls");
				cout << "Credit Deposits Account Has Been Canceled - You Can Try Later" << endl;
				goto a1;
			}

		}
		system("cls");
		cout << "Dear "; myAccount.isim(isim); cout << " Transaction Is Succesfull And Your New Balance Is : " << myAccount.getBalance() << " TL" << endl;
		goto a1;
	}

	if (operationNumber == 3){
		char ans;
		cout << "The Type Of The Account You Want To Add Interest On [D]ollar / [T]L :"; cin >> ans;
		if (ans == 'T' || ans == 't')
		{
			system("cls"); cout << "Interest Rate Is " << myAccount.rate << "The Operation Is Completed And Your New Balance Is : " << myAccount.addinterest() << " TL" << endl;
		}
		if (ans == 'D' || ans == 'd')
		{
			system("cls"); cout << "Interest Rate Is " << myAccount.rate << "The Operation Is Completed And Your New Balance Is : " << buy.dollaraddinterest(myAccount) << " Dollar" << endl;
		}
		goto a1;
	}

	if (operationNumber == 4){
		system("cls");
		cout << "Your  TL Balance :  " << myAccount.getBalance() << " TL" << endl;
		if (basvuru == true)
		{
			cout << "Your Dolar Balance : " << myAccount.getDolarBalance() << " USD" << endl;
		}
		goto a1;
	}

	if (operationNumber == 5){
		char answerr;
		cout << "Which Account You Want To Transfer Money [[D]ollar / [T]l]";
		cin >> answerr;
		if (answerr == 'T' || answerr == 't')
		{
			cout << "Please Enter The Amount You Wish To Deposit In The Other Account : ";
			cin >> money;
			cout << "Please Enter The Account Number You Wish To Deposit :  ";
			cin >> accountNumber2;
			if (money <= myAccount.getBalance())
			{
				system("cls");
				Account myAccount2("", accountNumber2);
				myAccount.moneyTransfer(myAccount, myAccount2, money);
				goto a1;
			}
			if (money >= myAccount.getBalance())
			{
				char answer3;
				cout << "Dear " << myAccount.name; cout << "\nWithdrawing " << money << " will overdraft your account and accrue a %5 overdraft fee." << endl;
				cout << "Do you wish to continue with this transaction? [Y/N]? :  ";
				cin >> answer3;
				if (answer3 == 'Y' || answer3 == 'y')
				{
					system("cls");
					ov.overdraft(money, myAccount);
					Account myAccount2("", accountNumber2);
					ov.overdraftmoneyTransfer(myAccount, myAccount2, money);
					goto a1;
				}
				else if (answer3 == 'N' || answer3 == 'n')
				{
					system("cls");
					cout << "Credit Deposits Account Has Been Canceled - You Can Try Later" << endl;
					goto a1;
				}
			}
		}
		else if ((answerr == 'D' || answerr == 'd') && basvuru == true)
		{
			double dollarr; double accountNumber2;
			cout << "Please Enter The Amount You Wish To Deposit In The Other Account : ";
			cin >> dollarr;
			cout << "Please Enter The Account Number You Wish To Deposit :  ";
			cin >> accountNumber2;
			if (dollarr < myAccount.dolarbalance)
			{
				system("cls");
				Account myAccount2("", accountNumber2);
				buy.dolarTransfer(myAccount, myAccount2, dollarr);
				goto a1;
			}
			else{
				system("cls");
				cout << "Insufficient Balance" << endl;
				goto a1;
			}

		}
		else
		{
			system("cls");
			cout << "You Do Not Have A Dollar Currency Account." << endl;
			goto a1;
		}

	}

	if (operationNumber == 6){
		if (basvuru == true){ goto a3; }
		char answer;
		cout << "Do You Want To Open Your Dollar Currency Account? Account Opening Fee Is 50 $ [Y/N]:";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			basvuru = true;
			system("cls");

		a3:int answer1;
			cout << "----------------------------------------" << endl;
		a2:cout << " >> Select The Action You Want To Do" << endl;
			cout << "1 >> To Deposit Dollar" << endl;
			cout << "2 >> To Withdraw Dollar" << endl;
			cout << "3 >> Show Balance" << endl;
			cout << "4 >> Buy Dollar" << endl;
			cout << "5 >> Main Menu" << endl;
			cout << "Your Chooise : "; cin >> answer1;

			if (answer1 == 1){
				double bakiye;
				cout << "How Much Dollar Do You Want To Deposit : "; cin >> bakiye;
				system("cls");
				cout << "Dear "; myAccount.isim(isim); cout << " Transaction Is Succesfull And Your New Balance Is : ";
				if (basvuru2 == false)
				{
					cout << buy.usddeposit(bakiye - 50, myAccount);
					basvuru2 = true;
				}
				else
				{
					cout << buy.usddeposit(bakiye, myAccount);
				}
				cout << " USD" << endl;
				cout << "----------------------------------------" << endl;
				goto a2;
			}
			if (answer1 == 2){
				double bakiye;
				cout << "How Much Dollar Do You Want To Withdraw : "; cin >> bakiye;
				system("cls");
				if (myAccount.dolarbalance >= bakiye)
				{
					cout << "Dear "; myAccount.isim(isim); cout << " Transaction Is Succesfull And Your New Balance Is : " << buy.usdwithdraw(bakiye, myAccount) << " USD" << endl;
					cout << "----------------------------------------" << endl;
				}
				else
					cout << "Overdraft Account Application Is Available Only On Turkish Liras.May Be Available In Later Versions" << endl;
				goto a2;
			}
			if (answer1 == 3)
			{
				system("cls");
				cout << "Your  TL Balance :  " << myAccount.getBalance() << " TL" << endl;
				if (basvuru == true)
				{
					cout << "Your Dolar Balance : " << myAccount.getDolarBalance() << " USD" << endl;
				}
				cout << "----------------------------------------" << endl;
				goto a2;
			}
			if (answer1 == 4)
			{
				system("cls");
				cout << "Your  TL Balance :  " << myAccount.getBalance() << " TL" << endl;
				if (basvuru == true)
				{
					cout << "Your Dolar Balance : " << myAccount.getDolarBalance() << " USD" << endl;
				}
				cout << "----------------------------------------" << endl;
				double bakiye;
				cout << "How Much Dollar Do You Want To Buy : "; cin >> bakiye;
				system("cls");
				if (bakiye * 4 <= myAccount.getBalance())
				{
					if (basvuru2 == false)
					{
						buy.buyingdolar(bakiye, myAccount);
						myAccount.setdolarBalance(myAccount.getDolarBalance() - 50);
						basvuru2 = true;
					}
					else
					{
						buy.buyingdolar(bakiye, myAccount);
					}

					cout << "Dear "; myAccount.isim(isim); cout << " Transaction Is Succesfull And Your New Balance Is : " << buy.getDolarBalance(myAccount) << " USD" << endl;
					cout << "----------------------------------------" << endl;
				}
				else{
					cout << "Insufficient Balance --" << endl;
					cout << "----------------------------------------" << endl;
				}
				goto a2;
			}
			if (answer1 == 5)
			{
				system("cls");
				goto a1;
			}
		}
		else if (answer == 'N' || answer == 'n')
		{
			cout << "If You Want, You Can Apply Later";
		}

	}
	if (operationNumber == 7)
	{
		ofstream file1;
		file1.open("Account.txt", ios::out);
		file1 << "Kullanýcý Adý :" << myAccount.name;
		file1 << "\nHesap Numarasý :" << myAccount.accountNumber;
		file1 << "\nTL Balance : " << myAccount.balance;

		file1 << "\nDollar Current Account : ";
		if (basvuru == true)
		{
			file1 << "Yes";
			file1 << "\nDollar Balance :" << myAccount.dolarbalance;
		}
		else
		{
			file1 << "No";
		}
		file1 << "\nOverDraft : ";
		if (basvuru == true)
		{
			file1 << "Yes";
		}
		else
		{
			file1 << "No";
		}

		file1.close();
		system("cls");
		cout << " Transaction Is Succesfull Press" << endl;
		cout << "<1> To Return To The Main Menu" << endl;
		cout << "<2> To Exit " << endl;
		int ss;
		cout << "Your Choosing : "; cin >> ss;
		if (ss == 1)
		{
			system("cls");
			goto a1;

		}
		if (ss == 2)
			exit(0);
	}


	if (operationNumber == 8)
	{
		exit(0);
	}

	system("pause");
	return 0;
}