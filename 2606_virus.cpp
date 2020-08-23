#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int n, m, cnt;
vector<vector<int>> adj; // vector <int> adj[101]; ÀÌ¶û °°´Ù.
queue<int>que;
int visit[101];

void BFS(int start)
{
	que.push(start);
	visit[start] = 1;
	while ( !que.empty() )
	{
		int now = que.front();
		que.pop();
		for ( int i = 0; i < adj[now].size(); i++ )
		{
			if ( !visit[adj[now][i]] )
			{
				visit[adj[now][i]] = 1;
				que.push(adj[now][i]);
				cnt++;
			}
		}
	}

}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	adj.resize(n + 1);
	cin >> m;
	for ( int i = 0; i < m; i++ )
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	BFS(1);
	cout << cnt;

	return 0;
}