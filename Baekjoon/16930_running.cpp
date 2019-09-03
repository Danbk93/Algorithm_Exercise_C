#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
int N,M,K;
char map[1001][1001];
int x_1, y_1, x_2, y_2;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int visited[1001][1001];
int dist[1001][1001];
int flag;
void bfs(int a, int b) {
	queue<pair<int,int>> q;
	q.push(make_pair(a, b));
	visited[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		/*for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cout << visited[i][j];
			}
			cout << endl;
		}
		cout << endl;*/
		
		if (x == x_2 && y == y_2) {
			cout << dist[x][y];
			break;
		}


		/*	for (int i = 0; i < 4; i++) {
					int nx = dx[i]+ x;
					int ny = dy[i]+ y;

					if (nx < 1 || nx > N || ny < 1 || ny > M || map[nx][ny] == '#') continue;
					if (visited[nx][ny] == 0) {
						q.push(make_pair(nx, ny));

						visited[nx][ny] = 1;

						dist[nx][ny] = dist[x][y] + 1;
					}
				}

			}*/

		for (int i = 0; i < 4; i++) {
			for (int j = K; j >= 1; j--) {

				flag = 0;
				for (int n = j; n >= 1; n--) {
					int nnx = dx[i] * n + x;
					int nny = dy[i] * n + y;

					if (nnx < 1 || nnx > N || nny < 1 || nny > M) continue;
					if (map[nnx][nny] == '#') {
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					continue;
				}
				int nx = dx[i] * j + x;
				int ny = dy[i] * j + y;

				if (nx < 1 || nx > N || ny < 1 || ny > M ) continue;
				if (visited[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					for (int z = j; z >= 1; z--) {
						int nnx = dx[i] * z + x;
						int nny = dy[i] * z + y;

						visited[nnx][nny] = 1;

					}
					dist[nx][ny] = dist[x][y] + 1;
				}
			}



		}
	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	//input
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= M; j++) {
	//		cout<< map[i][j];
	//	}
	//	cout << endl;
	//}

	cin >> x_1 >> y_1 >> x_2 >> y_2;

	bfs(x_1, y_1);

	if (visited[x_2][y_2] == 0) {
		cout << -1;
	}

}



