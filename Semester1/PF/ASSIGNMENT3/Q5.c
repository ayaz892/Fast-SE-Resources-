//Assignment No = 03
 //Section =SE-2A
 //Std.Id = 20K-1044
 //Name = MUHAMMAD AYAZ
#include<stdio.h>
void calculateResult(float[]);
int _t;
int main(){
	float results[100];
	printf("Enter total subjects: ");
	scanf("%d",&_t);
	int counter;
	for(counter=0;counter<_t;counter++){
		scanf("%f",&results[counter]);
	}
	printf("\n");
	calculateResult(results);
}
void calculateResult(float res[]){
	int _c;
	for(_c=0;_c<_t;_c++){
		
		if(res[_c]>=90 && res[_c]<=100)
		
			printf("A-one Grade.\n");
			
		else if(res[_c]>=80 && res[_c]<90)
		
			printf("A+ Grade.\n");
			
		else if(res[_c]>=70 && res[_c]<80)
		
			printf("A Grade.\n");
			
		else if(res[_c]>=60 && res[_c]<70)
		
			printf("B Grade.\n");
			
		else if(res[_c]>=50 && res[_c]<60)
		
			printf("C Grade.\n");
			
		else if(res[_c]>=0 && res[_c]<50)
		
			printf("F Grade.\n");
	}
}














