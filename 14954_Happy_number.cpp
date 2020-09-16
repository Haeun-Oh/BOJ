#include <iostream>
using namespace std;

void func(int n)
{
	int a = 0;
	if ( n == 1 )
	{
		cout << "HAPPY\n";;
		return;
	}
	else if(n==4 )
	{
		cout << "UNHAPPY\n";
		return;
	}
	while(n>9 ){
		a += (n%10)*(n%10);
		n = n / 10;
	}
	func(a+n*n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	func(num);

	return 0;
}