#include <iostream>
#include <algorithm>
using namespace std;

int n;
int t[16];
int p[16];
int dp[16]; // dp[i] : i일까지 얻는 이익

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int MAX = 0;
	cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> t[i] >> p[i];
		dp[i] = p[i];
	}

	for ( int i = 2; i <= n; i++ )
	{
		for ( int j = 1; j < i; j++ )
		{
			if(i-j>=t[j] )
				dp[i] = max(dp[j] + p[i], dp[i]);
		}
	}

	for ( int i = 1; i <= n; i++ )
	{
		if ( i + t[i] <= n + 1 )
		{
			if ( MAX < dp[i] )
				MAX = dp[i];
		}
	}
	cout <<  MAX;
	return 0;
}