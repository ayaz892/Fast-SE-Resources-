//Assignment No = 03
 //Section =SE-2A
 //Std.Id = 20K-1044
 //Name = MUHAMMAD AYAZ
 
#include<stdio.h>
void printString(char**);
int main()
{
	char *strings[5]={"Programming Fundamental","Object Oriented Programming"
	,"Software Engineering"
	}; 
	
	printString(strings);
}
 
void printString(char**st){
	int i;
	for (i=0;i<5;i++){
		printf("%s\n",st[i]);
	}
}
