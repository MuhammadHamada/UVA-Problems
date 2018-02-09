#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
string ans;
vector<string>vec;
bool vis[26];
bool vis1[26];
bool vis2[26];
vector<int> adj[26];
void dfs(int u)
{
	if (vis1[u])return;
	vis1[u] = true;
	for (int i = 0; i < adj[u].size(); i++)
	{
		dfs(adj[u][i]);
		if (!vis2[adj[u][i]])
		{
			ans += 'A' + adj[u][i];
			vis2[adj[u][i]] = 1;
		}
	}
}
int main() {
	//freopen("output.txt", "w", stdout);
	string s, s1, s2;
	while (cin >> s)
	{
		while (s != "#")
		{
			vec.push_back(s);
			cin >> s;
			for (int j = 0; j < s.size(); j++)
			{
				vis[s[j] - 'A'] = true;
			}
		}
		for (int i = 1; i < vec.size(); i++)
		{
			s1 = vec[i - 1], s2 = vec[i];
			int mn = min((int)s1.size(), (int)s2.size());
			for (int j = 0; j < mn; j++)
			{
				if (s1[j] != s2[j])
				{
					adj[s1[j] - 'A'].push_back(s2[j] - 'A');
					break;
				}
			}
		}
		for (int i = 0; i < 26; i++)
		{
			if (!vis1[i] && vis[i])
			{
				dfs(i);
				if (!vis2[i])
				{
					ans += 'A' + i;
					vis2[i] = 1;
				}
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
		vec.clear();
		memset(vis, 0, sizeof vis);
		memset(vis1, 0, sizeof vis1);
		memset(vis2, 0, sizeof vis2);
		ans = s = s1 = s2 = "";
		for (int i = 0; i < 26; i++)adj[i].clear();
	}
	return 0;
}
