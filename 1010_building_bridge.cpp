#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int t, n, m;
int dp[35][35];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for(int i=1;i<=30;i++){
		dp[i][i] = 1;
		dp[i][1] = i;
	}

	for(int i=3;i<=30;i++){
		for(int j=2;j<i;j++){
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}

	cin>>t;
	while(t--){
		cin>> n>> m;
		cout <<dp[m][n]<<"\n";
	}
	return 0;
}
