#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int check[20002] = {0};
vector<int> v[20002];


void dfs(int node, int c)
{
	check[node] = c;
	for (int i = 0; i < v[node].size(); i++)
	{
		int next = v[node][i];
		if (check[next] == 0)
		{
			dfs(next, 3 - c);
		}
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int K, V, E = 0 ;
	cin >> K;

	while (K--)
	{
		cin >> V;
		cin >> E;

		for (int i = 0; i < E; i++)
		{
			int x, y = 0;
			cin >> x;
			cin >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}

		bool graph = true;

		for (int i = 1; i <= V; i++) {
		
			if (check[i] == 0)
			{
				dfs(i, 1);
				
			}
		}

		for (int i = 1; i <= V; i++)
		{
			for (int k = 0; k < v[i].size(); k++)
			{
				int j = v[i][k];
				if (check[i] == check[j])
				{
					graph = false;
				}
			}
		}
		
		if (graph == true) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		for (int i = 0; i < V; i++) {
			check[i] = 0;
			v[i].clear();
		}
	}
}
