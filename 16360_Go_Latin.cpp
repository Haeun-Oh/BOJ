#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string str;

string func(string s, int sSize)
{
	if ( s[sSize - 1] == 'a' )
		s += "s";
	else if ( s[sSize - 1] == 'i' || s[sSize - 1] == 'y' )
	{
		s[sSize - 1] = 'i'; s += "os";
	}
	else if ( s[sSize - 1] == 'l' )
	{
		s += "es";
	}
	else if ( s[sSize - 1] == 'n' )
	{
		s[sSize - 1] = 'a'; s += "nes";
	}
	else if ( s[sSize - 1] == 'e' && s[sSize - 2] == 'n' )
	{
		s[sSize - 2] = 'a'; s[sSize - 1] = 'n'; s += "es";
	}
	else if ( s[sSize - 1] == 'o' )
	{
		s += 's';
	}
	else if ( s[sSize - 1] == 'r' )
	{
		s += "es";
	}
	else if ( s[sSize - 1] == 't' )
	{
		s += "as";
	}
	else if ( s[sSize - 1] == 'u' )
	{
		s += "s";
	}
	else if ( s[sSize - 1] == 'v' )
	{
		s += "es";
	}
	else if ( s[sSize - 1] == 'w' )
	{
		s += "as";
	}
	else
	{
		s += "us";
	} cout << s << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, MAX=0;
	cin >> n;

	while(n-- )
	{
		cin >> str;
		int size = str.size();
		cout << func(str, size)<<"\n";
	}

	return 0;
}
