#include <stdio.h>
#include <cstring>
int n, m;
int arr[1005][1005];
int num[1005][1005];
int ans[4010];

// a==1�̸� ���� �Ǵ� ���������� �̵�, a==-1�̸� �Ʒ��� �Ǵ� �������� �̵�
// b==1�̸� ����, b==0�̸� ���η� �̵�
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
	memset(arr, -1, sizeof(arr)); // �Է� ���� ���� �κ��� �����ϱ� ���ؼ� -1�� �ʱ�ȭ

	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= m; j++ )
			scanf("%d", &arr[i][j]);
		
	for ( int i = 1; i <= n; i++ )
	{
		num[i][0] = i; // ����
		num[n-i+1][m + 1] = n+m+i; // ������
	}

	for ( int i = 1; i <= m; i++ )
	{
		num[n+1][i] = n + i; // �Ʒ�
		num[0][m -i+1] = 2 * n + m + i; // �� 
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