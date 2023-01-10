#include<iostream>
using namespace std;

class Invoice     //class that repreesent invoice for item
{ 
	string partno,partdesc;
	int quantity;
	double priceperitem;
	public:
	    Invoice() //constructor that initialize the data item
	    {
		    partno="";
		    partdesc="";
		    quantity=0;
		    priceperitem=0.0;
	    }
	    //Setter and getter functions below:
	    void setpartno();
	    string getpartno();
	    void setpartdesc();
	    string getpartdesc();
	    void setquantity();
	    int getquantity();
	    void setpriceperitem();
	    double getpriceperitem();
	    double getinvoiceamount();
};
void Invoice::setpartno()
{
	cout<<"Enter part number:";
	getline(cin,partno);
}
string Invoice::getpartno()
{
	return partno;
}
void Invoice:: setpartdesc()
{
	cout<<"Enter part description:";
	
	getline(cin,partdesc);
} 
string Invoice:: getpartdesc()
{
	return partdesc;
}
void Invoice::setquantity()
{
	cout<<"Enter the quantity of the item:";
	
	cin>>quantity;
	
	if(quantity<0)
	{
		quantity=0;
	}
}
int Invoice::getquantity()
{
	return quantity;
}
void Invoice::setpriceperitem()
{
	cout<<"Enter the price per item:";
	
	cin>>priceperitem;
	
	if(priceperitem<0)
	{
		priceperitem=0;
	}
}
double Invoice::getpriceperitem()
{
	return priceperitem;
}
double Invoice::getinvoiceamount() //calculate invoice amount
{
	double amount;
	
	amount=quantity*priceperitem;
	
	return amount;
	
}
int main()
{
	Invoice a;
	
	a.setpartno();
	
	a.setpartdesc();
	
	a.setquantity();
	
	a.setpriceperitem();
	
	cout<<"Part no->"<<a.getpartno()<<endl;
	
	cout<<"Descritpion->"<<a.getpartdesc()<<endl;
	
	cout<<"Quantity->"<<a.getquantity()<<endl;
	
	cout<<"Price Per Item->"<<a.getpriceperitem()<<endl;
	
	cout<<"Total invoice->"<<a.getinvoiceamount()<<endl;
	
}
