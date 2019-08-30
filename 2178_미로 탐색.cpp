#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
char map[101][101];
int visited[101][101];
int dist[101][101];

void bfs(int a,int b ) {
	queue<pair<int, int>> q;
	q.push(make_pair(a,b));
	visited[a][b] = 1;
	dist[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == '0')continue;
			if (visited[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
				dist[nx][ny] = dist[x][y] + 1;
			}
			

	/*		for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {

					cout << dist[i][j];
				}
				cout << endl;
			}
			cout << endl;*/
		}

	}



}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			cin >> map[i][j];
		}

	}
	bfs(0, 0);

	cout << dist[n-1][m-1];


}