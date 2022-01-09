#include <stdio.h>
#include <math.h>
int checking(char *ip)
{
	int i = 0, c = 0, s = 0;
	while (ip[i] != '\0')
	{
		if (ip[i] == '.')
		{
			c++;
		}
		if (ip[i] == '/')
		{
			s++;
		}
		i++;
	}
	if (c == 3 && s == 1)
	{
		return 1;
	}
	return -1;
}

int validity(int a, int b, int c, int d, int n)
{
	if (a <= 255 && b <= 255 && c <= 255 && d <= 255 && n <= 32)
	{
		return 1;
	}
	else
	{
		printf("Check the Ip Address first");
		return -1;
	}
}

int dectobi(int n)
{
	int rem;
	rem = n % 2;
	return rem;
}

int bitodec(int n, int i)
{
	return pow(2, i) * n;
}

void finding_first(int *aa, int *bb, int *cc, int *dd, int *first)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		first[i] = aa[i] && first[i];
		first[i + 8] = bb[i] && first[i + 8];
		first[i + 16] = cc[i] && first[i + 16];
		first[i + 24] = dd[i] && first[i + 24];
	}
}

void finding_last(int *aa, int *bb, int *cc, int *dd, int *last)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		last[i] = aa[i] || last[i];
		last[i + 8] = bb[i] || last[i + 8];
		last[i + 16] = cc[i] || last[i + 16];
		last[i + 24] = dd[i] || last[i + 24];
	}
}

void Display(int f1, int f2, int f3, int f4, int l1, int l2, int l3, int l4)
{
	int i;
	printf("First Address is :\t%d.%d.%d.%d", f1, f2, f3, f4);
	printf("\nLast Address is :\t%d.%d.%d.%d", l1, l2, l3, l4);
}

int main()
{
	char ip[19];
	int a, b, c, d, check, i = 0, j, f1 = 0, f2 = 0, f3 = 0, f4 = 0, l1 = 0, l2 = 0, l3 = 0, l4 = 0;
	unsigned int n;
	int aa[8], bb[8], cc[8], dd[8], first[32], last[32];
	while (1)
	{
		printf("\nAre you want to Continue : \n press \n1.Continue 0. Stop");
		scanf("%d", &i);
		if (i == 0)
		{
			printf("Thank You");
			return 0;
		}
		for (i = 0; i < 8; i++)
		{
			aa[i] = 0;
			bb[i] = 0;
			cc[i] = 0;
			dd[i] = 0;
		}
		i = 0;

		printf("\n\nEnter Ip Address : \t");
		scanf("%s", ip);
		check = checking(&ip[0]);
		if (check == -1)
		{
			printf("\nEntered Ip Address is Wrong.");
			continue;
		}
		sscanf(ip, "%d.%d.%d.%d/%d", &a, &b, &c, &d, &n);
		for (i = 0; i < 32; i++)
		{
			if (i < n)
			{
				first[i] = 1;
				last[i] = 0;
			}
			else
			{
				first[i] = 0;
				last[i] = 1;
			}
		}

		check = validity(a, b, c, d, n);
		if (check == -1)
		{
			printf("\nEntered Ip Address is Wrong.");
			continue;
		}
		for (j = 7; a > 0 || b > 0 || c > 0 || d > 0; j--)
		{
			aa[j] = dectobi(a);
			bb[j] = dectobi(b);
			cc[j] = dectobi(c);
			dd[j] = dectobi(d);
			a = a / 2;
			b = b / 2;
			c = c / 2;
			d = d / 2;
		}
		j = 7;

		finding_first(&aa[0], &bb[0], &cc[0], &dd[0], &first[0]);
		finding_last(&aa[0], &bb[0], &cc[0], &dd[0], &last[0]);
		for (i = 0; i < 8; i++)
		{
			f1 = bitodec(first[i], j) + f1;
			f2 = bitodec(first[i + 8], j) + f2;
			f3 = bitodec(first[i + 16], j) + f3;
			f4 = bitodec(first[i + 24], j) + f4;
			l1 = bitodec(last[i], j) + l1;
			l2 = bitodec(last[i + 8], j) + l2;
			l3 = bitodec(last[i + 16], j) + l3;
			l4 = bitodec(last[i + 24], j) + l4;
			j--;
		}
		
		Display(f1, f2, f3, f4, l1, l2, l3, l4);
		n = pow(2, (32 - n));
		printf("\nNumbers of Adderesses in Class is %ld", n);
	}
}
