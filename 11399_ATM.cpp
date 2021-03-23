#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int n, total;
int p[1005];
int ans[1005];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>p[i];
	sort(p, p+n);
	ans[0] = p[0];
	total = ans[0];
	for(int i=1;i<n;i++){
		ans[i]=ans[i-1] + p[i];
		total+=ans[i];
	}
	cout <<total;
	return 0;
}
