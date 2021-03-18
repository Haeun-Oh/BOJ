#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10];
int ans[8];

void recur(int start, int depth){
	if(depth == 7){
		int sum = 0;
		for(int i=0;i<7;i++)
			sum+=ans[i];

		if(sum==100){
			sort(ans, ans+7);
			for(int i=0;i<7;i++)
			cout <<ans[i]<<"\n";
		}
		return;
	}

	for(int i=start;i<9;i++){
		ans[depth] = arr[i];
		recur(i+1, depth+1);
	}
}

int main(void)
{
	for(int i=0;i<9;i++)
		cin>>arr[i];

	recur(0, 0);

 	return 0;
}
