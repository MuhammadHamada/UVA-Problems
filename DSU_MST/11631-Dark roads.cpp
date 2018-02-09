#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<fstream>
typedef long long ll;
using namespace std;
int siz[200100];
int parent[200100];
pair<int,pair<int,int>> arr[200100];
int getsetId(int u)
{
	return u == parent[u] ? u : parent[u] = getsetId(parent[u]);
}
bool isSameSet(int u, int v)
{
	return getsetId(u) == getsetId(v);
}
void Unionset(int u, int v)
{
	if (isSameSet(u, v))return;
	int s1 = getsetId(u), s2 = getsetId(v);
	siz[s1] += siz[s2];
	parent[s2] = s1;
}
int main()
{
	int n, m, u, v, w;
	cin >> m >> n;
	while (!(n == 0 && m == 0))
	{
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			parent[i] = i, siz[i] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> u >> v >> w;
			arr[i].first = w;
			arr[i].second.first = u;
			arr[i].second.second = v;

		}
		sort(arr, arr + n);
		for (int i = 0; i < n; i++)
		{
			if (isSameSet(arr[i].second.first, arr[i].second.second))
			{
				ans += arr[i].first;
				continue;
			}
			Unionset(arr[i].second.first, arr[i].second.second);
		}
		cout << ans << endl;
		cin >> m >> n;
	}
	return 0;
}