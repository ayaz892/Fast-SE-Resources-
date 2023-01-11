// ASSIGNMENT=1
//  SE-SEC 2A
// ID=20K-1044
// MUHAMMAD AYAZ

#include<stdio.h>
int main()
{
	int num,i,fact=1;
	printf("Enter number: ");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		fact=fact*i;
	}
		printf("Factorail= %d",fact);
	}
