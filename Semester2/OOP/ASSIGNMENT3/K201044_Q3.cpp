#include<iostream>
using namespace std;

class Vehicle //vehicle class
{
	string type_of_car,color,miles_driven;
	
	int model,year;
	
	public:
	Vehicle(string type_of_car,string color,string miles_driven,int year,int model )//peramterize constructor
	{
		this->type_of_car=type_of_car;
		this->color=color;
		this->miles_driven=miles_driven;
		this->model=model;
		this->year=year;
	}
	//accssesor functions
	string get_type()
	{
		return type_of_car;
	}
	string get_color()
	{
		return color;
	}
	string get_miles()
	{
		return miles_driven;
	}
	int get_model()
	{
		return model;
	}
	
	int get_year()
	{
		return year;
	}
	
	
};
class GasVehicle:public Vehicle //Gasvehicle class which inherit class vehicle
{
	string fuel_size;
	
	public:
		GasVehicle(string t,string c,string m,int y,int m1,string fuel_size):Vehicle(t,c,m,y,m1) //permatrize constructor
		{
			this->fuel_size=fuel_size;
		}
		//Accssesor function
		string get_fuel()
		{
			return fuel_size;
		}
		
};
class ElectricVehicle:public Vehicle //electricvehicle class 
{
	string energy_storage;
	
	public:
		ElectricVehicle(string t,string c,string m,int y,int m1,string energy_storage):Vehicle(t,c,m,y,m1)
		{
			this->energy_storage=energy_storage;
		}
		string get_energy()
		{
			return energy_storage;
		}
};
class HighPerformance:public GasVehicle //High performance class
{
	string horse_power;
	string top_speed;
	
	public:
		HighPerformance(string t,string c,string m,int y,int m1,string f,string horse_power,string top_speed):GasVehicle(t,c,m,y,m1,f)
		{
			this->horse_power=horse_power;
			this->top_speed=top_speed;
		}
		string get_power()
		{
			return horse_power;
		}
		string get_speed()
		{
			return top_speed;
		}
		
};
class HeavyVehicle:public GasVehicle //Heavy vehicle class
{
	string max_weight;
	int wheels;
	int length;
	
	public:
		HeavyVehicle(string t,string c,string m,int y,int m1,string f,string max_weight,int wheel,int length):GasVehicle(t,c,m,y,m1,f)
		{
			this->max_weight=max_weight;
			this->wheels=wheels;
			this->length=length;
		}
		string get_weight()
		{
			return max_weight;
		}
		int get_wheels()
		{
			return wheels;
		}
		int get_length()
		{
			return length;
		}
		
};
class SportsCar:public HighPerformance //sports car class
{
	string gearbox,drive_system;
	
	public:
		SportsCar(string t,string c,string m,int y,int m1,string f,string h,string t1,string gearbox,string drive_system):HighPerformance(t,c,m,y,m1,f,h,t1)
		{
			this->gearbox=gearbox;
			this->drive_system=drive_system;
		}
		string get_gearbox()
		{
			return gearbox;
		}
		string get_drive()
		{
			return drive_system;
		}
};
class ConstructionTruck:public HeavyVehicle //constructiontruck class
{
	string cargo;
	
	public:
		ConstructionTruck(string t,string c,string m,int y,int m1,string f,string mw,int w,int l,string cargo):HeavyVehicle(t,c,m,y,m1,f,mw,w,l)
		{
			this->cargo=cargo;
			
		}
		string get_cargo()
		{
			return cargo;
		}
};
class Bus:public HeavyVehicle //Bus vehicle
{
	int no_of_seats;
	
	public:
		Bus(string t,string c,string m,int y,int m1,string f,string mw,int w,int l,int seat):HeavyVehicle(t,c,m,y,m1,f,mw,w,l)
		{
			no_of_seats=seat;
		}
		//display function to print all the information
		void display()
		{
			cout<<"Type of car="<<get_type()<<"\ncolor="<<get_color()<<"\nmiles drive="<<get_miles()
			<<"\nyear="<<get_year()<<"\nmodel="<<get_model()<<"\nFuel_size="<<get_fuel()
			<<"\nMax wight="<<get_weight()<<"\nWheels="<<get_wheels()<<"\nlength of vehicle in mm="<<get_length()
			<<"\nNo of seats="<<no_of_seats;
		}
};
int main()
{
	Bus b1("4X4","Blue","5024 miles",2010,2007,"51 litres","4094 pound",4,5330,5);//obj of bus class
	
	b1.display();//calling display function
	
	
}

