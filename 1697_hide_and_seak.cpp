#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int main(void)
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N,K = 0;

	cin >> N>>K;

	int visited[200001] = { 0 };
	queue<pair<int, int>> q;
	q.push(make_pair(0, N));

	visited[N]++;

	while (!q.empty()) {
		int cnt = q.front().first;
		int pos = q.front().second;
		q.pop();

		if (pos == K) {
			cout << cnt << endl;
			break;
		}

		if (!visited[pos + 1]) {
			q.push(make_pair(cnt + 1, pos + 1));
			visited[pos + 1]++;
		}

		if (pos - 1 >= 0 && !visited[pos - 1]) {
			q.push(make_pair(cnt + 1, pos - 1));
			visited[pos - 1]++;
		}

		if (pos * 2 - K <= K - pos && !visited[pos * 2]) {
			q.push(make_pair(cnt + 1, pos * 2));
			visited[pos * 2]++;
		}

	}
}