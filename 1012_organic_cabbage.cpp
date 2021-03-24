#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int t, m, n, k, cnt;
int arr[55][55];
int visit[55][55];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int y, int x){
	visit[y][x]=1;
	for(int i=0;i<4;i++){
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		if(nextx<0 || nexty < 0 || nextx>=m||nexty>=n)
			continue;
		if(arr[nexty][nextx]==1 && !visit[nexty][nextx]){
			cnt++;
			dfs(nexty, nextx);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>t;
	while(t--){
		cin>> m >> n >>k;
		vector<pair<int, int>> vec;
		int ans=0;
		for(int i=0; i<n; i++)
    		memset(arr[i], 0, sizeof(int)*m);
		for(int i=0; i<n; i++)
    		memset(visit[i], 0, sizeof(int)*m);
		for(int i=0;i<k;i++){
			int x, y;
			cin>> x>> y;
			arr[y][x] = 1;
			vec.push_back(make_pair(y, x));
		}
		cnt=0;
		for(auto v : vec){
			if(cnt == k)
				break;
			if(!visit[v.first][v.second]){
				dfs(v.first, v.second);
				ans++;
			}
		}
		
		cout <<ans<<"\n";
	}
	return 0;
}
