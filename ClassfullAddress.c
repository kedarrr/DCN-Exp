#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    int ip[4],i;
    char class;

    printf("Enter the IP address in dotted decimal form: ");
    scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);

    for(i = 0; i < 4; i++)
	{
		if(ip[i] > 255)
		{
			printf("\nEntered IP address is invalid!!\n");
			exit(0);
		}
	}

    if(ip[0]>=0 && ip[0]<=127)
    {
        printf("Given IP belongs to Class A.\n");
        class='A';
    }

    else if(ip[0]>=128 && ip[0]<=191)
    {
        printf("Given IP belongs to Class B.\n");
        class='B';
    }

    else if(ip[0]>=192 && ip[0]<=223)
    {
        printf("Given IP belongs to Class C.\n");
        class='C';
    }

    else if(ip[0]>=224 && ip[0]<=239)
    {
        printf("Given IP belongs to Class D.\n");
        class='D';
    }

    else if(ip[0]>=240 && ip[0]<=255)
    {
        printf("Given IP belongs to Class E.\n");
        class='E';
    }

    if(class=='A')
    {
        printf("NetID is %d\n",ip[0]);
        printf("HostID is %d.%d.%d\n",ip[1],ip[2],ip[3]);
        printf("Default mask is 255.0.0.0\n");
    }
    else if(class=='B')
    {
        printf("NetID is %d.%d\n",ip[0],ip[1]);
        printf("HostID is %d.%d\n",ip[2],ip[3]);
        printf("Default mask is 255.255.0.0\n");
    }
    else if(class=='C')
    {
        printf("NetID is %d.%d.%d\n",ip[0],ip[1],ip[2]);
        printf("HostID is %d\n",ip[3]);
        printf("Default mask is 255.255.255.0\n");
    }
    else if(class=='D' || class=='E')
    {
        printf("There is no NetID, HostID, Default mask for Class D and Class E.\n");
    }
}