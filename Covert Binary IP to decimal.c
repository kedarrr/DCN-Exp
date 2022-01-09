#include <stdio.h>
#include <math.h>
int bintodec(int num);
int main()
{
    char ip[50];
    int dec[4],bin[4],i;
    printf("Enter the IP Address in binary:");
    gets(ip);
    sscanf(ip,"%d %d %d %d",&bin[0],&bin[1],&bin[2],&bin[3]);
    printf("%d %d %d %d",bin[0],bin[1],bin[2],bin[3]);
    for(i=0;i<4;i++)
    {
        dec[i]=bintodec(bin[i]);
    }
    sprintf(ip,"%d.%d.%d.%d",dec[0],dec[1],dec[2],dec[3]);
    printf("\nIP in Decimal=");
    puts(ip);
}
int bintodec(int num)
{
    int rem,dec=0;
    for (int i=0; num!=0; i++)  
    {  
        rem=num%10;  
        num=num/10;  
        dec=dec+(rem)*( pow (2,i));  
    }      
    return dec;
}