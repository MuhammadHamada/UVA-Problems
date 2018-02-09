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
vector<int> adj[26];
bool awake[26];
int dirc[26];
int year[26];
int main()
{
	//ofstream cout("out.txt");
	int n, m;
	char c1, c2, c3, c4, c5;
	while (cin >> n >> m)
	{
		int ans = 0;
		cin >> c1 >> c2 >> c3;
		awake[c1 - 'A'] = 1;
		awake[c2 - 'A'] = 1;
		awake[c3 - 'A'] = 1;
		while(m--)
		{
			cin >> c4 >> c5;
			adj[c4 - 'A'].push_back(c5 - 'A');
			adj[c5 - 'A'].push_back(c4 - 'A');
			for (int i = 0; i < 26; i++)
			{
				int c = 0;
				if (!awake[i])
				{
					for (int j = 0; j < adj[i].size(); j++)
					{
						if (awake[adj[i][j]])c++;
					}
					if (c == 3)
					{
						int mx = -1;
						for (int j = 0; j < adj[i].size(); j++)
						{
							if (awake[adj[i][j]])
								mx = max(mx, year[adj[i][j]]);
						}
						year[i] = mx+1, awake[i] = 1, i = 0, year[i] = 0;
					}
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++)
		{
			if (awake[i])cnt++;
		}
		if (cnt == n)
		{
			for (int i = 0; i < 26; i++)
			{
				ans = max(ans, year[i]);
			}
			cout << "WAKE UP IN, " << ans << ", YEARS" << endl;
		}
		else
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
		memset(awake, 0, sizeof awake);
		memset(dirc, 0, sizeof dirc);
		memset(year, 0, sizeof year);
		for (int i = 0; i < 26; i++)
			adj[i].clear();
	}
	return 0;
}