#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<set>
#include<iomanip>
#include<cstring>
#define oo 1000000000
typedef long long ll;
using namespace std;
int t, n, m, mat[11][110], dp[11][110][110];
vector<vector<pair<int, int>>>vec;
int solve(int x, int y,int rem)
{
	if (rem < 0 || y > m)return -oo;
	if (x == n)return 0;
	if (dp[x][y][rem] != -1)return dp[x][y][rem];
	int ans1 = 0;
	if (mat[x][y] >= 5 && rem - y >= 0)ans1 = solve(x + 1, 1, rem - y) + mat[x][y];
	int ans2 = solve(x, y + 1, rem);
	return dp[x][y][rem] = max(ans1, ans2);
}
int main()
{
	//freopen("output.txt", "w", stdout);
	cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof dp);
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			vector<pair<int, int>>tmp;
			for (int j = 1; j <= m ; j++)
			{
				cin >> mat[i][j];
				tmp.push_back({ mat[i][j],j });
			}
			vec.push_back(tmp);
			tmp.clear();
		}
		double ans = solve(0, 1, m) / (n*1.0) + 0.000000001;
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			sort(vec[i].begin(), vec[i].end());
			for (int j = 0; j < vec[i].size(); j++)
			{
				if (vec[i][j].first >= 5)
				{
					c += vec[i][j].second;
					break;
				}
			}
		}
		vec.clear();
		if (ans >= 5 && c <= m)cout << "Maximal possible average mark - " << fixed << setprecision(2) << ans <<"."<< endl;
		else cout << "Peter, you shouldn't have played billiard that much." << endl;
	}
	return 0;
}