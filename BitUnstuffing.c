#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    char bstr[60],str[60];
    int n,i=0,j=0,c=0,k=0;
    printf("Enter the Received String: ");
    scanf("%s",bstr);
    printf("Flag taken in process: 11111\n");
    n=strlen(bstr);

    while(i<n)
    {
        if(bstr[i]=='1')
        {
            c++;
        }
        else
        {
            c=0;
        }
        if(c<=5)
        {
            str[j]=bstr[i];
            j++;
            i++;
            
        }
        if((c+1)==6)
        {
            if(bstr[i]=='0')
            {
                i++;
            }
            else
            {
                printf("Error at %d bit.\n",i+1);
                exit(0);
            }
            c=0;
        }
    }
    str[j]='\0';
    printf("String after Unstufing: %s",str);
}