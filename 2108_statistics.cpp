#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
int arr[500001];
int cnt[8002];
int MAX = -4000;
int MIN = 4000;

int main(void)
{
	double nsum = 0;
	scanf("%d", &n);

	for ( int i = 0; i < n; i++ )
	{
		scanf("%d", &arr[i]);
		nsum += arr[i];
		cnt[arr[i]+4000]++;
		MAX = max(arr[i], MAX);
		MIN = min(arr[i], MIN);
	}

	printf("%.0f\n", nsum / n);

	sort(arr, arr + n);
	printf("%d\n", arr[int(n / 2)]);

	int ncnt = 0;
	for ( int i = 0; i <= MAX+4000; i++ )
		ncnt = max(ncnt, cnt[i]);

	vector<int>vec;
	for ( int i = 0; i <= MAX + 4000; i++ )
	{
		if ( cnt[i] == ncnt )
			vec.push_back(i - 4000);
	}
	sort(vec.begin(), vec.end());
	if ( vec.size() == 1 )
		printf("%d\n", vec[0]);
	else
		printf("%d\n", vec[1]);
	printf("%d\n", MAX-MIN);

	return 0;
}
