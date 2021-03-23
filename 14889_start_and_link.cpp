#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int n, ans=987654321;
int s[25][25];
int visit[25];

void dfs(int player, int cnt){
	if(cnt == n/2){
		vector<int> start, link;
		for(int i=0;i<n;i++){
			if(visit[i])
				start.push_back(i);
			else
				link.push_back(i);
		}
		int total_start=0, total_link=0;
		for(int i=0;i<n/2;i++){
			for(int j=i+1;j<n/2;j++){
				int sx = start[i], sy = start[j];
				int lx = link[i], ly = link[j];
				total_start += s[sx][sy] + s[sy][sx];
				total_link += s[lx][ly] + s[ly][lx];	
			}
		}
		ans = min(ans, abs(total_start - total_link));
		return;
	}
	for(int i=player+1;i<n;i++){
		if(!visit[i]){
			visit[i] = 1;
			dfs(i, cnt+1);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>s[i][j];
	}
	
	dfs(0, 0);

	cout <<ans;

	return 0;
}
