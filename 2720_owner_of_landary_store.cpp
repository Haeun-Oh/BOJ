#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int t, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// Q: 25, D: 10, N: 5, P: 1 
	cin >> t;
	
	while(t--){
		cin>>c;
		cout <<c/25<<" ";
		c = c%25;
		cout <<c/10 <<" ";
		c = c%10;
		cout << c/5 <<" ";
		c = c%5;
		cout <<c<<"\n";
	}
	return 0;
}
