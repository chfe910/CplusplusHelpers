
#include <iostream>
using namespace std;

int *f1;
int *f2;
int *l1;
int *l2;

int ff = 0;
int ll = 0;


void FASTEST_WAY(int *a, int *t, int *e, int *x, int n)
{
	f1 = new int [n + 1];
	f2 = new int [n + 1];
	l1 = new int [n + 1];
	l2 = new int [n + 1];
	
	f1[1] = e[1] + a[0 * n + 1];
	f2[1] = e[2] + a[1 * n + 1];

	for (int j = 2; j <= n; ++j)
	{
		if (f1[j - 1] + a[0 * n + j] <= f2[j - 1] + t[1 * n + j - 1] + a[0 * n + j])
		{
			f1[j] = f1[j - 1] + a[0 * n + j];
			l1[j] = 1;
		}
		else
		{
			f1[j] = f2[j - 1] + t[1 * n + j - 1] + a[0 * n + j];
			l1[j] = 2;
		}

		
		if (f2[j - 1] + a[1 * n + j] <= f1[j - 1] + t[0 * n + j - 1] + a[1 * n + j])
		{
			f2[j] = f2[j - 1] + a[1 * n + j];
			l2[j] = 2;
		}
		else
		{
			f2[j] = f1[j - 1] + t[0 * n + j - 1] + a[1 * n + j];
			l2[j] = 1;
		}
	}

	if (f1[n] + x[1] <= f2[n] + x[2])
	{
		ff = f1[n] + x[1];
		ll = 1;
	}
	else
	{
		ff = f2[n] + x[2];
		ll = 2;
	}
}

void PRINT_SOLUTION(int n)
{
	int i = ll;
	cout << "line " << i << ", station " << n << endl;

	for (int j = n; j > 1; --j)
	{
		if (i == 1)
		{
			i = f1[j];
		}
		else
		{
			i = f2[j];
		}
		
		cout << "line " << i << ", station " << j - 1 << endl;
	}
}

void TEST()
{
	int a[2][6 + 1] = {{0, 7, 9, 3, 4, 8, 4}, {0, 8, 5, 6, 4, 5, 7}};
	int t[2][6 + 1] = {{0, 2, 3, 1, 3, 4, 0}, {0, 2, 1, 2, 2, 1, 0}};
	int e[3] = {0, 2, 4};
	int x[3] = {0, 3, 2};
	int n = 6;

	FASTEST_WAY(a[0], t[0], e, x, n);
	PRINT_SOLUTION(n);
}