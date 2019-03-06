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

void dfs(int x,int y) {

	for (int i = 0; i < 4; i++) {
		x += dx[i];
		y += dy[i];

		if (x >= 0 && x < N && y >= 0 &&y<M) {
			box[x][y] == 1;
			visited[x][y] == 1;
			dfs(x, y);
		}
	
	}
	day++;

}

int main(void){
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j]) {

				ripe.push(i * 10000 + j);
			}

		}

	}

	while (!ripe.empty()) {
		int x = ripe.front() / 10000;
		int y = ripe.front() % 10000;
		visited[x][y] = 1;
		ripe.pop();
		dfs(x,y);
	}


	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << box[i][j];

	//	}
	//	cout<<endl;

	//}
	cout <<day<< endl;

}