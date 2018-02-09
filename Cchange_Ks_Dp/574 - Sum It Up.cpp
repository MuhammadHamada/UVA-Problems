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
int t, n;
vector<string>vec;
map<string, bool>mp;
bool cmp(string a, string b) {
	for (int i = 0,j=0; i < a.size() && j < b.size(); i++,j++) {
		int x, y;
		string tmp = "";
		while (a[i] != '+'&&i < a.size()) {
			tmp += a[i];
			i++;
		}
		x = stoi(tmp);
		tmp = "";
		while (b[j] != '+' && j < b.size()) {
			tmp += b[j];
			j++;
		}
		y = stoi(tmp);
		if (x == y)continue;
		return x > y;
	}
	return a.size() > b.size();
}
int dp[15][1010][4096];
int arr[15];
bool solve(int idx,int rem,int msk) {
	if (idx > n || rem < 0)return false;
	if (rem == 0) {
		string s = "";
		for (int i = 0; i < idx; i++) {
			if (msk&(1 << i)) {
				s += to_string(arr[i]);
				if (i != idx - 1)
					s += '+';
				else {
					if (mp.count(s) == 0) {
						mp[s] = true;
					}
				}
			}
		}
		return true;
	}
	if (dp[idx][rem][msk] != -1)return true;
	dp[idx][rem][msk] = solve(idx + 1, rem - arr[idx], msk | (1 << idx));
	dp[idx][rem][msk] = solve(idx + 1, rem, msk);
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (cin >> t >> n) {
		if (t == 0 && n == 0)break;
		memset(dp, -1, sizeof dp);
		memset(arr, 0, sizeof arr);
		mp.clear();
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << "Sums of " << t << ":" << endl;
		solve(0, t, 0);
		if (mp.size() == 0) {
			cout << "NONE" << endl;
		}
		else {
			for (auto it : mp) {
				vec.push_back(it.first);
			}
			sort(vec.begin(), vec.end(),cmp);
			for (int i = 0; i < vec.size(); i++) {
				cout << vec[i] << endl;
			}
			vec.clear();
		}
	}
	return 0;
}