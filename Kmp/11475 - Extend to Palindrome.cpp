#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;
void kmp(vector<int> &v,string &s)
{
	v.resize(s.size());
	for (int i = 1, j = 0; i < s.size(); i++)
	{
		while (j > 0 && s[i] != s[j])
			j = v[j - 1];
		j += (s[i] == s[j]);
		v[i] = j;
	}
}
int main()
{
	//fstream cout("output.txt");
	int n;
	string k, s, tmp;
	while (cin >> s)
	{
		int len = s.size();
		tmp = s;
		k = s;
		reverse(k.begin(), k.end());
		k += '#' + s;
		vector<int>pi;
		kmp(pi, k);
		int mx = 0;
		tmp += k.substr(pi[k.size() - 1], len - pi[k.size() - 1]);
		cout << tmp << endl;
	}
	return 0;
}