#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> vec;
int dp[100001];

int dfs(int cur)
{
	if ( dp[cur] )
		return dp[cur];
	dp[cur]=1;
	for ( int i = 0; i < vec[cur].size(); i++ )
	{
		int next = vec[cur][i];
		if ( vec[cur].size() < vec[next].size() )
			dp[cur] = max(dfs(next) + 1, dp[cur]);
	}
		
	return dp[cur];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, MAX=0;
	cin >> n >> m;
	vec.resize(n + 1);
	while(m-- )
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for(int i=0;i<n;i++ )
		MAX = max(MAX, dfs(i));

	cout << MAX << "\n";
	return 0;
}
