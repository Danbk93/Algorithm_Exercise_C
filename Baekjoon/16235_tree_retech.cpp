#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
int N, M, K;
int x, y, z;
int A[11][11];
int d[11][11];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int cnt;

struct tree_info {
	int x;
	int y;
	int age;
};

vector<tree_info> v;

bool cmp(tree_info a, tree_info b) {

	if (a.x == b.x && a.y == b.y) {
		return a.age < b.age;
	}
	else {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		else {
			return a.x < b.x;
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
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			d[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, age = 0;
		cin >> x >> y >> age;

		v.push_back({ x,y,age });
		
	}


	while (K--) {
		sort(v.begin(), v.end(), cmp);

		vector<tree_info> alive;
		vector<tree_info> dead;
		vector<tree_info> five;
		vector<tree_info> birth;

		//봄
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].x;
			int y = v[i].y;
			int age = v[i].age;

			if (d[x][y] < age) {
				dead.push_back({ x, y, age });
			}
			else {
				d[x][y] -= age;
				v[i].age++;
				alive.push_back({ x, y, v[i].age });
				if (v[i].age % 5 == 0) five.push_back({ x, y, v[i].age });
			}

		}

		//여름
		for (int i = 0; i < (int)dead.size(); i++) {
			int x = dead[i].x;
			int y = dead[i].y;
			int age = dead[i].age;
			int feed = age / 2;

			d[x][y] += feed;
		}

		//가을
		for (int k = 0; k < five.size(); k++) {
			int x = five[k].x;
			int y = five[k].y;

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
					birth.push_back({ nx, ny, 1 });
				}
			}
		}

		//겨울
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[i][j] += A[i][j];
			}
		}

		v.clear();
		for (int i = 0; i < (int)alive.size(); i++) {
			int x = alive[i].x;
			int y = alive[i].y;
			int age = alive[i].age;
			v.push_back({ x, y, age });
		}

		for (int i = 0; i < (int)birth.size(); i++) {
			int x = birth[i].x;
			int y = birth[i].y;
			int age = birth[i].age;
			v.push_back({ x, y, age });
		}

		alive.clear();
		birth.clear();
		dead.clear();
		five.clear();

		cnt = (int)v.size();
		
	}
	cout << cnt;
}



