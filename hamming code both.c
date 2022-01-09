#include <stdio.h>
#include <math.h>

void parity_bit(int *d, int *p)
{
	p[0] = d[0] ^ d[1] ^ d[3] ^ d[4] ^ d[6];
	p[1] = d[0] ^ d[2] ^ d[3] ^ d[5] ^ d[6];
	p[2] = d[1] ^ d[2] ^ d[3] ^ d[7];
	p[3] = d[4] ^ d[5] ^ d[6] ^ d[7];
}

void parity_insert(int *code, int *p)
{
	int i, j = 0;

	for (i = 0; i < 4; i++)
	{
		j = pow(2, i) - 1;
		code[j] = p[i];
	}
}

void generate_code(int *code, int *d)
{
	int i, j = 0, k = 0;
	for (i = 0; i < 12; i++)
	{
		if (i != pow(2, j) - 1)
		{
			code[i] = d[k];
			k++;
		}
		else
		{
			j++;
		}
	}
}
int check(int *data)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		if (data[i] != 0 && data[i] != 1)
		{
			return -1;
		}
	}
	return 1;
}

void dataword(int *code, int *data)
{
	int i, j = 0, k = 0;
	for (i = 0; i < 12; i++)
	{
		if (i != pow(2, j) - 1)
		{
			data[k] = code[i];
			k++;
		}
		else
		{
			j++;
		}
	}
}
int error_pos(int *syn)
{
	int re = 0;
	int i;
	for (i = 0; i < 4; i++)
	{
		re = re + pow(2, i) * syn[i];
	}
	return re;
}

void error_correcting(int *code, int *syn)
{
	int pos;
	pos = error_pos(&syn[0]);
	printf("\nPosition of is %d", pos);
	if (code[pos - 1] == 1)
	{
		code[pos - 1] = 0;
	}
	else
	{
		if (code[pos - 1] == 0)
		{
			code[pos - 1] = 1;
		}
	}
}

int main()
{
	int d[8], parity[4], code[12], i, data[8], s, pos, syndrome[4], choice;
	while (1)
	{
		printf("\n\n1.sender\t2.Receiver\t0.Exit\nEnter the Choice :");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			printf("Thank you.");
			return 0;

		case 1:

			// sender
			printf("Enter the Dataword of 8 bit : \t");

			for (i = 0; i < 8; i++)
			{
				scanf("%d", &d[i]);
			}
			i = check(&d[0]);
			if (i == -1)
			{
				printf("Enter Correct Data.");
				return 0;
			}
			parity_bit(&d[0], &parity[0]);
			parity_insert(&code[0], &parity[0]);
			generate_code(&code[0], &d[0]);
			printf("Sending code are .....\n");
			for (i = 0; i < 12; i++)
			{
				printf("%d\t", code[i]);
			}
			break;

		case 2:

			// receiver

			printf("enter the 12 bit codeword : \t");
			for (i = 0; i < 12; i++)
			{
				scanf("%d", &code[i]);
			}
			i = check(&code[0]);
			if (i == -1)
			{
				printf("Enter Correct Data.");
				return 0;
			}
			syndrome[0] = code[0] ^ code[2] ^ code[4] ^ code[6] ^ code[8] ^ code[10];
			syndrome[1] = code[1] ^ code[2] ^ code[5] ^ code[6] ^ code[9] ^ code[10];
			syndrome[2] = code[3] ^ code[4] ^ code[5] ^ code[6] ^ code[11];
			syndrome[3] = code[7] ^ code[8] ^ code[9] ^ code[10] ^ code[11];

			for (s = 0; s < 4; s++)
			{
				if (syndrome[s] != 0)
				{
					break;
				}
			}
			if (s != 4)
			{
				printf("Entered data is with Error.");
				error_correcting(&code[0], &syndrome[0]);
				dataword(&code[0], &data[0]);
			}

			if (s == 4)
			{
				printf("Received Data is Error-free");
				dataword(&code[0], &data[0]);
			}

			printf("\nData is .....");
			for (i = 0; i < 8; i++)
			{
				printf("%d", data[i]);
			}
			break;

		default:
			printf("Enter Correct Choice");
		}
	}
}
