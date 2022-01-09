#include <stdio.h>

int check(int *data, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (data[i] != 0 && data[i] != 1)
		{
			return -1;
		}
	}
	return 1;
}

int syndrome(int *list, int size, int divs)
{
	int i;
	for (i = size; i <= size - divs; i++)
	{
		if (list[i] != 0)
		{
			return -1;
		}
	}
	return 1;
}

int main()
{
	int data[100], code[100], i = 0, j = 0, k = 0, l, size, divisor[50], choice;
	printf("1.Send dataword\n2.reviever end\n");
	while (1)
	{
		printf("\n\nEnter Choice : \t");
		scanf("%d", &choice);

		switch (choice)
		{
			// case 0:
			// 	break;

		case 1:
			printf("\nEnter the size of data :\t");
			scanf("%d", &size);

			printf("\nEnter the data :\t");
			for (i = 0; i < size; i++)
			{
				scanf("%d", &data[i]);
			}

			k = check(&data[0], size);

			if (k == -1)
			{
				printf("\nEntered Data is Incorrect");
				break;
			}

			printf("\nEnter the size of divisor :\t");
			scanf("%d", &l);

			printf("\nEnter the divisor :\t");
			for (i = 0; i < l; i++)
			{
				scanf("%d", &divisor[i]);
			}
			i = 0;

			k = check(&divisor[0], l);
			if (k == -1)
			{
				printf("\nEntered Divisor is Incorrect");
				break;
			}

			// sender side

			for (i = 0; i < size; i++)
			{
				code[i] = data[i];
			}

			for (i = size; i < size + l - 1; i++)
			{
				code[i] = 0;
			}

			for (i = 0; i < size; i++)
			{
				k = i;
				if (code[i] == 1)
				{
					for (j = 0; j < l; j++)
					{
						code[k] = code[k] ^ divisor[j];
						k++;
					}
				}
			}

			for (i = 0; i < size; i++)
			{
				code[i] = data[i];
			}

			printf("Sending string.......");
			for (i = 0; i < size + l - 1; i++)
			{
				printf("%d", code[i]);
			}

			break;

		case 2:

			// Receiver side
			printf("Enter The Size Of Codeword :\t");
			scanf("%d", &size);
			printf("Enter Received Codeword :\t");
			for (i = 0; i < size; i++)
			{
				scanf("%d", &code[i]);
			}
			printf("\nEnter size of divisor : \t");
			scanf("%d", &l);

			printf("Enter The Divisor :\t ");
			for (i = 0; i < l; i++)
			{
				scanf("%d", &divisor[i]);
			}

			for (i = 0; i <= size - l; i++)
			{
				code[i] = data[i];
			}

			k = check(&code[0], size);
			if (k == -1)
			{
				printf("\nEnter correct codeword .");
				break;
			}

			k = check(&divisor[0], l);
			if (k == -1)
			{
				printf("\nEnter correct Divisor.");
				break;
			}

			for (i = 0; i <= size - l; i++)
			{
				k = i;

				if (code[i] == 1)
				{
					for (j = 0; j < l; j++)
					{
						code[k] = code[k] ^ divisor[j];
						k++;
					}
				}
			}

			k = syndrome(&code[0], size, l);
			if (k == -1)
			{
				printf("\nReceived Data is with Error.");
			}
			if (k == 1)
			{
				printf("\nReceived Data is Datafree.");
				printf("\nData is ....\n");
				for (i = 0; i <= size - l; i++)
				{
					printf("%d", data[i]);
				}
			}

			break;

		default:
			printf("\nEnter Correct Choice");
		}
		if (choice == 0)
		{
			break;
		}
	}
	printf("\nThank You");
	return 0;
}
