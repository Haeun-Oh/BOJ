#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int visit[100001];
int cnt[100001];

queue<int>que;
int func(int num, int x)
{
	if ( x == 0 )
		return num - 1;
	else if (x == 1 )
		return num + 1;
	else
		return 2 * num;
}
void BFS(int start)
{
	que.push(start);
	visit[start] = 1;
	while ( !que.empty() )
	{
		int fz = que.front();
		que.pop();

		for ( int i = 0; i < 3; i++ )
		{
			int nowz = func(fz, i);

			if ( nowz<0 || nowz>100000 )
				continue;
			if ( !visit[nowz]  )
			{
				visit[nowz] = 1;
				que.push(nowz);
				cnt[nowz] = cnt[fz] + 1;
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n>>k;

	BFS(n);
	
	cout << cnt[k] << "\n";

	return 0;
}