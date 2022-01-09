 #include<stdio.h>


    int arr[8],crc[12],gen[5]={1,0,0,1,1},temp[12];
    int i,j,k,l;

    void to_binary(int a)
    {
	 for(i=6;i>=0;i--)
	 {
	    arr[i]=a%2;
	    a=a/2;
	 }
	 printf("\nThe binary equivalent of given character is :");
	 for(i=0;i<7;i++)
	 printf("%d",arr[i]);
    }

    void to_crc()
    {
	printf("\n\nFrame after adding 4 zeros at the end for Dataword: ");
	for(i=0;i<11;i++)
	{
	    if(i>6)
	    crc[i]=0;
	   else
		crc[i]=arr[i];
	}
	for(i=0;i<11;i++)
	{
	    printf("%d",crc[i]);
	    temp[i]=crc[i];
	}
		 //EX-ORING
	printf("\n\nFrame Generated after applying CRC Tech. : ");
	k=0;
	for(i=0;i<7;i++)
	{
	    if(temp[i]==1)
	    {
		for(j=i;j<i+5;j++)
		{
		    temp[j]=temp[j]^gen[k];
		    k++;
		    //printf("%d",crc[j]);
		}
	    }
	    k=0;
	    //printf("\n");
	}
	 //ADDING REMAINDER TO THE FRAME
	for(i=7;i<11;i++)
	crc[i]=temp[i];
	 //DISPLAYING THE FRAME
	for(i=0;i<11;i++)
	printf("%d",crc[i]);
    }

    void to_send()
    {
	printf("\n\nSending the bits: ");
	for(i=0;i<11;i++)
	{
	    	    printf("%d",crc[i]);
	}
    }


    int main()
    {
	char ch;
	int asc;
	printf("\n\n\tCRC (Cycic Redundancy Check - Error Detection Tech.)\n");
	printf("\nEnter the character for CRC transmission: ");
	scanf("%c",&ch);
	asc=(int)ch;
	to_binary(asc);
	to_crc();
	to_send();
    return 0;
    }
