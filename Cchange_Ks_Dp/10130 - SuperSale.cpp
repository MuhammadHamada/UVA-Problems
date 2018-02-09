#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<set>
#include<cstring>
#define oo 1000000000
typedef long long ll;
using namespace std;
int t, n, p, w, g;
int dp[1010][110];
vector<pair<int, int>>vec;
int solve(int ind,int rem)
{
	if (rem < 0)return -oo;
	if (ind == n)return 0;
	if (dp[ind][rem] != -1)return dp[ind][rem];
	return dp[ind][rem] = max(solve(ind + 1, rem), solve(ind + 1, rem - vec[ind].second)+vec[ind].first);
}
int main()
{
	
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> p >> w;
			vec.push_back({ p,w });
		}
		cin >> g;
		int ans = 0;
		for (int i = 0; i < g; i++)
		{
			memset(dp, -1, sizeof dp);
			cin >> w;
			ans += solve(0, w);
		}
		cout << ans << endl;
		vec.clear();
	}
	return 0;
}