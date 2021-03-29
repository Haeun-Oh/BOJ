#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int n;
long long ans;
long long edge[100005];
long long node[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin>> n;
	for(int i=0;i<n-1;i++)
		cin>>edge[i];
	for(int i=0;i<n;i++)
		cin>>node[i];
	long long num = node[0];
	for(int i=0;i<n;i++){
		if(node[i]<num)
			num = node[i];
		ans+=num*edge[i];
	}
	cout<<ans<<"\n";
	return 0;
}
