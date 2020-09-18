#include <iostream>
#include <string>
using namespace std;

int n;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while(n-- )
	{
		cin >> str;
		if ( str.back() == 'a' )
			str += "s";
		else if ( str.back() == 'i' || str.back() == 'y' )
		{
			str.pop_back();
			str += "ios";
		}
		else if ( str.back() == 'l' )
			str += "es";
		else if ( str.back() == 'n' )
		{
			str.pop_back();
			str += "anes";
		}
		else if ( str.back() == 'e' && str[str.size() - 2] == 'n' )
		{
			str[str.size() - 2] = 'a'; 
			str[str.size() - 1] = 'n'; 
			str += "es";
		}
		else if ( str.back() == 'o' )
			str += "s";
		else if ( str.back() == 'r' )
			str += "es";
		else if ( str.back() == 't' )
			str += "as";
		else if ( str.back() == 'u' )
			str += "s";
		else if ( str.back() == 'v' )
			str += "es";
		else if ( str.back() == 'w' )
			str += "as";
		else
			str += "us"; 
		cout << str << '\n';
	}

	return 0;
}
