#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <functional>

#define inf 987654321

using namespace std;

int time;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> time;
	if ( time % 10 != 0 )
	{
		cout << -1;
	}
	else
	{
		cout << time / 300 << " ";
		time %= 300;
		cout << time / 60 << " ";
		time %= 60;
		cout << time / 10;
	}
	
}
