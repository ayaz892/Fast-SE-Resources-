#include<iostream>
using namespace std;

class package
{
	//private members of Package classs
	private:
		string name;
		string address;
		string city;
		string state;
		int senderzipcode;
		
		string rec_name;
		string rec_address;
		string rec_city;
		string rec_state;
		int reczipcode;
		
		static double weight;
		//protected so that we can access it outside another class
	protected:
		//static beacuse we want this value to be stored when this class object distroyed
		static double costperounce;
	public:
		package()//Default Constructor
		{
		}
		// parameterized constructor 
		package(string name,string address,string city,string state,int senderzipcode,string rec_name,string rec_address,string rec_city,string rec_state,
		int reczipcode,double weight=0,double costperounce=0)
		{
			
		 //initializing data memebers
			this->name=name;
			this->address=address;
			this->city=city;
			this->senderzipcode=senderzipcode;
			this->state=state;
			this->rec_name=rec_name;
			this->rec_address=rec_address;
			this->rec_city=rec_city;
			this->reczipcode=reczipcode;
			
			this->rec_state=rec_state;
			//weight and cost perounce contain positive values.
			if(costperounce>0)
				this->costperounce=costperounce;
			if(weight>0)
				this->weight=weight;
		}
		
		static double calculatecost(){
			return weight*costperounce;
		}
		void display()
		{
			cout<<"Sender name:"<<name<<"\nSender address:"<<address<<"\nSender city:"<<city<<"\nSender state:"<<state<<"\nSender zipcode:"<<senderzipcode;
			cout<<"\n\nReciever name:"<<rec_name<<"\nReciever address:"<<rec_address<<"\nReciever city:"<<rec_city<<"\nReciever state:"<<rec_state<<"\nReciever zipcode:"<<reczipcode;
		
		}
};
double package::costperounce=0;

double package::weight=0;

class twodaypackage:public package //twodaypackage class is  inherited by package
{
	private:
		double flatfee;
		
	public:
		twodaypackage()
		{
		}
		
		twodaypackage(double flatfee)
		{
			this->flatfee=flatfee;
		}
		
		double calculateCost()
		{
			double cost=package::calculatecost();
			return cost+flatfee;
			
		}
};

class overnightpackage:public package //overnightpackage is inherited by package class 
{
	int additional_fees;
	
	public:
		overnightpackage()
		{
		}
		overnightpackage(int additional_fees)
		{
			this->additional_fees= additional_fees;
		}
			double Calculatecost()
		{
		
			return additional_fees + costperounce;
			
		}
	
	
	
	
	};
	
int main()
	
{
	//objects for each class
	package p("Ayaz","D-78","Karachi","Sindh",1234,"Anas","R-30","Lahore","Punjab",3452,35.4,1300);
	
	p.display();
	
	cout<<"\n\nCost: "<<p.calculatecost()<<endl;
	
	twodaypackage t(500); //value of flatfee
	
	cout<<"Two Day Package Cost:"<<t.calculateCost()<<endl;
	
	overnightpackage o(1000); // value of additional_fees
	
	cout<<"Over night Package Cost: "<<o.Calculatecost();
}
	
	

			
		
		

