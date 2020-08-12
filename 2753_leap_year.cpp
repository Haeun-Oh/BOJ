#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	if ( n % 4 == 0 && (n % 100 != 0 || n % 400 == 0) )
		printf("%d\n", 1);
	else
		printf("%d\n", 0);
}