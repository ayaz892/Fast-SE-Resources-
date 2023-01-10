#include<iostream>
#include<math.h>
using namespace std;

class HealthProfile{ //health profile that contains all the health info of person
	string first,last;
	int  day,year,month;
	int height,weight;
	string gender;
	int rate,agee,bmi=0;
	
	public:
		void FirstName() //first name of the person
		{
			cout<<"Enter first name: ";
			cin>>first;
		}
		void LastName()  //last name of the person
		{
			cout<<"Enter last name:";
			cin>>last;
		}
		void Gender()   //Gender of a person
		{
			cout<<"what is your gender:";
			cin>>gender;
			
		}
		void BirthMonth() //Date of Birth of a person
		{
			cout<<"Enter your date of Birth M/D/Y: ";
			cin>>month>>day>>year;
		}
		void Height()   //Height of a person
		{
			cout<<"enter your height in inches:";
			cin>>height;
		}
		void Weight()   //weight of a person
		{
			cout<<"Enter your weight:";
			cin>>weight;
		}
		void age()    //calculate age of a person
		{
			agee=2021-year;
		}
		void max_heart() //Calculate maximum heart rate of a person
		{
			rate=220-agee;
		}
		void BMI()
		{
			bmi=(weight*703)/(height*height);
		}
		string getfirst()  //getter function for first name
		{
			return first;
		}
		string getlast()   //getter function for last name
		{
			return last;
		}
		string getgender() //getter function for gender
		{
			return gender;
		}
		
		int getHeight()  //getter function for height
		{
			return height;
		}
		int getweight()   //getter function for weight
		{
			return weight;
		}
		int getage()      //getter function for age
		{
			return agee;
		}
		int getheart()    //getter function for heart rate
		{
			return rate;
		}
		int getbmi()     //getter function for bmi
		{
			return bmi;
		}
		
		
		
		
};
int main()
{
	HealthProfile p; //created object of class HealthProfile
	p.FirstName(); //calling first name
	p.LastName(); //calling last name
	p.Gender();   //calling gender of person
	p.BirthMonth();//calling person's age
	p.Height();    //calling height of a person
	p.Weight();    //calling weight of person
	p.age();       //calling age of a person
	p.max_heart(); //calling maximum heart rate
	p.BMI();
	 
	//printing all the information below:
	cout<<"---------------------------------"<<endl;
   cout << "First Name:"<<p.getfirst()<<"\n";
   
   cout << "Last Name: " << p.getlast() << "\n";
   
   cout << "Gender: " << p.getgender()<< "\n";
   
   cout<<"Height:"<<p.getHeight()<<"\n";
   
   cout<<"Weight:"<<p.getweight()<<"\n";
   
   cout<<"your age is:"<<p.getage()<<"\n";
   
   cout <<"Maximum Heart Rate:"<<p.getheart()<<endl;
   
   cout<<"Your BMI is: "<<p.getbmi()<<endl;
   
   cout<<"\n\tBMI VALUES"<<endl;
   cout<<"------------------------------"<<endl;
   cout<<"Less then 19 : Underweight "<<endl<<"19 - 25      : Average "<<endl<<"25 - 30      : Overweight"<<endl<<">30          : Obese"<<endl;
   

}


