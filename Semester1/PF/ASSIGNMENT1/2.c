// ASSIGNMENT=1
//  SE-SEC 2A
// ID=20K-1044
// MUHAMMAD AYAZ

#include <stdio.h>
int main()


	{

	int num=0,small=0,no=0,i=0;

	printf("How many number you want to enter?: ");

	scanf("%d",&num);

	printf("Enter number : ");

	scanf("%d",&no);

	small=no;

	for(i=1; i<num;i++)

		{

		printf("Enter a Number : ");

		scanf("%d",&no);

		if(no<small)

		small=no;

		}

	printf("The smallest number is : %d",small);

	

	}


