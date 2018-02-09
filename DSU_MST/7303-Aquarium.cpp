#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<cmath>
#include <iomanip>
const int DR = 1;
const int UL = 2;
const int UR = 3;
const int DL = 4;
typedef long long ll;
using namespace std;
int n, m;
char mat[110][110];
vector < pair<ll, pair<int, int>>>vec;
pair<pair<int, int>, int> parent[110][110][10];
pair<pair<int, int>, int> getsetId(pair<pair<int, int>, int> x)
{
	return x == parent[x.first.first][x.first.second][x.second] ? x : parent[x.first.first][x.first.second][x.second] = getsetId(parent[x.first.first][x.first.second][x.second]);
}
bool isSameSet(pair<pair<int, int>, int> u, pair<pair<int, int>, int> v)
{
	pair<pair<int, int>, int> s1 = getsetId(u);
	pair<pair<int, int>, int> s2 = getsetId(v);
	return (s1 == s2);
}
void Unionset(pair<pair<int, int>, int> u, pair<pair<int, int>, int> v)
{
	if (isSameSet(u, v))return;
	pair<pair<int, int>, int> s1 = getsetId(u), s2 = getsetId(v);
	parent[s2.first.first][s2.first.second][s2.second] = s1;
}
void ReadInput()
{
	ll x;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			vec.push_back({ x,{ i,j } });
		}
}
void Initial_Id()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == '/')
			{
				parent[i][j][DR] = { { i,j },DR }, parent[i][j][UL] = { { i,j },UL };
			}
			else
			{
				parent[i][j][DL] = { { i,j },DL }, parent[i][j][UR] = { { i,j },UR };
			}
		}
	}
}
void Initial_Union()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == '/')
			{
				if (j + 1 < m) //Connect with Right
				{
					Unionset({ { i,j },DR }, { { i ,j + 1 },(mat[i][j + 1] == '/' ? UL : DL) });
				}
				if (i + 1 < n) //Connect with Down
				{
					Unionset({ { i,j },DR }, { { i + 1,j },(mat[i + 1][j] != '/' ? UR : UL) });
				}
				if (j - 1 >= 0) //Connect with Left
				{
					Unionset({ { i,j },UL }, { { i ,j - 1 },(mat[i][j - 1] == '/' ? DR : UR) });
				}
				if (i - 1 >= 0) //Connect with Up
				{
					Unionset({ { i,j },UL }, { { i - 1,j },(mat[i - 1][j] != '/' ? DL : DR) });
				}
			}
			else
			{
				if (j + 1 < m) //Connect with Right
				{
					Unionset({ { i,j },UR }, { { i ,j + 1 },(mat[i][j + 1] == '/' ? UL : DL) });
				}
				if (i + 1 < n) //Connect with Down
				{
					Unionset({ { i,j },DL }, { { i + 1,j },(mat[i + 1][j] != '/' ? UR : UL) });
				}
				if (j - 1 >= 0) //Connect with Left
				{
					Unionset({ { i,j },DL }, { { i ,j - 1 },(mat[i][j - 1] == '/' ? DR : UR) });
				}
				if (i - 1 >= 0) //Connect with Up
				{
					Unionset({ { i,j },UR }, { { i - 1,j },(mat[i - 1][j] != '/' ? DL : DR) });
				}
			}
		}
	}
}
ll MST()
{
	sort(vec.begin(), vec.end());
	ll ans = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (mat[vec[i].second.first][vec[i].second.second] == '/')
		{
			if (isSameSet({ { vec[i].second.first,vec[i].second.second },DR }, { { vec[i].second.first,vec[i].second.second },UL }))
				continue;
			ans += vec[i].first;
			Unionset({ { vec[i].second.first,vec[i].second.second },DR }, { { vec[i].second.first,vec[i].second.second },UL });
		}
		else
		{
			if (isSameSet({ { vec[i].second.first,vec[i].second.second },UR }, { { vec[i].second.first,vec[i].second.second },DL }))
				continue;
			ans += vec[i].first;
			Unionset({ { vec[i].second.first,vec[i].second.second },UR }, { { vec[i].second.first,vec[i].second.second },DL });
		}
	}
	return ans;
}
void clear()
{
	vec.clear();
	for (int i = 0; i < 110; i++)
	{
		for (int j = 0; j < 110; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				parent[i][j][k].first.first = 0, parent[i][j][k].first.second = 0, parent[i][j][k].second = 0;
			}
		}
	}
}
int main()
{
	int t,c=1;
	cin >> t;
	while (t--)
	{
		//ofstream cout("out.txt");
		ReadInput(); //This function reads inputs from the user

		Initial_Id(); //This function sets IDs for both parts of each cell by cell's coordinates and a value (UL or
		              //UR or DR or DL) w.r.t what the cell contains ('\' or '/')

		Initial_Union(); //To Union any two parts of two cells which are neighbours

		cout << "Case " << c << ": " << MST() << endl; //To Union n*m*2 sets by minimum cost 

		clear(); 

		c++;
	}
	return 0;
}