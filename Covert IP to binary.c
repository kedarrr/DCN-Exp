#include<stdio.h>
int dectobin(int num);
int main()
{
    char ip[50];
    int dec[4],b[4],i;
    printf("Enter the IP Address:");
    gets(ip);
    sscanf(ip,"%d.%d.%d.%d",&dec[0],&dec[1],&dec[2],&dec[3]);
    printf("%d %d %d %d",dec[0],dec[1],dec[2],dec[3]);
    for(i=0;i<4;i++)
    {
        b[i]= dectobin(dec[i]);
    }
    sprintf(ip,"%d %d %d %d",b[0],b[1],b[2],b[3]);
    printf("\nIP in binary=");
    puts(ip);
}
int dectobin(int num)
{
    int b=0,mf=1;
    while(num>0)
    {
        b=b+(num%2)*mf;
        num=num/2;
        mf=mf*10;   
    }
    return b;
}