#include <stdio.h>
#include <math.h>

int main() {
    int t,sum1,sum2;
    scanf("%d\n", &t);
    while (t--) {
        int Ri, Rs, Ti, Ts, X;
        scanf("%d %d %d %d %d", &Ri, &Rs, &Ti, &Ts, &X);
        
        sum1=Ri+Rs;
        sum2=Ti+Ts;
    }
   
   if(sum1>sum2)
{
	printf("Turtle");
}
else if(sum1<sum2)
{
	printf("Rabbit");
}
else if(sum1==sum2)
{
	printf("Turtle\nDraw");
}}



  
