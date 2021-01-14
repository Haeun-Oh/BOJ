#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;
 
int n;
 
int main(void)
{
    scanf("%d", &n);
    int cnt = 0;
    int start = 666;
    while ( 1 )
    {
        string str = to_string(start);
        if ( str.find("666") != -1 )
            cnt++;
        if ( cnt == n )
        {
            printf("%d\n", start);
            break;
        }
        start++;
    }
    
 
    return 0;
}
