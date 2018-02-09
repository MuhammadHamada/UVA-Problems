#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<set>
#include<iomanip>
#include<cstring>
#include <sstream>
#include <iterator>
#define oo 1e17
typedef long long ll;
using namespace std;
int t, n, m, x;
ll mat[110][110];
ll dp[110][110];
ll solve(int i, int j)
{
	if (i < 1)i = n;
	else if (i>n)i = 1;
	if (j == m)return mat[i][j];
	if (dp[i][j] != -1)return dp[i][j];
	return dp[i][j] = min(min(solve(i - 1, j + 1), solve(i + 1, j + 1)), solve(i, j + 1)) + mat[i][j];
}
void getPath(int i, int j)
{
	if (i < 1)i = n;
	else if (i>n)i = 1;
	if(j != m)
	cout << i << " ";
	if (j == m)
	{
		cout << i << endl;
		return;
	}
	int ans1 = solve(i - 1, j + 1);
	int ans2 = solve(i, j + 1);
	int ans3 = solve(i + 1, j + 1);
	if (i - 1 < 1)
	{
		if (i + 1 <= n)
		{
			if (ans2 <= ans1 && ans2 <= ans3)getPath(i, j + 1);
			else if (ans3 <= ans1 && ans3 <= ans2)getPath(i + 1, j + 1);
			else getPath(i - 1, j + 1);
		}
		else
		{
			if (ans3 <= ans1 && ans3 <= ans2)getPath(i + 1, j + 1);
			else if (ans2 <= ans1 && ans2 <= ans3)getPath(i, j + 1);
			else getPath(i - 1, j + 1);
		}
	}
	else if (i + 1 > n)
	{
		if (ans3 <= ans1 && ans3 <= ans2)getPath(i + 1, j + 1);
		else
		{
			if (i - 1 < 1)
			{
				if (ans2 <= ans1 && ans2 <= ans3)getPath(i, j + 1);
				else getPath(i - 1, j + 1);
			}
			else
			{
				if (ans1 <= ans2 && ans1 <= ans3)getPath(i - 1, j + 1);
				else getPath(i, j + 1);
			}
		}
	}
	else if (ans1 <= ans2 && ans1 <= ans3)getPath(i - 1, j + 1);
	else if (ans2 <= ans1 && ans2 <= ans3)getPath(i, j + 1);
	else getPath(i + 1, j + 1);
}
int main()
{
	//freopen("output.txt", "w", stdout);
	while (cin >> n >> m)
	{
		memset(dp, -1, sizeof dp);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> mat[i][j];
			}
		}
		ll ans = oo;
		int r = 1;
		for (int i = 1; i <= n; i++)
		{
			ll tmp = ans;
			ans = min(ans, solve(i, 1));
			if (tmp != ans)r = i;
		}
		getPath(r, 1);
		cout << ans << endl;
	}
	return 0;
}