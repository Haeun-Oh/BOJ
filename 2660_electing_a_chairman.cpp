#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
using namespace std;
#define INF 55
 
int n;
int dis[55][55];
int ans[55];
 
int main()
{
    vector<int>vec;
    scanf("%d", &n);
    int x, y;
    memset(dis, INF, sizeof(dis));
    while(1){
        scanf("%d %d", &x, &y);
        if(x==-1 && y==-1)
                break;
        dis[x][y]=dis[y][x]=1;
    }
 
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            int MAX = 0;
            for(int j=1;j<=n;j++){
                if(dis[i][j] >dis[i][k]+dis[k][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                continue;
                ans[i] = max(ans[i], dis[i][j]);
        }
    }
    int MIN = INF;
    for(int i=1;i<=n;i++){
        MIN = min(MIN, ans[i]);
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==MIN)
            vec.push_back(i);
    }
 
    printf("%d %d\n", MIN, vec.size());
    for(auto v:vec)
        printf("%d ", v);
    return 0;
}
