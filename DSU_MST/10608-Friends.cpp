//https://ideone.com/xICP5e
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int parent[100100];
int ans[100100];
int getsetId(int u)
{
	return (u == parent[u] ? u : parent[u]=getsetId(parent[u]));
}
bool isSameSet(int u, int v) {
	return getsetId(u) == getsetId(v);
}
 
void Unionset(int u, int v) {
	if (isSameSet(u, v))
		return;
	int s1 = getsetId(u), s2 = getsetId(v);
	ans[s1] += ans[s2];
	parent[s2] = s1;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
 
		int n, m, x, y;
		cin >> n >> m;
		for (int i = 1; i <= n ; i++)
		{
			parent[i] = i, ans[i] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			Unionset(x, y);
		}
		int mx = -1;
		for (int i = 1; i <= n; i++)
		{
			mx = max(mx, ans[i]);
		}
		cout << mx << endl;
		memset(ans, 0, sizeof ans);
	}
	return 0;
}