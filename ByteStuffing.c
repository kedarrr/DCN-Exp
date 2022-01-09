#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    int i,j=0,n,c=0;
    char str[50],Bstr[70];
    printf("Enter string: ");
    scanf("%s",str);
    printf("Flag: 11111 & Escape Character: $\n");
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
        if(str[i]=='$')
        {
            Bstr[j]='$';
            j++;
        }
        Bstr[j]=str[i];
        j++;
        if(c==5)
        {
           Bstr[j]='$';
           j++;
           c=0;
        }
    }
    Bstr[j]='\0';
    printf("String to send: %s",Bstr);
}