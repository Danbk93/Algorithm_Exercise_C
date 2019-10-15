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
				// 1) ���� ������ �� �����ϴ�.
				// 2) ��Ȱ��ȭ �� ���̷����� Ȱ��ȭ ���̷����� ������ Ȱ��ȭ �˴ϴ�.
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
				// ���� ��ĭ�ε� ���̷����� ������ �ʾ����� �����Դϴ�.
				if (check[i][j] == -1) {
					isClear = false;
					break;
				}
				// ���̷����� �������� �ִ� �ð��� �������ݴϴ�.
				else {
					max_time = max(max_time, check[i][j]);
				}
			}

		}
	}
	// �ּҽð��� �������ݴϴ�.
	if (isClear) result = min(result, max_time);
}

// ��͸� ���� m���� Ȱ��ȭ ���̷����� �������ݴϴ�.
void go(int idx) {
	if (idx == virus.size()) {

		if (pick.size() == m) {

			// ������ m���� ���̷����� ť�� �־��ݴϴ�.
			for (int i = 0; i < m; i++) q.push(pick[i]);

			// check �迭 �ʱ�ȭ
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					check[i][j] = -1;
				}
			}

			// m���� ���̷����� ���� ������ 0 ���� �����մϴ�.
			for (int i = 0; i < pick.size(); i++) {
				int x = pick[i].x;
				int y = pick[i].y;
				check[x][y] = 0;
			}

			// bfs Ž���� ���� ���� ��ü�� ���̷����� ������ �ּ� �ð��� ������ݴϴ�.
			bfs();

		}
		return;
	}

	// 1) idx��° ���̷��� ����
	pick.push_back({ virus[idx].x, virus[idx].y });
	go(idx + 1);
	pick.pop_back();

	// 2) idx��° ���̷����� �������� �ʰ� ������
	go(idx + 1);
}

int main() {

	freopen("input.txt","r",stdin);

	// 1. ������ �Է¹޽��ϴ�.
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			// 2. ���̷����� ��� x, y�� ���� �������ݴϴ�.
			if (a[i][j] == 2) virus.push_back({ i, j });
		}
	}

	// 3. ��ü ���̷����� ���� Ȱ��ȭ ��ų m���� �������ݴϴ�.
	go(0);

	// 4. ����� ����մϴ�.
	if (result == max_val) result = -1;
	printf("%d\n", result);
}