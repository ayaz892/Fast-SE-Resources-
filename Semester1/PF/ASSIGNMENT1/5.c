// ASSIGNMENT=1
//  SE-SEC 2A
// ID=20K-1044
// MUHAMMAD AYAZ

#include <stdio.h>
int main()

{
	
    int num;
    int sum=0;

    printf("Enter number: ");
    scanf("%d",&num);

    while(num!=0)
    {
        sum=sum+num % 10;
        
        num = num/10;
    }
    
    printf("Sum of digits = %d",sum);
   
}
