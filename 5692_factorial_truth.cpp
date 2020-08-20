#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n;
int arr[6];

int main()
{
	arr[0] = 1;
	for ( int i = 1; i <= 5; i++ )
		arr[i] = i * arr[i - 1];

	while ( 1 )
	{
		int ans = 0, chk = 1;
		scanf("%d", &n);
		if ( n == 0 )
			return 0;
		while ( 1 )
		{
			if ( n == 0 )
				break;
			ans += n % 10 * arr[chk];
			n = n / 10;
			chk++;
		}
		printf("%d\n", ans);
	}
	return 0;
}