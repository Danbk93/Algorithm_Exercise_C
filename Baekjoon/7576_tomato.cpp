#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
int box[1001][1001];
queue<int> ripe;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int visited[1001][1001];
int day;

int main(void){
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j]==1) {
				ripe.push(i * 10000 + j);
				visited[i][j] = 1;
			}

		}

	}

	while (1) {
		queue<int> next_ripe;
		while (!ripe.empty()) {
			int y = ripe.front() / 10000;
			int x = ripe.front() % 10000;
			
			ripe.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;

				if (visited[ny][nx] || box[ny][nx] != 0)
					continue;

				visited[ny][nx] = 1;
				box[ny][nx] = 1;
				next_ripe.push(ny * 10000 + nx);
			}
			
		}

		ripe = next_ripe;
		if (ripe.empty()) {
			break;
		}
		day++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				day = -1;
				break;
			}

		}
	}			

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << box[i][j];

		}
		cout<<endl;

	}
	cout <<day<< endl;

}