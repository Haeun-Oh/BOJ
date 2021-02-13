#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int main()
{
	scanf("%d", &n);
	int l, r, ans=0;
	l = r = -1e9 - 1;
	while(n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if ( a > r )
		{
			ans += (r - l);
			l = a, r = b;
		}
		else
			r = max(r, b);
	}	
	ans += (r - l);
	printf("%d\n", ans);
	return 0;
}
