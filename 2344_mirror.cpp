#include <stdio.h>
#include <cstring>
int n, m;
int arr[1005][1005];
int num[1005][1005];
int ans[4010];

// a==1이면 위로 또는 오른쪽으로 이동, a==-1이면 아래로 또는 왼쪽으로 이동
// b==1이면 가로, b==0이면 세로로 이동
void move(int x, int y, int a, int b, int cnt)
{
	int dx[] = { -1 * a, 0 }, dy[] = { 0, 1 * a };
	while ( arr[x][y] != -1 )
	{
		if ( arr[x][y] == 1 )
			b = (b + 1) % 2;
		x += dx[b], y += dy[b];
	}
	ans[cnt] = num[x][y];
}

int main()
{
	scanf("%d %d", &n, &m);
	memset(arr, -1, sizeof(arr)); // 입력 받지 않은 부분을 구분하기 위해서 -1로 초기화

	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= m; j++ )
			scanf("%d", &arr[i][j]);
		
	for ( int i = 1; i <= n; i++ )
	{
		num[i][0] = i; // 왼쪽
		num[n-i+1][m + 1] = n+m+i; // 오른쪽
	}

	for ( int i = 1; i <= m; i++ )
	{
		num[n+1][i] = n + i; // 아래
		num[0][m -i+1] = 2 * n + m + i; // 위 
	}

	for ( int i = 1; i <= n; i++ )
	{
		move(i, 1, 1, 1, num[i][0]);
		move(i, m, -1, 1, num[i][m + 1]);
	}

	for ( int i = 1; i <= m; i++ )
	{
		move(n, i, 1, 0, num[n + 1][i]);
		move(1, i, -1, 0, num[0][i]);
	}

	for ( int i = 1; i <= 2 * (n + m); i++ )
		printf("%d ", ans[i]);

	return 0;
}