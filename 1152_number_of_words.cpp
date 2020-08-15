#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;

char str[1000002];
int main()
{
	fgets(str, sizeof(str), stdin);
	int cnt = 0;
	for ( int i = 0; i< sizeof(str); i++ )
	{
		if ( str[i] == ' ' )
		{
			cnt++;
			if ( i == 0 )
			{
				cnt--;
				if ( str[i + 1] == '\n' ) cnt--;
			}
			else if ( str[i + 1] == '\n' )cnt--;
		}
	}
	printf("%d\n", cnt + 1);
	return 0;
}