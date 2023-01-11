//Assignment No = 03
 //Section =SE-2A
 //Std.Id = 20K-1044
 //Name = MUHAMMAD AYAZ


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void SortString(char str[])
{
	int len=strlen(str) , i , words=1 ;
	
	for(i=0;i<len;i++)
		if(str[i]==' ')
			words++;
			
	int j , k=0 , word_len[words] , temp; 
	char temp1 , **arr=(char **)malloc(words*sizeof(char));
	
	for(i=0;i<words;i++)
		arr[i]=(char *)malloc(20*sizeof(char));
	
	for(i=0;i<words;i++,k++)
		for(word_len[i]=0,j=0;j<20;j++,k++,word_len[i]++)
			if(str[k]==' ' || k==len)
				break;
			else
				arr[i][j]=str[k];
	
	for(i=0;i<words;i++)
		for(j=0;j<words;j++)
			if (word_len[i]>word_len[j])
			{
				temp=word_len[j];
				word_len[j]=word_len[i];
				word_len[i]=temp;
				for(k=0;k<20;k++)
				{
					temp1=arr[i][k];
					arr[i][k]=arr[j][k];
					arr[j][k]=temp1;
				}
			}
			
	for(i=0;i<words;i++)
	{
		for(j=0;j<word_len[i];j++)
			printf("%c" , arr[i][j]);
		printf("\n");
	}
}
int main()
{
	char *str=malloc(sizeof(char)); 
	int i;
	
	puts("Enter a String: ");
	gets(str);
	
	SortString(str);
}
