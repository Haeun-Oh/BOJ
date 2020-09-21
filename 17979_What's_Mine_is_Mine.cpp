#include <stdio.h>;

int n, m;
int price[101], dp[15001], s[10001], e[10001], t[10001], sum[10001];

int main()
{
	scanf("%d %d", &m, &n);

	for ( int i = 1; i <= m; i++ )
		scanf("%d", &price[i]);

	for ( int i = 0; i < n; i++ )
	{
		scanf("%d %d %d", &s[i], &e[i], &t[i]);
		sum[i] = (e[i] - s[i])*price[t[i]];
	}

	for ( int i = 1; i < 15001; i++ )
	{
		dp[i] = dp[i - 1];
		for ( int j = 0; j < n; j++ )
		{
			if ( e[j] == i )
				dp[i] = dp[i] > dp[s[j]] + sum[j] ? dp[i] : dp[s[j]] + sum[j];
		}
	}

	printf("%d", dp[15000]);
	return 0;
}