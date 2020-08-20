#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int b, ans;
string n;

int main()
{
	cin >> n >> b;

	for ( int i = 0; i < n.length(); i++ )
	{
		int chk = 1;
		if ( '0' <= n[i] && n[i] <= '9' )
		{
			for ( int k = i; k < n.length() - 1; k++ )
				chk *= b;
			ans += (n[i] - '0') * chk;
		}
		else
		{
			for ( int k = i; k < n.length() - 1; k++ )
				chk *= b;
			ans += (n[i] - 'A' + 10) * chk;
		}
	}

	printf("%d\n", ans);
	return 0;
}