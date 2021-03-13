#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n, ans;
 
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if ( a.first == b.first )
        return a.second < b.second;
    else
        return a.first < b.first;
}
 
int main()
{
    scanf("%d", &n);
    vector<pair<int, int>>vec(n);
    int a, b, j=0;
    for ( int i = 0; i < n; i++ )
    {
        scanf("%d %d", &vec[i].second, &vec[i].first);
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    int now = 0;
    
    for ( int i = 0; i < n; i++ )
    {
        if ( now <= vec[i].second )
        {
            ans++;
            now = vec[i].first;
        }
    }
 
    printf("%d\n", ans);
    return 0;
}
