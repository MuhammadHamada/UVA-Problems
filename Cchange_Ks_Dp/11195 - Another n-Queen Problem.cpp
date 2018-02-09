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
int n;
char mat[20][20];
bool cl[20], d1[20], d2[50];
int solve(int i, int j, int k) {
	if (k == 0)return 1;
	int ans = 0;
	if (!cl[j] && !d1[i + j] && !d2[i - j + n + 1] && mat[i][j] != '*') {
		cl[j] = true; d1[i + j] = true; d2[i - j + (n + 1)] = true;
		if (i + 1 <= n) {
			ans += solve(i + 1, 0, k - 1);
		}
		cl[j] = false; d1[i + j] = false; d2[i - j + (n + 1)] = false;
	}
	if (j + 1 < n)
		ans += solve(i, j + 1, k);
	return ans;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t = 1;
	while (cin >> n) {
		if (n == 0)break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}
		cout << "Case " << t++ << ": " << solve(0, 0, n) << endl;
	}
	return 0;
}