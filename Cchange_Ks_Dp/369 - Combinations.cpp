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
ll n, r;
ll dp[110][110];
ll solve(int x,int r)
{
	if (r == 0 && x == 0)return 1;
	if ((r > 0 && x == 0) || x < 0 || r < 0)return 0;
	if (dp[x][r] != -1)return dp[x][r];
	return dp[x][r] = solve(x - 1, r - 1) + solve(x - 1, r);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dp, -1, sizeof dp);
	while (true)
	{
		cin >> n >> r;
		if (n == 0 && r == 0)break;
		ll ans = solve(n, r);
		cout << n << " things taken " << r << " at a time is " << ans << " exactly." << endl;
	}
	return 0;
}