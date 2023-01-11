//Assignment No = 03
 //Section =SE-2A
 //Std.Id = 20K-1044
 //Name = MUHAMMAD AYAZ

#include<stdio.h> 
int fibonac(int);

int main()
{    
    int fib,i;

    printf("How many fibonacci series you want: ");
    
    scanf("%d",&fib);       

    for(i=0; i<fib; i++)
    {
        printf("%d ",fibonac(i));
    }

    return 0; 
}

int fibonac(int n)
{    

    
    if(n==0 )
    {
        return n;
    }
    
    else if(n==1)
    {
    	return n;
	}

    else
    {
        
        return fibonac(n-1) + fibonac(n-2);
    }

}


