#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	while(t--){
		cin>> n;
		int x, y, ans=1;
		vector<pair<int, int>>vec;
		for(int i=0; i<n; i++){
			cin >> x >> y;
			vec.push_back(make_pair(x, y));
		}
		sort(vec.begin(), vec.end());
		int num = vec[0].second;
		for(int i=1;i<n;i++){
			if(vec[i].second<num){
				ans++;
				num = vec[i].second;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
