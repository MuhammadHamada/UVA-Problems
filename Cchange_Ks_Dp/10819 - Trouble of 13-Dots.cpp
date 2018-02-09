#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<string>
#include<set>
#include<cstring>
#include<fstream>
using namespace std;
typedef long long ll;
int dp[110][10201];
pair<int, int> arr[110];
int m, n;
int solve(int i, int c)
{
	if (c > m+200)return -1e9;
	if (i == n)
	{
		if (m + 200 * (c > 2000) >= c)
			return 0;
		else
			return -1e9;
	}
	if (dp[i][c] != -1)return dp[i][c];
	return dp[i][c] = max(solve(i + 1, c + arr[i].first) + arr[i].second, solve(i + 1, c));
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (cin>>m)
	{
		cin >> n;
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &arr[i].first, &arr[i].second);
		printf("%d\n", solve(0, 0));
	}
	return 0;
}