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
int t, n, mat[10][1010], dp[10][1010];
int solve(int x, int y)
{
	if (y == n && x == 0)return 0;
	if (x < 0 || x > 9 || y == n)return oo;
	if (dp[x][y] != -1)return dp[x][y];
	return dp[x][y] = min(min(solve(x - 1, y + 1) + 20 - mat[x][y]
		, solve(x + 1, y + 1) + 60 - mat[x][y])
		, solve(x, y + 1) + 30 - mat[x][y]);
}
int main()
{
	
	cin >> t;
	while (t--)
	{
		cin >> n;
		n = n / 100;
		for (int i = 9; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> mat[i][j];
				dp[i][j] = -1;
			}
		}
		cout << solve(0, 0) << endl << endl;
	}
	return 0;
}