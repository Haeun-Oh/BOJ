#include <stdio.h>

int main()
{
	int n, c = 0;
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ )
		if ( i < 100 || (i / 100 + i % 10) == (i / 10 % 10 * 2) )
			c++;
	printf("%d", c);
}
