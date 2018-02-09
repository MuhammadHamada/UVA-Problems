#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <stack>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
vector<string>output(1);
bool vis[26];
int mp[26];
int mp2[26];
bool cmp(string a, string b)
{
	return a[0] < b[0];
}
class Graph
{
	int V;    // No. of vertices
	list<int> *adj;    // An array of adjacency lists

					   // Fills Stack with vertices (in increasing order of finishing
					   // times). The top element of stack has the maximum finishing 
					   // time
	void fillOrder(int v, bool visited[], stack<int> &Stack);

	// A recursive function to print DFS starting from v
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V);
	void addEdge(int v, int w);

	// The main function that finds and prints strongly connected
	// components
	void printSCCs();

	// Function that returns reverse (or transpose) of this graph
	Graph getTranspose();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;
	string s;
	s += (char)('A' + mp2[v]);
	output[output.size() - 1] += s;
//	cout << (char)('A' + v) << " ";

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
	// Mark the current node as visited and print it
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			fillOrder(*i, visited, Stack);

	// All vertices reachable from v are processed by now, push v 
	Stack.push(v);
}

// The main function that finds and prints all strongly connected 
// components
void Graph::printSCCs()
{
	stack<int> Stack;

	// Mark all the vertices as not visited (For first DFS)
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Fill vertices in stack according to their finishing times
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			fillOrder(i, visited, Stack);

	// Create a reversed graph
	Graph gr = getTranspose();

	// Mark all the vertices as not visited (For second DFS)
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Now process all vertices in order defined by Stack
	while (Stack.empty() == false)
	{
		// Pop a vertex from stack
		int v = Stack.top();
		Stack.pop();

		// Print Strongly connected component of the popped vertex
		if (visited[v] == false)
		{
			gr.DFSUtil(v, visited);
			output.push_back("");
			//cout << endl;
		}
	}
}

// Driver program to test above functions
vector<vector<char>>vec;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	while (n != 0)
	{
		vec.resize(n);
		set<char>s;
		char a, b, c, d, e, f;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> c >> d >> e >> f;
			vec[i].push_back(a);
			vec[i].push_back(b);
			vec[i].push_back(c);
			vec[i].push_back(d);
			vec[i].push_back(e);
			vec[i].push_back(f);
			s.insert(a);
			s.insert(b);
			s.insert(c);
			s.insert(d);
			s.insert(e);
			s.insert(f);
		}
		int id = 0;
		for (set<char>::iterator i = s.begin(); i != s.end(); i++)
		{
			mp[*i - 'A'] = id;
			mp2[id] = *i - 'A';
			id++;
		}
		Graph g((int)s.size());
		for (int i = 0; i < n; i++)
		{
			a = vec[i][0];
			b = vec[i][1];
			c = vec[i][2];
			d = vec[i][3];
			e = vec[i][4];
			f = vec[i][5];
			if (a != f)
				g.addEdge(mp[f - 'A'],mp[ a - 'A']);
			if (b != f)
				g.addEdge(mp[f - 'A'], mp[b - 'A']);
			if (c != f)
				g.addEdge(mp[f - 'A'], mp[c - 'A']);
			if (d != f)
				g.addEdge(mp[f - 'A'], mp[d - 'A']);
			if (e != f)
				g.addEdge(mp[f - 'A'], mp[e - 'A']);
		}
		g.printSCCs();
		for (int i = 0; i < output.size(); i++)
		{
			sort(output[i].begin(), output[i].end());
		}
		sort(output.begin(), output.end(),cmp);
		for (int i = 0; i < output.size(); i++)
		{
			bool f = false;
			for (int j = 0; j < output[i].size(); j++)
			{
				cout << output[i][j];
				if (j != output[i].size() - 1)cout << " ";
				f = true;
			}
			if(f)
			cout << endl;
		}
		vec.clear();
		output.clear();
		output.resize(1);
		output[0] = "";
		memset(vis, 0, sizeof vis);
		memset(mp, 0, sizeof mp);
		memset(mp2, 0, sizeof mp2);
		cin >> n;
		if(n!=0)
		cout << endl;
	}
	return 0;
}
