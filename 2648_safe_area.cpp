#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;

int n, MAX, cnt, ans;
int visit[101][101];
int arr[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void DFS(int x, int y, int rain)
{
	visit[x][y] = 1;
	for ( int k = 0; k < 4; k++ )
	{
		int nowx = x + dx[k];
		int nowy = y + dy[k];
		if ( nowx < 0 || nowy < 0 || nowx>=n || nowy>=n )
			continue;
		if ( !visit[nowx][nowy] && arr[nowx][nowy] > rain )
			DFS(nowx, nowy, rain);
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
		for ( int j = 0; j < n; j++ )
		{
			cin >> arr[i][j];
			MAX = max(MAX, arr[i][j]);
		}
	}
	for ( int i = 0; i <= MAX; i++ )
	{
		cnt = 0;
		for ( int w = 0; w < n; w++ )
			memset(visit[w], 0, sizeof(int)*n);

		for ( int j = 0; j < n; j++ )
		{
			for ( int k = 0; k < n; k++ )
			{
				if ( !visit[j][k] && arr[j][k] > i )
				{
					DFS(j, k, i);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";

	return 0;
}