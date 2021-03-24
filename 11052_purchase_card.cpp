#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int n;
int arr[1005];
int dp[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>> n;
	
	for(int i=1;i<=n;i++)
		cin >> arr[i];

	dp[1] = arr[1];
	for(int k = 2;k<=n;k++){
		dp[k] = arr[k];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i+j==k){
					dp[k] = max(dp[k], dp[i]+dp[j]);
				}
			}
		}
	}
	
	
	cout <<dp[n];
	
	return 0;
}
