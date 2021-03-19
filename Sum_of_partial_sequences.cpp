#include<iostream>
#include<vector>
using namespace std;
int n, s, arr[20], ans;
void recur(int index,int sum)
{
    if (index == n)
    {
        if (sum == s)
            ans++;
        return;
    }
    // arr[index]를 더할때
    recur(index + 1, sum + arr[index]);
    // 더하지않을 때
    recur(index + 1, sum);
}
int main()
{
    cin.tie(NULL);
	cout.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    recur(0,0);
    if (s == 0) ans--;
    cout << ans << '\n';
}
