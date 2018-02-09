#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<cmath>
#include <iomanip>
typedef long long ll;
using namespace std;
int siz[200100];
map<pair<double, double>, pair<double, double>>parent;
vector<pair<double,pair<pair<double,double>,pair<double,double>>>>dis;
vector<pair<double, double>>vec;
pair<double,double> getsetId(pair<double,double> u)
{
	return u == parent[u] ? u : parent[u] = getsetId(parent[u]);
}
bool isSameSet(pair<double, double> u, pair<double, double> v)
{
	return getsetId(u) == getsetId(v);
}
void Unionset(pair<double, double> u, pair<double, double> v)
{
	if (isSameSet(u, v))return;
	pair<double, double> s1 = getsetId(u), s2 = getsetId(v);
	parent[s2] = s1;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		double x, y;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			vec.push_back({ x,y });
			parent[{x, y}] = { x,y };
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				double x1, x2, y1, y2;
				x1 = vec[i].first;
				x2 = vec[j].first;
				y1 = vec[i].second;
				y2 = vec[j].second;
				double d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
				dis.push_back({ d,{{x1,y1},{x2,y2}} });
			}
		}
		sort(dis.begin(), dis.end());
		double ans = 0;
		for (int i = 0; i < dis.size(); i++)
		{
			if (isSameSet(dis[i].second.first, dis[i].second.second))continue;
			Unionset(dis[i].second.first, dis[i].second.second);
			ans += dis[i].first;
		}
		cout << fixed << setprecision(2) << ans << endl;
		if (i + 1 == t)break;
		cout << endl;
		parent.clear();
		dis.clear();
		vec.clear();
	}
	return 0;
}