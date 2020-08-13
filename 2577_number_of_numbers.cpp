#include <stdio.h>
int arr[10];

int main()
{
	int a, b, c, mul=1;
	scanf("%d %d %d", &a, &b, &c);

	mul = a * b*c;

	while ( mul > 0 )
	{
		arr[mul%10]++;
		mul = mul / 10;
	}

	for(int i=0;i<10;i++ )
		printf("%d\n", arr[i]);

	return 0;
}