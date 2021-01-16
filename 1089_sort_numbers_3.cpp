#include <algorithm>
#include <stdio.h>
using namespace std;
 
int n;
int cnt[10001];
int MAX = 0;
 
int main(void)
{
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ )
    {
        int x;
        scanf("%d", &x);
        cnt[x-1]++;
        MAX = max(MAX, x);
    }
    
    for ( int i = 0; i < MAX; i++ )
    {
        while (cnt[i]!=0 )
        {
            printf("%d\n", i + 1);
            cnt[i]--;
        }
    }
 
    return 0;
}
