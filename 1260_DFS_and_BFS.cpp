#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
queue<int>que;

int n, m;
int visit1[1001];
int visit2[1001];

void DFS(int start)
{
	visit1[start] = 1;
	cout << now << " ";
	for ( int i = 0; i < adj[now].size(); i++ )
	{
		if ( !visit1[adj[now][i]] )
			DFS(adj[now][i]);
	}
}

void BFS(int start)
{
	que.push(start);
	visit2[start] = 1;
	while ( !que.empty() )
	{
		int now = que.front();
		cout << now << " ";
		que.pop();
		for ( int i = 0; i < adj[now].size(); i++ )
		{
			if ( !visit2[adj[now][i]] )
			{
				visit2[adj[now][i]] = 1;
				que.push(adj[now][i]);
			}
		}
	}

}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v;
	cin >> n >>m >>v;
	adj.resize(n + 1);
	for ( int i = 0; i < m; i++ )
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for ( int i = 1; i <= n; i++ )
		sort(adj[i].begin(), adj[i].end());
	DFS(v);
	cout << "\n";
	BFS(v);

	return 0;
}
