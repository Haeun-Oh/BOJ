#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, MAX;
int arr[101];

int main()
{
	scanf("%d %d", &n, &m);
	for ( int i = 0; i < n;i++ )
		scanf("%d", &arr[i]);

	for ( int i = 0; i < n-2; i++ )
	{
		for ( int j = i + 1; j < n-1; j++ )
		{
			for ( int k = j + 1; k < n; k++ )
			{
				if ( arr[i] + arr[j] + arr[k] <= m )
					MAX = max(MAX, arr[i] + arr[j] + arr[k]);
			}
		}
	}
	
	printf("%d\n", MAX);

	return 0;
}
