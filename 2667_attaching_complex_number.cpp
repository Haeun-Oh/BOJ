#include<cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

int n, num;
int visit[26][26];
int arr[26][26];
int cnt[340];

string str;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visit[y][x] = 1;

	while ( !q.empty() )
	{
		pair<int, int> now = q.front();
		q.pop();

		for ( int i = 0; i < 4; i++ )
		{
			int movy = now.first + dy[i];
			int movx = now.second + dx[i];
			
			if ( movy < 0 || movx < 0 || movx >= n || movy >= n )
				continue;

			if ( (!visit[movy][movx]) && arr[movy][movx]==1 )
			{
				q.push(make_pair(movy, movx));
				visit[movy][movx] = 1;
				cnt[num]++;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		cin >> str;
		for ( int j = 0; j < n; j++ )
		{
			if ( str[j] == '1' )
				arr[i][j] = 1;
		}
	}
	
	for(int i=0;i<n;i++ )
		for ( int j = 0; j < n; j++ )
		{
			if ( arr[i][j] == 1 && visit[i][j] == 0 )
			{
				bfs(i, j);
				num++;
			}
		}

	cout << num<<"\n";
	sort(cnt, cnt + num);
	for ( int i = 0; i < num; i++ )
		cout << cnt[i]+1 << "\n";
	return 0;
}
