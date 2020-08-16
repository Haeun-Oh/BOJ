#include <stdio.h>

int n;
int dp[1005];

int main()
{
	scanf("%d", &n);
	dp[0] = 1;
	for ( int i = 0; i < n; i++ ){
		int num;
		scanf("%d", &num);

		if ( dp[i] == 0 )
			break;

		for ( int j = 1 ; (j <= num) && ((i+j)<=1000); j++ )
		{
			if ( dp[i + j] > dp[i] + 1 || dp[i + j] == 0 )
				dp[i + j] = dp[i] + 1;
		}
	}
	if ( dp[n - 1] == 0 )
		printf("-1\n");
	else
		printf("%d\n", dp[n - 1]-1);
	return 0;
}