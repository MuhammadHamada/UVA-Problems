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
int d, n;
int arr[25];
int dp[25][10000];
int solve(int idx, int rem) {
	if (rem < 0)return 100000;
	if (idx == n) {
		return rem;
	}
	int &ret = dp[idx][rem];
	if (ret != -1)return ret;
	ret = 0;
	return ret += min(solve(idx + 1, rem), solve(idx + 1, rem - arr[idx]));
}
void printAns(int idx,int rem) {

	if (solve(idx + 1, rem) > solve(idx + 1, rem - arr[idx])) {
		cout << arr[idx] << " ";
		if (idx + 1 < n)
			printAns(idx + 1, rem - arr[idx]);
	}
	else {
		if (idx + 1 < n)
		printAns(idx + 1, rem);
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (cin >> d >> n) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		memset(dp, -1, sizeof dp);
		int x = solve(0, d);
		printAns(0, d);
		cout << "sum:" << d - x << endl;
	}
	return 0;
}