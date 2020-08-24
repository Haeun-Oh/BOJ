#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> adj;
int n, m, a, b;
int cnt[101];
int visit[101];
void DFS(int now)
{
	visit[now] = 1;
	for ( int i = 0; i < adj[now].size(); i++ )
	{
		if ( !visit[adj[now][i]] )
		{
			cnt[adj[now][i]] = cnt[now] + 1;
			DFS(adj[now][i]);
		}
	}
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cin >> a >> b;
	cin >> m;
	adj.resize(n + 1);
	for ( int i = 0; i < m; i++ )
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	DFS(a);
	if ( cnt[b] == 0 )
		cout << -1;
	else
		cout << cnt[b];
	return 0;
}