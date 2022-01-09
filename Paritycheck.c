#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long int result[200];
int dectobin(int n,int j)
{
	int binary=0,mf=1,count=0,no;
	while(n!=0)
	{
		no=(n%2);
		if(no==1)
			count++;
		binary+=(n%2)*mf;
		n=n/2;
		mf=mf*10;
	}
	if(count%2==0)
		{
			result[j]=binary*10+0;
		}
	else
		{
			result[j]=binary*10+1;
		}
	return binary;
}
int main()
{
	char ch[20];
	int i,j,k,l;
	int bin[200];
	printf("Enter the characters: ");
	scanf("%s",ch);
	
	
	for(i=0; i<strlen(ch); i++)
	{
		bin[i]=dectobin((int) ch[i],i);	
	}
	printf("\n Binary Conversion: \n");
	for(k=0; k<strlen(ch); k++)
	{
		printf("\n %d",bin[k]);
	}
	printf("\n Even parity : \n");
	for(l=0; l<strlen(ch); l++)
	{
		printf("\n %ld",result[l]);
	}
	return 0;
}
