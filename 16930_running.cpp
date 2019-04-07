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

void bfs(int a, int b) {
	queue<pair<int,int>> q;
	q.push(make_pair(a, b));
	visited[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx= dx[i] + x;
			int ny = dy[i] + y;

			if (visited[nx][ny] == 1)continue;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M|| nx==)continue;
			if () {
				q.push(make_pair(nx, ny));
				visited[nx][ny]==1
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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout<< map[i][j];
	//	}
	//	cout << endl;
	//}

	cin >> x_1 >> y_1 >> x_2 >> y_2;

	
}



