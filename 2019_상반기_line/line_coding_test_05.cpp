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

	int N, K;
	int bigger = 0;
	bool visit[100001] = { 0, };

	cin >> N >> K;

	queue<pair<int, int>> q;

	q.push(pair<int, int>(N, 0));

	while (true) {

		while (!q.empty())
		{
			int pos = q.front().first;
			int depth = q.front().second;

			if (pos == K)
				break;

			q.pop();

			visit[pos] = true;

			if (pos - 1 >= 0 && !visit[pos - 1])
				q.push(pair<int, int>(pos - 1, depth + 1));
			if (pos + 1 <= 100000 && !visit[pos + 1])
				q.push(pair<int, int>(pos + 1, depth + 1));
			if (pos * 2 <= 100000 && !visit[pos * 2])
				q.push(pair<int, int>(pos * 2, depth + 1));
		}
		
		bigger++;
		K += bigger;
	}
	

	cout << q.front().second << endl;

	return 0;
}