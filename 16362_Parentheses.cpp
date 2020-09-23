#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack <char> st;
int alp, oper, p_left, p_right;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, str);

	for ( int i = 0; i < str.length(); i++ )
	{
		if ( str[i] != ' ' )
			st.push(str[i]);
	}

	char a;
	while ( !st.empty() )
	{
		a = st.top();
		if ( a >= 'a' && a <= 'z' )
			alp++;
		else if ( a == '*' || a == '/' || a == '%'  || a=='+' ||a=='-')
			oper++;
		else if ( a == '(' )
			p_left++;
		else
			p_right++;

		st.pop();
	}
	if ( alp == 1 )
		cout << "proper\n";
	else if ( alp - 1 != oper || p_left != p_right )
		cout << "error\n";
	else if ( alp-2 != p_left)
		cout << "improper\n";
	else
		cout << "proper\n";
	return 0;
}
