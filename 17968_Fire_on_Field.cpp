#include <stdio.h>

int n, A[1001];

bool isPossible(int i)
{
	for ( int k = 1; i - 2 * k >= 0; k++ )
	{
		if ( A[i] == 2 * A[i - k] - A[i - 2 * k] )
		{
			return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d", &n);

	A[0] = A[1] = 1;
	for ( int i = 2; i <= n; i++ )
	{
		for ( int val = 1; ; val++ )
		{
			A[i] = val;
			if ( isPossible(i) )
			{
				break;
			}
		}
	}

	printf("%d\n", A[n]);
}