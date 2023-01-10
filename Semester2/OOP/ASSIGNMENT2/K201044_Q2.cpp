#include <iostream>

using namespace std;

class clothes
{
     string ID;
     float revenue;
    public:
     clothes(string ID,float revenue)
     {
         this->ID=ID;
         this->revenue=revenue;
     }
     
   
};
class shirt:public clothes
{
    string design;
    float price;
    string i;
    float r;
    public:
     shirt(string design,float price):clothes(i,r)
     {
         this->design=design;
         this->price=price;
         
     }
     void calculate()
     {
         cout<<"shirt price is: "<<price;
     }
};
class pant:public clothes
{
    string style;
    float price;
    string i;
    float r;
    int choice;
    public:
     pant(string style,float price):clothes(i,r)
     {
         this->style=style;
         this->price=price;
         
     }
     void pantt()
     {
       cout<<"Pant style:\n1-bell-bottomed\n2-straight fit\n3-narrow fit"<<endl;
          cin>>choice;
        if(choice==1)
        {
            price=1200;
        }
        else if(choice==2)
        {
            price=1600;
        }
        else if(choice==3)
        {
            price=2000;
        }
     }
};
class tie:public clothes
{
    string pattern;
    float price;
     string i;
     float r;
     int choice;
    public:
     tie(string pattern,float price):clothes(i,r)

     {
         this->pattern=pattern;
         this->price=price;
     }
     void tiee()
     {
        cout<<"tie style\n1-striped\n2-checks"<<endl ;
        cin>>choice;
       
        if(choice==1)
        {
            price=700;
        }
        else if(choice==2)
        {
            price=800;
        }
     }
};
 class suit:public shirt,public pant,public tie
 {
     float price;
     public:
      suit(float price)
      {
          this->price=price;
      }
 }
int main()
{
    pant p;
    p1.void pantt();

}
