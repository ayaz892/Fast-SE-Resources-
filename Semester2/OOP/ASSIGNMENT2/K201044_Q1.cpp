#include<iostream>
using namespace std;
class A
{
	int x;
	public:
		//constructorr for class A for initializing value of x
	A(int x):x(x){
	}
};
class B:public A
{
	int y;
	public:
			//constructorr for class B for initializing value of y
	B(int x,int y):y(y),A(x){
	}
};
class C:public B
{
	int z;
	public:
			//constructorr for class A for initializing value of z
	C(int x,int y,int z):z(z),B(x,y)
	{
		cout<<x<<" "<<" "<<y<<" "<<z;
	}
};
int main()
{
	C obj(2,5,12); // obj of class c through which we can also access members of class B and A
	
}
