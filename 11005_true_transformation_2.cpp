#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int>vec;
int n, b, ans;

int main()
{
	cin >> n >> b;
	while ( n != 0 )
	{
		vec.push_back(n%b);
		n = n / b;
	}
	for ( int i = vec.size()-1; i >=0; i-- )
	{
		if ( vec[i] <= 9 )
			printf("%d", vec[i]);
		else
			printf("%c", vec[i] - 10 + 'A');
	}
	return 0;
}