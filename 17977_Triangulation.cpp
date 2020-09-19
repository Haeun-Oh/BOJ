#include <iostream>
using namespace std;

int n;

int func(int num)
{
	if ( num == 3 )
		return 0;
	else if ( num == 4 )
		return 1;
	else
		return func((num +1) / 2 ) + 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << func(n) << "\n";
	return 0;
}