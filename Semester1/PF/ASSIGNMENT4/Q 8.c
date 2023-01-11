//Assignment No = 03
 //Section =SE-2A
 //Std.Id = 20K-1044
 //Name = MUHAMMAD AYAZ
 
#include<stdio.h>
#include<string.h>
struct student
{
	char Name[30];
	char sec;
	char course[40];
	
	
	
};
int main()
{
	struct student s1;

	printf("Enter name of student: ");
	
	gets(s1.Name);
	
	printf("Enter Section: ");
	scanf("%c",&s1.sec);

	
	printf("Enter course name: ");
	scanf("%s",s1.course); 

	
	
	
	printf("\nName: %s\nSec: %c\nCourse: %s",s1.Name,s1.sec,s1.course);

}
