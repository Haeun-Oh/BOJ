#include <stdio.h>

int func(int x, int y)
{
	if ( x%y == 0 )
		return y;
	else
		return func(y, x%y);
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", func(a, b));
	printf("%d\n", a*b / func(a, b));
}