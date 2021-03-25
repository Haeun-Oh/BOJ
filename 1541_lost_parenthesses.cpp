#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

string str;
int ans;
stack<string>st;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>str;
	
	string num = "";
	bool chk = false;

	for(int i=0;i<=str.size();i++){
		if(str[i]=='-' || str[i]=='+' || i==str.size()){
			if(chk) ans-=stoi(num);
			else ans+=stoi(num);
			num = "";
			if(str[i]=='-') chk = true;
		}
		else
			num+=str[i];
	}
	cout <<ans;
	return 0;
}
