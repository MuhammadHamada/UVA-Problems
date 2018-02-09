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
int n,z;
bool flag;
pair<int,int> idx[10][10];
vector<vector<int>> mat;
void init() {
	if (n == 1)return;
	if (n == 2) {
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i < 2 && j < 2)idx[i][j] = { 0,0 };
				if (i >= 2 && j < 2)idx[i][j] = { 2,0 };
				if (i < 2 && j >= 2)idx[i][j] = { 0,2 };
				if (i >= 2 && j >= 2)idx[i][j] = { 2,2 };
			}
		}
		return;
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			idx[i][j] = { 0,0 };
	for (int i = 0; i < 3; i++)
		for (int j = 3; j < 6; j++)
			idx[i][j] = { 0,3 };
	for (int i = 0; i < 3; i++)
		for (int j = 6; j < 9; j++)
			idx[i][j] = { 0,6 };
	//--------------------------------
	for (int i = 3; i < 6; i++)
		for (int j = 0; j < 3; j++)
			idx[i][j] = { 3,0 };
	for (int i = 3; i < 6; i++)
		for (int j = 3; j < 6; j++)
			idx[i][j] = { 3,3 };
	for (int i = 3; i < 6; i++)
		for (int j = 6; j < 9; j++)
			idx[i][j] = { 3,6 };
	//--------------------------------
	for (int i = 6; i < 9; i++)
		for (int j = 0; j < 3; j++)
			idx[i][j] = { 6,0 };
	for (int i = 6; i < 9; i++)
		for (int j = 3; j < 6; j++)
			idx[i][j] = { 6,3 };
	for (int i = 6; i < 9; i++)
		for (int j = 6; j < 9; j++)
			idx[i][j] = { 6,6 };

}
bool check(int x,int y,int k) {
	for (int i = 0; i < n*n; i++){
		if (mat[i][y] == k)return false;
	}
	for (int i = 0; i < n*n; i++) {
		if (mat[x][i] == k)return false;
	}
	for (int i = idx[x][y].first; i < idx[x][y].first+n; i++)
	{
		for (int j = idx[x][y].second; j < idx[x][y].second+n; j++)
		{
			if (mat[i][j] == k)return false;
		}
	}
	return true;
}
void printAns() {
	for (int i = 0; i < n*n; i++)
	{
		for (int j = 0; j < n*n; j++)
		{
			printf("%d", mat[i][j]);
			if (j != (n*n - 1))printf(" ");
		}
		printf("\n");
	}
	flag = true;
}
bool solve(int i,int j) {
	if (i == n*n || j == n*n || flag)return true;
	if (i == (n*n - 1) && j == (n*n - 1)) {
		if (mat[i][j] == 0) {
			for (int k = 1; k <= n*n; k++)
			{
				if (check(i, j, k)) {
					mat[i][j] = k;
					break;
				}
			}
			if (mat[i][j] == 0)return false;
		}
		printAns();
		return true;
	}
	 if (mat[i][j] == 0) {
		 for (int k = 1; k <= n*n; k++) {
			 if (check(i, j, k)) {
				 mat[i][j] = k;
				 if (j + 1 == n*n) {
					 if (solve(i + 1, 0))
						 mat[i][j] = 0;
					 else break;
				 }
				 else {
					 if (solve(i, j + 1))
						 mat[i][j] = 0;
					 else break;
				 }
			 }
		 }
	 }
	 else {
		 if (j + 1 == n*n)return solve(i + 1, 0);
		 else return solve(i, j + 1);
	 }
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	while (true) {
		init();
		for (int i = 0; i < n*n; i++)
		{
			vector<int>tmp;
			for (int j = 0; j < n*n; j++)
			{
				scanf("%d", &z);
				tmp.push_back(z);
			}
			mat.push_back(tmp);
		}
		solve(0, 0);
		for (int i = 0; i < n*n; i++)
		{
			for (int j = 0; j < n*n; j++)
			{
				if (mat[i][j] == 0 && !flag) {
					printf("NO SOLUTION\n");
					flag = true;
					break;
				}
			}
		}
		if (cin >> n)
			printf("\n");
		else
			break;
		for (int i = 0; i < mat.size(); i++)
		{
			mat[i].clear();
		}
		mat.clear();
		flag = false;
	}
	return 0;
}