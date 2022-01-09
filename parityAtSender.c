#include<stdio.h>

int count(int arr[],int sz)
{
    int c,x;
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
    int sz,i,cnt,ch,j,n;
    printf("Enter string lenght: ");
    scanf("%d",&sz);
    n=sz+1;
    int arr[n];
    printf("Enter Binary Data: ");
    for(i=0;i<sz;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    
    printf("Choose Parity: 1-Even 2-Odd\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1:
        {
            cnt=count(arr,sz);
            if(cnt%2==0)
            {
                arr[sz]=0;
            }
            else
            {
                arr[sz]=1;
            }
            printf("Data to be transfered: ");
            for(j=0;j<sz+1;j++)
            {
                printf("%d ",arr[j]);
            }
        }
        break;

        case 2:
        {
            cnt=count(arr,sz);
            if(cnt%2 == 0)
            {
                arr[sz]=1;
            }
            else
            {
                arr[sz]=0;
            }
            printf("Data to be transfered: ");
            for(j=0;j<sz+1;j++)
            {
                printf("%d ",arr[j]);
            }
        }
        break;

        default :
        printf("please Enter correct option.\n");
    }
}