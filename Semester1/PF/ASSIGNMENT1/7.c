
// ASSIGNMENT=1
//  SE-SEC 2A
// ID=20K-1044
// MUHAMMAD AYAZ

#include<stdio.h>
int main()
{
	int income;
	float tax;
	printf("Enter yearly income:");
	scanf("%d",&income);
	if(income<=400000)
	{
		tax=income*0/100;
		printf("Tax percentage =%.2f",tax);
	}
	else 
	if((income==400001)&&(income<=600000))
	{
		tax=income*2/100;
		printf("Tax percentage =%.2f",tax);
	}
	else
    if((income==600001)&&(income<=800000))
	{
		tax=income*5/100;
		printf("Tax percentage =%.2f",tax);
	}
	else 
	if((income==800001)&&(income<=1000000))
	{
		tax=income*7/100;
		printf("Tax percentage =%.2f",tax);
		
	}
	else 
	if(income>=1000001)
	{
		tax=income*9/100;
		printf("Tax percentage =%.2f",tax);
	}
	}
	
	
