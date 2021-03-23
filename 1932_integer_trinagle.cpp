#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int n, ans;
int arr[505][505];
int dp[505][505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			cin>>arr[i][j];
	}
	dp[1][1] = arr[1][1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++)
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
	}
	for(int i=1;i<=n;i++)
		ans = max(ans, dp[n][i]);
	cout <<ans;
	return 0;
}
