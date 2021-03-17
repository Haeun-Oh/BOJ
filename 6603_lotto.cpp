#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
int arr[15];
int lotto[6];

void recur(int idxa, int idxo){
	if(idxo == 6){
		for(int i=0;i<6;i++)
			cout <<lotto[i]<<" ";
		cout <<endl;
		return;
	}

	for(int i=idxa;i<k;i++){
		lotto[idxo] = arr[i];
		recur(i+1, idxo+1);
	}
}

int main(void)
{
	while(1){
		cin>>k;
		if(k==0)
			break;
		for(int i=0;i<k;i++)
			cin>> arr[i];
		recur(0, 0);
		cout <<endl;
	}
 return 0;
}
