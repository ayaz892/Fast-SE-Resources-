#include <stdio.h>
#include <string.h>

int main() {

    char str[100];
    int i,flag=0;
    
    	
    	scanf("%s", &str[i]);
    	
	char dup[101];
	int j;
	for(j=0;j<strlen(str)-1;j++)
	{
		if((j+1)%2==0)
		{
			dup[j]=str[j]-32;
			
		}
		else
		{
			dup[j]=str[j];
		}
		
		}
		printf("\n");
		for(j=0;j<strlen(dup);j++)
	{
		if((j+1)%2==0)
		{
			if(str[j]-32==dup[j])
			{
				flag=1;
			}
			}
		}
		if(flag==1)
		{
			printf("NO");
		}
		else
		{
			printf("YES");
			
		}

    
	
    
    return 0;
}
