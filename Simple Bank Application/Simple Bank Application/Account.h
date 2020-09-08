/////////////////////////////////Account.h/////////////////////////////////////////////
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Account
{
public:
	double rate = 0.035;
	long int accountNumber;
	double balance;
	double dolarbalance;
	string name;


public:
	Account(){}
	Account(string n, long int no)
	{
		name = n;
		accountNumber = no;
		setBalance(0);
		setdolarBalance(0);
	}
	double deposit(double para)
	{
		return balance += para;
	}
	double withdraw(double cpara)
	{
		return balance -= cpara;
	}
	double addinterest()
	{
		return balance = (getBalance() *rate) + getBalance();
	}

	double getBalance()
	{
		return balance;
	}
	double getDolarBalance()
	{
		return dolarbalance;
	}

	void setBalance(double a)
	{
		balance = a;
	}

	void setdolarBalance(double a)
	{
		dolarbalance = a;
	}
	void moneyTransfer(Account &acc1, Account &acc2, double q)
	{
		cout << "Balance of the account <" << acc2.accountNumber << "> is " << acc2.deposit(q) << " TL" << endl;
		cout << "Balance of your account is " << acc1.withdraw(q) << " TL" << endl;
	}

	void isim(char harf[])
	{
		int i = 0;
		int fark = 'a' - 'A';
		while (harf[i] != '\0')
		{
			if (harf[i] >= 'a' && harf[i] <= 'z')
			{
				harf[i] -= fark;
			}
			printf("%c", harf[i]);
			i++;
		}
		name = string(harf);
	}

};


class Overdraft : public Account
{
public:
	Overdraft() :Account(){}
	void overdraft(double amount, Account &a)
	{
		a.setBalance(a.getBalance() - amount - (amount*0.05));
	}
	void overdraftmoneyTransfer(Account &acc1, Account &acc2, double q)
	{
		cout << "Balance of the account <" << acc2.accountNumber << "> is " << acc2.deposit(q) << endl;
		cout << "Balance of your account is " << acc1.balance << endl;
	}

};

class buyDolar :public Account
{
public:
	buyDolar() :Account(){}

	double usddeposit(double dolar, Account &a)//Para Yatýrma
	{
		return	a.dolarbalance = a.dolarbalance + dolar;
	}
	double usdwithdraw(double cdolar, Account &a)//Para Çek
	{
		return a.dolarbalance -= cdolar;
	}
	double getDolarBalance(Account &a)//Hesaptaki Parayý Göster
	{
		return a.dolarbalance;
	}

	void buyingdolar(double b, Account &a)//Hesaptaki Paradan Dolar Alma
	{
		if (a.getBalance() >= b * 4)
		{
			a.setdolarBalance((a.getDolarBalance() + b));
			a.setBalance(a.getBalance() - (4 * b));
		}
	}

	double dollaraddinterest(Account &a)//Dolar Hesabýna Faiz Ekle
	{
		a.setdolarBalance(a.dolarbalance = a.dolarbalance + (a.dolarbalance*rate));
		return a.dolarbalance;
	}

	void dolarTransfer(Account &acc1, Account &acc2, double q)
	{

		cout << "Balance of the account <" << acc2.accountNumber << "> is " << usddeposit(q, acc2) << " USD" << endl;
		cout << "Balance of your account is " << usdwithdraw(q, acc1) << " USD" << endl;


	}

};