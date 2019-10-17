#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include<string>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int r,c,t;
int map[51][51];
int visited[51][51];
int dist[51][51];

vector<pair<int, int> > virus;
vector<pair<int, int> > aircon;



void bfs(int num, int a, int b) {

	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	memset(visited, 0, sizeof(visited));

	visited[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {

			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visited[nx][ny] == 1)continue;
			if (map[nx][ny] == 0) {
				visited[nx][ny] = 1;
				dist[nx][ny] = dist[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
			else if (map[nx][ny] == 2) {
				visited[nx][ny] = 1;
				dist[nx][ny] = dist[x][y];
				q.push(make_pair(nx, ny));
			}

		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c>>t;

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < c; j++) {
			int a;
			cin >> a;
			map[i][j] = a;
			if (a != 0) {

				virus.push_back(make_pair(i, j));
			}
			else if (a == -1) {
				aircon.push_back(make_pair(i, j));
			}
			
		}

	}

}
