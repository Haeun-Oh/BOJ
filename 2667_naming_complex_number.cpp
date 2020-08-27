#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, ans;
int cnt[900];
int visit[30][30];
int arr[30][30];

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

			if ( nowx<0 || nowy<0 || nowx>=n || nowy>=n )
				continue;
			if ( !visit[nowx][nowy] && arr[nowx][nowy] == 1 )
			{
				cnt[ans]++;
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
	cin >> n;
	
	for ( int i = 0; i < n; i++ )
	{
		string str;
		cin >> str;
		for ( int j = 0; j <n; j++ )
		{
			if ( str[j] == '1' )
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			if ( arr[i][j] == 1 && !visit[i][j] )
			{
				BFS(i, j);
				ans++;
			}
		}
	}
	sort(cnt, cnt + ans);
	cout << ans<<"\n";
	for ( int i = 0; i < ans; i++ )
		cout << cnt[i]+1<<"\n";
	return 0;
}