//https://ideone.com/d36fIt
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<fstream>
typedef long long ll;
using namespace std;
int siz[1010];
int parent[1010];
pair<int,pair<int,int>> arr[30000];
vector<int>vec;
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
//	ofstream cout("out.txt");
	int n, m, u, v, w;
	cin >> n >> m;
	while (!(n == 0 && m == 0))
	{
		for (int i = 0; i < n; i++)
		{
			parent[i] = i, siz[i] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			arr[i].first = w;
			arr[i].second.first = u;
			arr[i].second.second = v;
		}
		sort(arr, arr + m);
		for (int i = 0; i < m; i++)
		{
			if (isSameSet(arr[i].second.first, arr[i].second.second))
			{
				vec.push_back(arr[i].first);
				continue;
			}
			Unionset(arr[i].second.first, arr[i].second.second);
		}
		if (m <= n - 1 && vec.size()==0)cout << "forest\n";
		else
		{
			for (int i = 0; i < vec.size(); i++)
			{
				if (i != 0)cout << " ";
				cout << vec[i];
			}
			cout << endl;
		}
		vec.clear();
		cin >> n >> m;
	}
	return 0;
}