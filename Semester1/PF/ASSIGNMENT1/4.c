// ASSIGNMENT=1
//  SE-SEC 2A
// ID=20K-1044
// MUHAMMAD AYAZ

#include <stdio.h>

int main()

{
	int num,i,j;
	
	for (i = 0;i<5;i++)
	{
		printf("Enter numbers: ");
		
		scanf("%d", &num);
		
		if(num>30)
		break;
		
		for (j = 0;j<num;j++)
		{
			printf("*");
		}
		
		printf("\n");
		
	}
	
}
