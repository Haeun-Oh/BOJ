#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;
 
int n, m, cnt;
int a[55][55];
int b[55][55];
 
void fliped(int y, int x){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(a[y+i][x+j]) a[y+i][x+j] = 0;
            else a[y+i][x+j] = 1;
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &a[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &b[i][j]);
        }
    }
    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            if(a[i][j]!=b[i][j]){
                cnt++;
                fliped(i, j);
            }
        }
    }
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] != b[i][j]){
                printf("%d", -1);
                return 0;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
