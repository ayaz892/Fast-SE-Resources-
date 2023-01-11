// ASSIGNMENT=1
//  SE-SEC 2A
// ID=20K-1044
// MUHAMMAD AYAZ


#include<stdio.h>
int main()
{
	int no,m,reverse,remind;
	
	printf("Enter the number:");
	
	scanf("%d",&no);
	
	reverse=0;
	
	for(m=0;m>=0;m++)
	{
		remind=no%10;
		
		reverse=reverse*10+remind;
		no=no/10;
	if(no==0)
		break;
	}
	printf("Reverse of number is:%d",reverse);
}
	
