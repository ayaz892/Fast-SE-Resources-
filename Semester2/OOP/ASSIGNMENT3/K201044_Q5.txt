#include<iostream>
using namespace std;
class person        //person class
{
	char name[30];
	int id,salary;
	public:
		virtual void getdata() //get info of employee
		{
			cout<<"Enter name of the employee:";
			cin>>name;
			cout<<"Enter Employee id:";
			cin>>id;
			cout<<"Enter the Employee Salary:";
			cin>>salary;
		}
		virtual void display_data() //display info of employee
		{
			cout<<"\nName of the Employee:"<<name<<endl;
			cout<<"Id:"<<id<<endl;
			cout<<"salary of the Employee:"<<salary<<endl;
		}
		virtual void bonus() //calculate bonus of employee
		{
			
			int b=salary*0.5; //add 5% bonus in salary
			int total=0;
			
			
			cout<<"\nYou got the bonus of Rs: "<<b<<endl;
			total=b+salary;
			cout<<"Total salary after bonus:"<<total<<endl;
		}
		
};
class admin:virtual public person   //admin class
{
	char name[30];
	int salary;
	public:
		void getdata()       //get info of admin
		{
			cout<<"\nEnter the name of the admin:";
			cin>>name;
			cout<<"Enter the salary of admin:";
			cin>>salary;
		}
		void display_data() //display info of admin
		{
			cout<<"\nName of the admin:"<<name<<endl;
			cout<<"salary of the admin:"<<salary<<endl;
		}
		void bonus() //calculate bonus
	{
			int b=salary*0.6; //add 6% bonus in admin salary
			int total=0;
			
			
			cout<<"\nYou got the bonus of Rs:"<<b<<endl;
			total=b+salary;
			cout<<"Total salary after bonus:"<<total<<endl;
		
	}

};
class account:virtual public person //account class 
{
	char name[30];
	int salary;
	public:
		void getdata() //get info of accountant
		{
			cout<<"\nEnter the accountant name :";
			cin>>name;
			cout<<"Enter the salary of accountant:";
			cin>>salary;
		}
			void display_data() //isplay info of accountant
		{
			cout<<"\nName of the accountant:"<<name<<endl;
			cout<<"salary of the accountant: "<<salary<<endl;
		}
		void bonus() //calculate bonus
	{
			int b=salary*0.3; //add 3% bonus into salary
			int total=0;
			
			
			cout<<"\nYou got the bonus of Rs: "<<b<<endl;
			total=b+salary;
			cout<<"Total salary after bonus:"<<total<<endl;
		
	}
		
		
 };
 class master:public admin,public account //master class 
 { 
 	char name[30];
 	int salary;
 	public:
 			void getdata() //get info of master
		{
			cout<<"\nEnter the master name:";
			cin>>name;
			cout<<"Enter the salary of master:";
			cin>>salary;
		}
			void display_data() //display info of master
		{
			cout<<"\nName of the master:"<<name<<endl;
			cout<<"salary of the master: "<<salary<<endl;
		
		}
		void bonus() //calculate bonus
	{
			int b=salary*0.7; //add 7% bonus into salary
			int total=0;
			
			
			cout<<"\nYou got the bonus of Rs "<<b<<endl;
			total=b+salary;
			cout<<"Total salary after bonus:"<<total<<endl;
		
	}
  }; 
int main()
{
	person *p,p1; //pointer and object of class person
	p=&p1;     //assign the address of person obj to the pointer
	p->getdata(); // take the info of employe
	p->display_data(); //display the info of employe
	p->bonus();        //calculate and display the bonus of employe
	admin a1;          // object of admin class
	p=&a1;              //assign the address of admin obj to the pointer of person class
	p->getdata();      // take the info of admin
	p->display_data(); //display the info of admin
	p->bonus();         //calculate and display the bonus of admin
	account a2;        // object of accountant class
	p=&a2;             //assign the address of accountant obj to the pointer of person class
	p->getdata();      // take the info of accountant
	p->display_data(); //display the info of accountant
	p->bonus();        //calculate and display the bonus of accountant
	master m;          // object of master class
	p=&m;              //assign the address of master obj to the pointer of person class
	p->getdata();      // take the info of master
	p->display_data(); //display the info of master
	p->bonus();         //calculate and display the bonus of master
}

