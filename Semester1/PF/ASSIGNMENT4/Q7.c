//Assignment No = 03
 //Section =SE-2A
 //Std.Id = 20K-1044
 //Name = MUHAMMAD AYAZ
#include<stdio.h>
#include<stdlib.h>
int sumArray(int*,int);
int main(){
	
	int *nums;
	int size;
	int i;
	printf("Enter the size of an array: ");
	scanf("%d",&size);
	nums = (int *) malloc(size * sizeof(int));
	printf("Enter Elements: ");
	for(i=0;i<size;i++){
		scanf("%d",nums+i);
	}
	int sum;
	sum = sumArray(nums,size);
	printf("The sum is: %d",sum);
	
	free(nums);
}
int sumArray(int*n,int s){
	int i,sum=0;
	for(i=0;i<s;i++){
		sum+=*(n + i);
	}
	return sum;
}
