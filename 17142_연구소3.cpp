#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include<string>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n,m;
int map[51][51];
int visited[51][51];
int dist[10][51][51];

int dummy[51][51];

vector<pair<int, int> > virus;
vector<int> ind;


void bfs(int num, int a,int b) {	

	queue<pair<int,int> > q;
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
				dist[num][nx][ny] =dist[num][x][y] + 1;
				q.push(make_pair(nx, ny));
			}else if (map[nx][ny] == 2) {
				visited[nx][ny] = 1;
				dist[num][nx][ny] = dist[num][x][y];
				q.push(make_pair(nx, ny));
			}
			
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			map[i][j]=a;
			if (a == 2) {
				
				virus.push_back(make_pair(i, j));
			}
		}

	}
	// 바이러스 하나씩 bfs 돌리기
	for (int i = 0; i < virus.size(); i++) {
		bfs(i, virus[i].first, virus[i].second);
		
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cout << dist[i][j][k] << ' ';                                                      
			} 
			cout << endl;
		}
		cout << endl;
	}
	

	//조합을 사용하여 바이러스 근원지 설정

	// 2개(6개-2개)의 0 추가
	for (int i = 0; i < virus.size() - m; i++) {
		ind.push_back(0);
	}

	// k개의 1 추가

	for (int i = 0; i < m; i++) {
		ind.push_back(1);
	}
	int ans = 10000;
	//순열
	do {

		int most = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {

				dummy[j][k] = 5000;
			}

		}

		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {

				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						if (dummy[j][k] >= dist[i][j][k]) {
							dummy[j][k] = dist[i][j][k];
						}
							
					}

				}
				//cout << virus[i].first << virus[i].second;
			}
		}


		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {

				if (dummy[j][k] >= most) {
					most = dummy[j][k];
				}
			}
			
		}

		if (ans > most) {
			ans = most;
		}
		
		//cout << most << endl;
	} while (next_permutation(ind.begin(), ind.end()));

	cout <<  ans;
}