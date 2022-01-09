#include<stdio.h>
#include<string.h>
void main()
{
    int i,j=0,n,c=0;
    char str[50],bstr[100];
    printf("Enter the Binary string to send: ");
    scanf("%s",str);
    printf("Flag used is process: 11111\n");
    n=strlen(str);

    for(i=0;i<n;i++)
    {
        if(str[i]=='1')
        {
            c++;
        }
        else
        {
            c=0;
        }
        if(c<5)
        {
            bstr[j]=str[i];
            j++;
        }
        if(c==5)
        {
            bstr[j]=str[i];
            j++;
            bstr[j]='0';
            j++;
            c=0;
        }
    }
    bstr[j]='\0';
    printf("String converted by Bitstuffing: ");
    printf("%s",bstr);
}