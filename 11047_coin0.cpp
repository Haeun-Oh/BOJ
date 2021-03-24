#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int n, k, cnt;
int arr[13];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n >>k;
	for(int i=0;i<n;i++)
		cin>>arr[i];

	for(int i=n-1;i>=0;i--){
		if(k==0)
			break;
		if(arr[i] <= k){
			cnt += k/arr[i];
			k = k%arr[i];
		}
	}
	cout <<cnt;
	return 0;
}
