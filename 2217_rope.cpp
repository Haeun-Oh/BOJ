#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int n;
int arr[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr, arr+n);
	int ans = arr[n-1];
	for(int i=0;i<n;i++){
		ans = max(ans, arr[i]*(n-i));
	}
	cout <<ans;
	return 0;
}
