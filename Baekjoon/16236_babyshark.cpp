#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int N;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0 };
int map[21][21];
int visited[21][21];
int flag = 0;

struct shark {
	int x;
	int y;
	int scale;
	int eat;
	int time;
};
shark baby_shark;

bool compare(shark a, shark b){
	if (a.time == b.time) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		return a.x < b.x;
	}
	return a.time < b.time;
}

void bfs() {
	queue<shark> q;
	vector<shark> v;
	q.push(baby_shark);
	memset(visited, 0, sizeof(visited));
	v.clear();
	visited[baby_shark.x][baby_shark.y] = 1;
	flag = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int scale = q.front().scale;
		int eat = q.front().eat;
		int time = q.front().time;
		
		q.pop();
		for (int i = 0; i < 4; i++) {

		/*	for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << visited[i][j];

				}
				cout << endl;
			}
			cout << endl;*/
		
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visited[nx][ny] == 1)continue;
			if (map[nx][ny] == 0 || map[nx][ny] == scale) {
				visited[nx][ny] = 1;
				q.push({ nx,ny,scale,eat,time+1 });
			}
			else if (map[nx][ny] < scale) {

				visited[nx][ny] = 1;
				v.push_back({ nx,ny,scale,eat+1,time + 1 });

			}

		}
		
	}
	if (v.empty()) {
		flag = 1;
	}
	else {
		sort(v.begin(), v.end(), compare);

		map[v[0].x][v[0].y] = 0;
		if (v[0].eat == v[0].scale) {
			v[0].scale++;
			v[0].eat = 0;
		}

		


		baby_shark = { v[0].x,v[0].y,v[0].scale,v[0].eat,v[0].time};
	}

	
}



int main(void) {
	
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				baby_shark = { i,j,2,0,0 };
			}
		}
	}
	
	while (1) {
		bfs();
		if (flag == 1) {

			cout << baby_shark.time;
			break;
		}

	}
	




}