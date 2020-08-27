#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, h, cnt, ans, total, days;
int visit[101][101][101];
int arr[101][101][101];

struct tomato
{
	int hz, nx, my, day;
};

queue<tomato>que;

int dz[6] = { 1, -1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 0, 0, 0, 0, 1, -1 };

void BFS()
{
	while ( !que.empty() )
	{
		int fz = que.front().hz;
		int fx = que.front().nx;
		int fy = que.front().my;
		int fday = que.front().day;
		visit[fz][fx][fy] = 1;
		que.pop();

		for ( int i = 0; i < 6; i++ )
		{
			int nowz = fz + dz[i];
			int nowx = fx + dx[i];
			int nowy = fy + dy[i];

			if ( nowx<0 || nowy<0 || nowz<0|| nowx>=n || nowy>=m|| nowz>=h )
				continue;
			if ( !visit[nowz][nowx][nowy] && arr[nowz][nowx][nowy] == 0 )
			{
				arr[nowz][nowx][nowy] = 1;
				visit[nowz][nowx][nowy] = 1;
				que.push({ nowz, nowx, nowy, fday+1 });
				total++;
				days = max(days, fday + 1);
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m>> n>>h;

	for ( int k = 0; k < h; k++ )
	{
		for ( int i = 0; i < n; i++ )
		{
			for ( int j = 0; j < m; j++ )
			{
				cin >> arr[k][i][j];
				if ( arr[k][i][j] == -1 )
					cnt++;
				else if ( arr[k][i][j] == 1 )
				{
					que.push({ k, i, j, 0 });
					ans++;
				}
			}
		}
	}

	BFS();

	if ( n*m*h - cnt == ans )
		cout << 0 << "\n";
	else if ( n*m*h - cnt == total+ans )
		cout << days<<"\n";
	else
		cout << -1 << "\n";
	return 0;
}