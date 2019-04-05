#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int N, L, R;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int visited[51][51] = { 0, };
int map[51][51] = { 0, };
bool check = true;

void bfs(int a,int b) {	
	queue<pair<int, int>> q,nq;
	q.push(make_pair(a,b)); 
	nq.push(make_pair(a, b));
	visited[a][b] = 1;
	int sum = 0;
	int count = 0;
	int new_population = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		sum += map[x][y];
		count++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny] != 0) continue;
			if (abs(map[nx][ny]-map[x][y])<=R&& abs(map[nx][ny] - map[x][y]) >= L) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
				nq.push(make_pair(nx, ny));
			}
		}
	}
	
	new_population = sum / count;

	while (!nq.empty())
	{
		int x = nq.front().first;
		int y = nq.front().second;
		nq.pop();
		map[x][y] = new_population;
	}
}

bool checking(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (L <= abs(map[x][y] - map[nx][ny]) && abs(map[x][y] - map[nx][ny]) <= R) return true;
		}
	}
	return false;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> R;
	int movement=0;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

		}

	}

	while (check) {
		check = false;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j] == 0 && checking(i, j) == true)
				{
					bfs(i, j);
					check = true;
					
				}
		
			}
		}

		if (check == true) {
			movement++;
		}
		
		memset(visited, 0, sizeof(visited));

		////print
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		cout << map[i][j]<<" ";

		//	}
		//	cout << endl;
		//}
	}
	
	cout << movement;

	

}



