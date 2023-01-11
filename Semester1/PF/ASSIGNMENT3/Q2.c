//Assignment No = 03
 //Section =SE-2A
 //Std.Id = 20K-1044
 //Name = MUHAMMAD AYAZ
 
#include<stdio.h>
#include<string.h>

int main()
{
	
   char str[30];
   printf("Enter string: ");
   
   gets(str); 
   
   rev(str);
   
}

void rev(char *c)
{
	
	
   if (*c)
   {
       rev(c+1);
       
       printf("%c", *c);
   }
   
}
