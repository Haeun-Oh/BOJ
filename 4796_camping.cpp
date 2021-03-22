#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int l, p, v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t=1;
	while(t){
		cin>>l>>p>>v;
		if(l==0 &&p==0&&v==0)
			break;

		cout << "Case "<<t<<": "<<v/p*l + min(v%p, l)<<"\n";
		t++;
	}
	return 0;
}
