#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, m;
int cnt[101][101];
int visit[101][101];
int arr[101][101];

queue<pair<int, int>>que;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void BFS(int x, int y)
{
	que.push(make_pair(x, y));
	visit[x][y] = 1;
	while ( !que.empty() )
	{
		int fx = que.front().first;
		int fy = que.front().second;
		for ( int i = 0; i < 4; i++ )
		{
			int nowx = fx + dx[i];
			int nowy = fy + dy[i];

			if ( nowx<1 || nowy<1 || nowx>n || nowy>m )
				continue;
			if ( !visit[nowx][nowy] && arr[nowx][nowy] == 1 )
			{
				cnt[nowx][nowy] = cnt[fx][fy] + 1;
				visit[nowx][nowy] = 1;
				que.push(make_pair(nowx, nowy));
			}
		}
		que.pop();
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	
	for ( int i = 1; i <= n; i++ )
	{
		string str;
		cin >> str;
		for ( int j = 0; j <str.length(); j++ )
		{
			if ( str[j] == '1' )
				arr[i][j+1] = 1;
			else
				arr[i][j+1] = 0;
		}
	}
	BFS(1, 1);
	cout << cnt[n][m]+1;
	return 0;
}