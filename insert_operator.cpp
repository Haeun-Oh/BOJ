#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[11];
int op[4]; //+, -, *, /
int n, MAX = -10000000000, MIN = 10000000000;

void func(int plus, int minus, int multiply, int divide, int cnt, int sum)
{
	if ( cnt == n )
	{
		MAX = max(MAX, sum);
		MIN = min(MIN, sum);
	}

	if ( plus > 0 )
		func(plus - 1, minus, multiply, divide, cnt + 1, sum + arr[cnt]);
	if ( minus > 0 )
		func(plus, minus-1, multiply, divide, cnt + 1, sum - arr[cnt]);
	if ( multiply > 0 )
		func(plus, minus, multiply-1, divide, cnt + 1, sum * arr[cnt]);
	if ( divide > 0 )
		func(plus, minus, multiply, divide-1, cnt + 1, sum / arr[cnt]);
}

int main(){
	scanf("%d", &n);
	for ( int i = 0; i < n; i++ )
		scanf("%d", &arr[i]);
	for ( int i = 0; i < 4; i++ )
		scanf("%d", &op[i]);
	func(op[0], op[1], op[2], op[3], 1, arr[0]);

	printf("%d\n%d", MAX, MIN);
	return 0;
}
