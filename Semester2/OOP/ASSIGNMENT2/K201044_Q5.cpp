#include<iostream>
using namespace std;

class Account
{
	protected:
		double balance;
	public:
		Account(double b) //Constructor for initialzie vvalue of balance
		
		{
			if(b>=0)
			{
				balance=b;
				    cout << "Account Balance = " << balance << endl;
			}
			else
			{
				balance=0;
				cout<<"Initial balance was invalid"<<endl;
			}
		
		}
		double credit(double add) //function for add value into balance;
		{
			balance=balance+add;
			
		}
		double debit(double withdraw) //funtion for withdraw money
		{
			if(withdraw >balance)
			{
				cout << "Debit amount exceeded Account balance"<<endl;
			}
			else
			{
				balance=balance-withdraw;
				
			}
		}
		double getBalance()
		{
			return balance;
		}
};
class SavingAccounts:public Account
{
	double int_rate;
	
	double initial_balance;
	
	double i;
	
	public:
		SavingAccounts(double balance,double rate):Account(balance)
	{
	 
			int_rate=rate;
			
			initial_balance=balance;
			
		}
		
		double calculateInterest() //function to calcluate interest rate
		{
			i=initial_balance*int_rate;
			
			cout << "Interest Rate= " << i << endl;
			
			return i;
		}
		double credit(double add)
		{
			if(Account::credit(add))
        {
			initial_balance=initial_balance+add;
			
			cout << "Account Balance After Adding interest = " << initial_balance << endl;
		}}
		double debit(double withdraw)
		{
			if(Account::debit(withdraw))
           {
			if(withdraw >balance)
			{
				cout << "Debit amount exceeded account balance"<<endl;
			}
			else
			{
				initial_balance=initial_balance-withdraw;
				
				cout << "Account Balance After withdraw = " << initial_balance << endl;
			}
		}}
};
class CheckingAccount:public Account
{
	double fees,c_balance;
	
	public:
		CheckingAccount(double b,double f):Account(b)
		{
			fees=f;
			
			c_balance=b;
		}
		 void credit(double add)
    {
        if(Account::credit(add))
        {
        	c_balance=c_balance+add;
        
			cout << "Account Balance After Credit  " << c_balance << endl;
			}
		}
         void debit(double withdraw)
     {
       	 if(Account::debit(withdraw))
           {
           	c_balance=c_balance-fees;
           	
           	cout << "Balance After Debit Amount and Deducting transaction fees= " << c_balance << endl;
			}
 	}
};




int main()
{
	Account a(90000);//initilaize balance
	
	a.credit(10000); //credit amount into balance
	
	a.debit(30000);// debit amount from balance
	
	a.getBalance();
	
	cout << "Balance in Acount After Crediting and Debititng Amount= " <<a.getBalance()<<endl;
	
	double a1=a.getBalance();
	
	SavingAccounts b(a1,0.05);// interest rate=0.05
	
	double b1=b.calculateInterest();
	b.credit(b1);
	
	b.debit(25000);
	
	CheckingAccount c(a1,500); //transaction fees
	
	c.credit(1000);
	
	c.debit(5000);
	
	
}

		
		

