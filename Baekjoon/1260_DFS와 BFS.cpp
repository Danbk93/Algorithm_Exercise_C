#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int N, M, V;
vector<pair<int, int>> v;
int visited[1001];

bool compare(pair<int, int> a, pair<int, int> b){
	
	if (a.first == b.first) {
		return a.second < b.second;
	}return a.first < b.first;
}

void bfs(int a) {
	memset(visited, 0, sizeof(visited));
	queue< int> q;
	q.push(a);
	visited[a] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x <<" ";
		for (int i = 0; i < M*2; i++) {
		
			if (v[i].first == x) {
				int y = v[i].second;
				if (visited[y] == 1)continue;
				q.push(y);
				visited[y]=1;
			
			}
		}
	}

}
void dfs(int a) {
	visited[a] = 1;
	cout << a << " ";
	for (int i = 0; i < M * 2; i++) {

		if (v[i].first == a) {
			int y = v[i].second;
			if (visited[y] == 1)continue;
			visited[y] = 1;
			dfs(y);
		}
	}

}

int main() {
	freopen("input.txt", "r", stdin );
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		
		int x = 0;
		int y = 0;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
		v.push_back(make_pair(y, x));
	
	}
	sort(v.begin(), v.end(), compare);

	dfs(V);
	cout << endl;
	bfs(V);
	

}