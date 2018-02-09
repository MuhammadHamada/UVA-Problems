//https://ideone.com/XMHZ43
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<fstream>
using namespace std;
map<string, string>parent;
map<string, int>siz;
vector<pair<string, string>>vec;
string getsetId(string u)
{
	string &s = parent[u];
	return u == s ? u : s = getsetId(s);
}
bool isSameSet(string u, string v)
{
	return getsetId(u) == getsetId(v);
}
void UonionSet(string u, string v)
{
	if (isSameSet(u, v))return;
	string s1 = getsetId(u), s2 = getsetId(v);
	siz[s1] += siz[s2];
	parent[s2] = s1;
}
int main()
{
	//ofstream cout("out.txt");
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s1, s2;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> s1 >> s2;
			parent[s1] = s1;
			parent[s2] = s2;
			siz[s1] = 1;
			siz[s2] = 1;
			vec.push_back({ s1,s2 });
		}
		for (int i = 0; i < n; i++)
		{
			UonionSet(vec[i].first, vec[i].second);
			cout << siz[getsetId(vec[i].first)] << endl;
		}
		parent.clear();
		siz.clear();
		vec.clear();
	}
	return 0;
}
