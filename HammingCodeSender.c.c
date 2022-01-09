#include<stdio.h>
#include<math.h>
void main()
{
    int c[8],r[4],h[12];
    int i,j;
    int x,y;
    printf("Enter 8-Bit Binary data: ");
    for(i=0;i<8;i++)
    {
        scanf("%d",&c[i]);
    }
    
    printf("Entered Bits: ");
    for(y=0;y<8;y++)
    {
        printf("%d ",c[y]);
    }
    printf("\n");
    
    r[0]=c[0]^c[1]^c[3]^c[4]^c[6];
    r[1]=c[0]^c[2]^c[3]^c[5]^c[6];
    r[2]=c[1]^c[2]^c[3]^c[7];
    r[3]=c[4]^c[5]^c[6]^c[7];

    printf("Redundent Bits: ");
    for(x=0;x<4;x++)
    {
        printf("%d ",r[x]);
    }
    printf("\n");

    int k=0,l=0,n=0;
    printf("Hamming Code generated: ");
    for(j=0;j<12;j++)
    {
        //if(j == pow(2,n)-1)
        if(j==0 || j==1 || j==3 || j==7)
        {
            h[j]=r[k];
            printf("%d ",h[j]);
            k++;
        }
        else
        {
            h[j]=c[l];
            printf("%d ",h[j]);
            l++;
        }
    }
    printf("\n");
}