#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;
typedef long long ll;
int n, m;
int ans[1000][20000];
int slv[1000][20000];
map<string, int>mp;
map<pair<int, int>, string>eq;
bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i])continue;
			return a[i] < b[i];
		}
	}
	return a.size() < b.size();
}
void init() {
	string s = "";
	vector<string>vec;
	for (int i = 0; i < 26; i++)
	{
		s = "";
		s += ('A' + i);
		vec.push_back(s);
		for (int j = 0; j < 26; j++)
		{
			if (s.size() < 2)
			s += ('A' + j);
			else {
				s[1] = ('A' + j);
			}
			vec.push_back(s);
			for (int k = 0; k < 26; k++)
			{
				if(s.size() < 3)
				s += ('A' + k);
				else {
					s[2] = ('A' + k);
				}
				vec.push_back(s);
			}
			s = s.substr(0, 2);
		}
	}
	sort(vec.begin(), vec.end(),cmp);
	for (int j = 0; j < vec.size(); j++)
	{
		string tmp = vec[j];
		mp[tmp] = j;
	}
}
int solve(int i,int j) {
	if (slv[i][j])return ans[i][j];
	else {
		string s = eq[{i, j}];
		string tmp = "", r = "";
		int sum = 0;
		for (int k = 0; k < s.size(); k++)
		{
			if (s[k] != '+' && s[k] != '=') {
				if (s[k] >= '0'&&s[k] <= '9') {
					r += s[k];
					continue;
				}
				tmp += s[k];
				continue;
			}
			if (r == "" || tmp == "")continue;
			ans[stoi(r) - 1][mp[tmp]] = solve(stoi(r) - 1, mp[tmp]);
			slv[stoi(r) - 1][mp[tmp]] = true;
			sum += ans[stoi(r) - 1][mp[tmp]];
			tmp = "", r = "";
		}
		if (mp.count(tmp) != 0) {
			ans[stoi(r) - 1][mp[tmp]] = solve(stoi(r) - 1, mp[tmp]);
			slv[stoi(r) - 1][mp[tmp]] = true;
			sum += ans[stoi(r) - 1][mp[tmp]];
		}
		slv[i][j] = true;
		return ans[i][j] = sum;
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int t;
	string s;
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> s;
				if (s[0] != '=') {
					ans[i][j] = stoi(s);
					slv[i][j] = true;
				}
				else {
					eq[{i, j}] = s;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!slv[i][j]) {
					ans[i][j] = solve(i, j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d", ans[i][j]);
				if (j < m - 1)
					printf(" ");
			}
			printf("\n");
		}
		memset(slv, 0, sizeof slv);
		eq.clear();

	}
	return 0;
}