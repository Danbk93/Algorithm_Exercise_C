#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M = 0;
int year = 0;
int map[301][301] = { 0 };
int melt_map[301][301] = { 0 };
int visited[301][301] = { 0 };
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int island = 1;
int cnt = 0;
bool check = false;
queue<pair<int, int>> q;

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		if (map[ny][nx] && !visited[ny][nx]) {
			visited[ny][nx] = 1;
			dfs(ny, nx);
		}
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> M;

	//첫 맵
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j]) q.push(make_pair(i, j));
		}
	}

	//검사 하며 게속 밑에 반복하기 
	while (!q.empty()) {
		while (!q.empty()) {
			int i = q.front().first;
			int j = q.front().second;
			
			q.pop();
			if (map[i][j] && !visited[i][j]) {
				visited[i][j] = 1;
				cnt++;
				dfs(i, j);
			}
			
		}
		if (cnt > 1) {
			check = true;
			break;
		}
		cnt = 0;
		

		////visited map print
		//cout << "visited map" << endl;
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < M; j++) {
		//		cout << visited[i][j];
		//	}
		//	cout << endl;
		//}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int melt = 0;
				if (map[i + 1][j] == 0) {
					melt++;
				}
				if (map[i][j + 1] == 0) {
					melt++;
				}
				if (map[i - 1][j] == 0) {
					melt++;
				}
				if (map[i][j - 1] == 0) {
					melt++;
				}
				melt_map[i][j] = melt;
			}
		}


		//녹고난 후 맵
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				map[i][j] -= melt_map[i][j];
				if (map[i][j] < 0) {
					map[i][j] = 0;
				}
				if (map[i][j]) q.push(make_pair(i, j));
			}
		}
		year++;

		// map print
		//cout << "map" << endl;
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < M; j++) {
		//		cout << map[i][j];
		//	}
		//	cout << endl;
		//}

		//초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				melt_map[i][j] = 0;
				visited[i][j] = 0 ;
			}
		}
	}
	
	
	if (check == false)
		year = 0;

	cout <<year;
}