#include<iostream>
using namespace std;

class Message //message class
{
	private:
		string value;   //private member
	public:
		Message(string value)  //constructor
		{
			this->value=value; //assign the argument string to original string
		}
		void print()            //function with no argument
		{
			cout<<value<<endl;
		}
		void print(string a)  // function that take string as argument
		{
			cout<<a<<value<<endl;
		}
		
};
int main()
{
	Message m1("Object Oriented Programming:");    //object of class
	m1.print();                                    //Calling the print function with no arrgumet
	m1.print("Mid Two Exam ");                    //calling the print function that take argument
}
