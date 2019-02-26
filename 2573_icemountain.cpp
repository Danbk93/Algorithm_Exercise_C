#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M = 0;
int year = 0;
int map[301][301] = { 0 };
int melt_map[301][301] = { 0 };
int visited[301][301] = { 0 };
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

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

	//Ã¹ ¸Ê
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//°Ë»ç ÇÏ¸ç °Ô¼Ó ¹Ø¿¡ ¹Ýº¹ÇÏ±â 



		//³ì´Â ¸Ê (ÅÆÆÛ·¯¸®)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int melt = 0;
				if (map[i+1][j] == 0) {
					melt++;
				}
				if (map[i][j+1] == 0) {
					melt++;
				}
				if (map[i-1][j] == 0) {
					melt++;
				}
				if (map[i][j-1] == 0) {
					melt++;
				}
				melt_map[i][j] = melt;
			}
		}

		//³ì°í³­ ÈÄ ¸Ê
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
		
				map[i][j] -= melt_map[i][j];
				if (map[i][j] < 0) {
					map[i][j] = 0;
				}
			}
		}
		year++;

	
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout<< map[i][j];

		}
		cout << endl;
	}*/

	cout <<year;
}