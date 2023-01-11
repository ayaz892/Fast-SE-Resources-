//Assignment No = 03
//Section =SE-2A
//Std.Id = 20K-1044
//Name = MUHAMMAD AYAZ

#include <stdio.h>
int printSumOf2dInside3d(int *array);
int main()
{
   
    int array[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{2,3,4,5},{6,7,8,9}}};
     int sum= 0;
    
    sum=printSumOf2dInside3d(array);
	
    printf("\nSum of array:%d",sum);
	
    return 0;
}

int printSumOf2dInside3d(int *array)
{
   int i,j,k,sum=0;
   
   for(i=0; i<2 ; i++)
   {
   	
   
   	for(j=0;j<2;j++)
   	{
   		for(k=0;k<=3;k++)
   		{
   			sum = sum + array[i];
   }}}
   
   return sum;
}



