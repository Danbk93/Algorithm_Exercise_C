#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max_int 51
#define max_val 2147483647
using namespace std;


int n, m, a[max_int][max_int], check[max_int][max_int], result = max_val;

struct info {
	int x;
	int y;
};

vector<info> virus, pick;
queue<info> q;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

void bfs() {

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				// 1) 벽은 지나갈 수 없습니다.
				// 2) 비활성화 된 바이러스는 활성화 바이러스를 만나면 활성화 됩니다.
				if (a[nx][ny] != 1 && check[nx][ny] == -1) {
					check[nx][ny] = check[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	bool isClear = true;
	int max_time = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				// 만약 빈칸인데 바이러스가 퍼지지 않았으면 실패입니다.
				if (check[i][j] == -1) {
					isClear = false;
					break;
				}
				// 바이러스가 퍼졌으면 최대 시간을 갱신해줍니다.
				else {
					max_time = max(max_time, check[i][j]);
				}
			}

		}
	}
	// 최소시간을 갱신해줍니다.
	if (isClear) result = min(result, max_time);
}

// 재귀를 통해 m개의 활성화 바이러스를 선택해줍니다.
void go(int idx) {
	if (idx == virus.size()) {

		if (pick.size() == m) {

			// 선택한 m개의 바이러스를 큐에 넣어줍니다.
			for (int i = 0; i < m; i++) q.push(pick[i]);

			// check 배열 초기화
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					check[i][j] = -1;
				}
			}

			// m개의 바이러스에 대해 시작을 0 으로 설정합니다.
			for (int i = 0; i < pick.size(); i++) {
				int x = pick[i].x;
				int y = pick[i].y;
				check[x][y] = 0;
			}

			// bfs 탐색을 통해 지도 전체에 바이러스가 퍼지는 최소 시간을 계산해줍니다.
			bfs();

		}
		return;
	}

	// 1) idx번째 바이러스 선택
	pick.push_back({ virus[idx].x, virus[idx].y });
	go(idx + 1);
	pick.pop_back();

	// 2) idx번째 바이러스를 선택하지 않고 지나감
	go(idx + 1);
}

int main() {

	freopen("input.txt","r",stdin);

	// 1. 문제를 입력받습니다.
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			// 2. 바이러스일 경우 x, y를 따로 저장해줍니다.
			if (a[i][j] == 2) virus.push_back({ i, j });
		}
	}

	// 3. 전체 바이러스에 대해 활성화 시킬 m개만 선택해줍니다.
	go(0);

	// 4. 결과를 출력합니다.
	if (result == max_val) result = -1;
	printf("%d\n", result);
}