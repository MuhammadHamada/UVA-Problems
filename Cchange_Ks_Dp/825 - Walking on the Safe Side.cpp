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
#define oo 1000000000
typedef long long ll;
using namespace std;
int t, n, m, y;
bool mat[110][110];
int dp[110][110];
bool isvalid(int i,int j)
{
	return (i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1 && !mat[i][j]);
}
int solve(int i, int j)
{
	if (!isvalid(i, j))return 0;
	if (i == n - 1 && j == m - 1)return 1;
	if (dp[i][j] != -1)return dp[i][j];
	return dp[i][j] = solve(i + 1, j) + solve(i, j + 1);
}
int main()
{
	//freopen("output.txt", "w", stdout);
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		memset(mat, 0, sizeof mat);
		memset(dp, -1, sizeof dp);
		cin >> n >> m;
		string s;
		getline(std::cin, s);
		for (int i = 0; i < n; i++)
		{
			getline(std::cin, s);

			istringstream is(s);

			vector<int> v((std::istream_iterator<int>(is)), std::istream_iterator<int>());
			int j = 0;
			for (int x : v) {
				if (j != 0) {
					if(!((y==1 && x==1)||(y == n && x == m)))
					mat[y - 1][x - 1] = true;
				}
				else {
					y = x;
				}
				j++;
			}
		}
		cout << solve(0, 0) << endl;
		if (k != t - 1)cout << endl;
	}
	return 0;
}