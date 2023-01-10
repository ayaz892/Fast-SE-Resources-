#include<iostream>

using namespace std;

class matrixType //class declaration
{
	int array[3][3]; //array declaration
	
	public:
		 
	friend istream& operator>>(istream&, matrixType&);//initialize the input operator through friend function
	
	friend ostream& operator<<(ostream&, matrixType&);// initialize the output operator through friend function
	
	matrixType operator +(matrixType a) //overload the +operator for matrix addition
		{
			int temp[3][3];
			
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					temp[i][j]=array[i][j]+a.array[i][j];
				}
			}
			
			cout<<"matrix after addition:\n";
			
			for(int i=0;i<3;i++)
			{
				
				for(int j=0;j<3;j++)
				{
					
					cout<<temp[i][j]<<"\t";
					
				}
				
				cout<<"\n";
			}
		}
	matrixType operator -(matrixType b) //overload the - operator for matrix subtraction
		{
			int temp[3][3];
			
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					temp[i][j]=array[i][j]-b.array[i][j];
				}
			}
			
			cout<<"matrix after Subtraction:\n";
			
			for(int i=0;i<3;i++)
			{
				
				for(int j=0;j<3;j++)
				{
					cout<<temp[i][j]<<"\t";
				}
				cout<<"\n";
			}
		}
		
		matrixType operator *(matrixType c)  //overload the *operator for matrix multiplication
			{
			int temp[3][3];
			
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					for(int k=0;k<3;k++)
					{
						temp[i][j]=temp[i][j]+array[i][k]*c.array[k][j];
				}
				}
			}
			
			cout<<"matrix after multiplication:\n";
			
			for(int i=0;i<3;i++)
			{
				
				for(int j=0;j<3;j++)
				{
					cout<<temp[i][j]<<"\t";
				}
				
				cout<<"\n";
			}
		}
			
};
	 istream& operator>>(istream &din, matrixType &a) //declaration of friend funtion for input stream operator overloading
	 

	{
			cout<<"Enter matrix element:\n";
			
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					
					cin>>a.array[i][j];
				}
			}
		}

ostream& operator<<(ostream &dout,matrixType &c)//declaration of friend function for output operator overloading
{
	for(int i=0;i<3;i++)
			{
			
				for(int j=0;j<3;j++)
				{
					cout<<c.array[i][j]<<"\t";
				}
				
				cout<<"\n";
		
		
	}
}
int main()
{
	matrixType m1,m2; //object of class matrixType
	
	cin>>m1; //input the matrix1
	
	cin>>m2; //input the matrix 2
	
	cout<<"first matrix:\n";
	
	cout<<m1;           //display the matrix 1
	
	cout<<"second matrix:\n";
	cout<<m2;             //display the matrix 2
	

	
	m1+m2;          //+operator
	m1-m2;         //-operator
	m1*m2;          //*operator
    	
}


