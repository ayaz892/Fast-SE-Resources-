//QUESTION #3:	
1-ENTITIES:
	
*COMPANY HEAD
*NO OF EMPLOYEES
*ELECTRICITY
*REGIONAL OFFICE



2-RELEVANCE WITH THE OTHERS:

A COMPANY MANAGES THE REGIONAL OFFICES WHO IN TURN IS MANAGED BY THE HEADS


TASK 3:
	
	class Company{
		private:
		string ceo;
		int No_Of_RegionalOffices;
		int No_of_Heads;
		int Total_No_Of_Employees;
		public:
		void MonthlyOffice_ManageReport{ //method for monthly management check of heads by ceo
			
		}
		void No_Of_Visits{ //method for number of times ceo has to visit regional offices
			
		}
		explicit Company(){//constructor of Company class
			//Name of ceo
			//Number of Regional office
			//Number of Heads
			//Total Employes
		
			
		}
	};
	
class Head
{
	private:
	string name;
	double salary;
	public:
		explicit Head() //constructor for head class
		{
			//name of Employes
			//Gender
			//Salary of employes
		
		}
	
};
class  Regional office
{
	float expense;
	float profit;
	float sales;
	public:
		void set_Expense(float expense) //setter function for expense
		{
		}
		float get_Expense() //getter function for expense
		{
		  return expense;
		}
		void set_Profit(float profit) //setter function for profit
		{
		}
		float get_Expense() //getter function for profit
		{
		  return expense;
     	}
     	void set_Sale(float sale) //setter function for sale
		{
		}
		float get_Sale() //getter function for sale
		{
		  return sales;
		  
		explicit Regional office() //constructor for regional office class
		{
		  //Sales 
		  //Profit
		  //Expense
	
};

