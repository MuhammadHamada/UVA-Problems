#include <iostream>
#include <vector>
#include <set>
using namespace std;

int uniqueId;
int id[100100];
int parent[100100];
int siz[100100];
int sum[100100];

int getsetId(int u)
{
	return (u == parent[u] ? u : parent[u] = getsetId(parent[u]));
}
bool isSameSet(int u, int v) {
	return getsetId(u) == getsetId(v);
}

void Unionset(int u, int v) {
	if (isSameSet(u, v))
		return;
	int s1 = getsetId(u), s2 = getsetId(v);
	siz[s1] += siz[s2];
	sum[s1] += sum[s2];
	parent[s2] = s1;
}

void remove(int u) {
	int sid = getsetId(id[u]);
	siz[sid]--;
	sum[sid] -= u;
	id[u] = ++uniqueId;
	parent[id[u]] = id[u];
	sum[id[u]] = u;
	siz[id[u]] = 1;
}
int main()
{
	//ofstream cout("out.txt");
	int n, m, q, u, v;
	while (cin >> n >> m) {
		uniqueId = n;
		for (int i = 1; i <= n; i++)
		{
			id[i] = i;
			parent[i] = i;
			siz[i] = 1;
			sum[i] = i;
		}
		while (m--) {
			cin >> q;
			if (q <= 2) {
				cin >> u >> v;
				if (q == 2) {
					if (isSameSet(id[u], id[v]))continue;
					remove(u);
				}
				Unionset(id[u], id[v]);
			}
			else {
				cin >> u;
				cout << siz[getsetId(id[u])] << " " << sum[getsetId(id[u])] << endl;
			}
		}
	}
	return 0;
}
