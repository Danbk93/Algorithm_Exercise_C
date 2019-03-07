#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N,M,P;
int power[10];
char map[1001][1001];

struct castle {
	char num;
	int x; 
	int y; 
};

queue<char> q;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int visited[1001][1001];


int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> P;

	for (int i = 0; i < P; i++) {
		cin >> power[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != '.' || map[i][j] != '#') {

				q.push(map[i][j]);
				visited[i][j] = 1;
			}
		}
	}
	
	while (1) {
		queue<char> next_castle;
		while (!castle.empty()) {
			int y = castle.front() / 10000;
			int x = castle.front() % 10000;

			castle.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;

				if (visited[ny][nx] || map[ny][nx] != 0)
					continue;

				visited[ny][nx] = 1;
				map[ny][nx] = 1;
				next_castle.push(ny * 10000 + nx);
			}

		}

		castle = next_castle;
		if (castle.empty()) {
			break;
		}
	}


	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j];

		}
		cout << endl;

	}

}



