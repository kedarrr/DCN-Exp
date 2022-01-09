#include<stdio.h>


int count(int arr[],int sz)
{
    int c=0,x;
    for(x=0;x<sz;x++)
    {
        if(arr[x] == 1)
        {
            c++;
        }
    }
    return c;
}

void main()
{
    int sz,i,cnt,n;
    printf("Enter the lenght of string received: ");
    scanf("%d",&sz);
    int arr[sz];
    printf("Enter the string received: ");
    for(i=0;i<sz;i++)
    {
        scanf("%d",&arr[i]);
    }

    //Check No. of 1's
    cnt=count(arr,sz);

    printf("Please select Parity: 1-Even 2-Odd \n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            if(cnt==0)
            {
                printf("Please check Data word.\n");
            }
            else if(cnt%2==0)
            {
                printf("Count of 1's in string is %d.\n",cnt);
                printf("Hence received data word is correct according to Even Parity.\n");
            }
            else
            {
            printf("One Bit error is present in received data for Even Parity.\n");
            }
        }
        break;
    
        case 2:
        {
            if(cnt==0)
            {
                printf("Please check Data word.\n");
            }
            else if(cnt%2!=0)
            {
                printf("Count of 1's in string is %d.\n",cnt);
                printf("Hence received data word is correct according to Odd Parity.\n");
            }
            else
            {
            printf("One Bit error is present in received data for Odd Parity.\n");
            }
        }
        break;

        default :
        printf("please select correct choice.\n");
    }
}