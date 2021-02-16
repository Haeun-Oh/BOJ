#include <stdio.h>
#include <cmath>
int n;
int cnt = 0;
int board[15];
int promising(int idx)
{
	for ( int i = 0; i < idx; i++ )
		if ( board[idx] == board[i] || (idx - i == abs(board[idx] - board[i])) )
			return 0;
	return 1;
}
void n_queen(int idx)
{
	if ( idx == n )
	{
		cnt++;
		return;
	}
	for ( int i = 0; i < n; i++ )
	{
		board[idx] = i;
		if(promising(idx) )
			n_queen(idx + 1);
	}
}
int main()
{
	scanf("%d", &n);
	n_queen(0);
	printf("%d", cnt);
}
