#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct mirror
{
	int x, y, dir;
};

int n, ex, ey;
char a[50][50];
int visit[50][50][4];
queue<mirror> que;
const int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };

bool move(int x, int y, int dir)
{
	if ( x < 0 || x >= n || y < 0 || y >= n ) return false;
	if ( visit[x][y][dir] == '*' ) return false;
	return true;
}

void bfs()
{
	while ( !que.empty() )
	{
		int x = que.front().x;
		int y = que.front().y;
		int dir = que.front().dir; 
		que.pop();
		if ( x == ex && y == ey )
		{
			printf("%d\n", visit[x][y][dir]);
			return;
		}
		int nx = x + dx[dir], ny = y + dy[dir];
		while ( move(nx, ny, dir) && a[nx][ny] == '.' )
		{
			nx += dx[dir], ny += dy[dir];
		}
		if ( move(nx, ny, dir) && a[nx][ny] == '!' )
		{
			visit[nx][ny][dir] = visit[x][y][dir];
			que.push({ nx, ny, dir });
			int k = dir < 2 ? 2 : 0;
			for ( int i = k; i<k + 2; i++ )
			{
				if ( visit[nx][ny][i] == -1 )
				{
					visit[nx][ny][i] = visit[x][y][dir] + 1;
					que.push({ nx, ny, i });
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	memset(visit, -1, sizeof(visit));
	for ( int i = 0; i<n; i++ )
	{
		for ( int j = 0; j<n; j++ )
		{
			scanf(" %c", &a[i][j]);
			if ( a[i][j] == '#' )
			{
				if ( que.empty() )
				{
					for ( int k = 0; k<4; k++ )
					{
						que.push({ i, j, k });
						visit[i][j][k] = 0;
					}
				}
				else
				{
					ex = i, ey = j;
				}
				a[i][j] = '!';
			}
		}
	}
	bfs();
	return 0;
}