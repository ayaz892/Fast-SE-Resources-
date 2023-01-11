//Assignment No = 03
 //Section =SE-2A
 //Std.Id = 20K-1044
 //Name = MUHAMMAD AYAZ
 
#include<stdio.h>

struct point
{
	int x;
	int y;
	
};

float distance(struct point p1,struct point p2)
{
	float x=pow((p2.x - p1.x),2);
	float y=pow((p2.y - p1.y),2);
	float res=sqrt(x+y);
	return res;
}
int main()
{
	struct point p1={1,5},p2={6,7};
	float dis =distance(p1,p2);
	printf("%f",dis);
	
}

