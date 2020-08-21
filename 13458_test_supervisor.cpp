#include <iostream>
#include <algorithm>

using namespace std;

int n, b, c;
long long ans = 0;
int arr[1000001];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for ( int i = 1; i <= n; i++ )
		cin >> arr[i];
	cin >> b >> c;
	for ( int i = 1; i <= n; i++ )
	{
		ans++;
		arr[i] = arr[i] - b;
		if ( arr[i] > 0 )
		{
			if ( arr[i] / c == 0 )
				ans++;
			else if ( arr[i] / c != 0 && arr[i] % c == 0 )
				ans = ans + arr[i] / c;
			else
				ans = ans + arr[i] / c + 1;
		}
	}
	cout << ans;

	return 0;
}