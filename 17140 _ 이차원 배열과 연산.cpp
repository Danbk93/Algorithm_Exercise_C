#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;

const int MAX = 100;

int r, c, k;
int A[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> k;
	r -= 1, c -= 1;

	int time = 0;
	bool flag = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int num;
			cin >> num;

			A[i][j] = num;
			if (i == r && j == c && num == k)
				flag = true;
		}
	}

	int row = 3, col = 3;
	while (!flag)
	{
		time++;
		if (time > MAX)
		{
			cout << -1 << "\n";
			return 0;
		}

		vector<pair<int, int>> v[MAX];
		//R
		if (row >= col)
		{
			for (int i = 0; i < row; i++)
			{
				int cnt[MAX + 1] = { 0, };
				//각 열 숫자 개수 파악
				for (int j = 0; j < col; j++)
					cnt[A[i][j]]++;

				//v[i]는 i번째 열에 나타난 {숫자 등장 횟수, 숫자}
				for (int j = 1; j <= MAX; j++)
					if (cnt[j])
						v[i].push_back({ cnt[j], j });
			}

			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					A[i][j] = 0;

			//{숫자 등장 횟수, 숫자}를 기준으로 오름차순
			for (int i = 0; i < row; i++)
				sort(v[i].begin(), v[i].end());

			for (int i = 0; i < row; i++)
			{
				int tempIdx = 0;
				for (int j = 0; j < v[i].size(); j++)
				{
					A[i][tempIdx++] = v[i][j].second;
					if (tempIdx == MAX)
						break;
					A[i][tempIdx++] = v[i][j].first;
					if (tempIdx == MAX)
						break;
				}
				col = max(col, tempIdx);
			}
		}
		//C
		else
		{
			for (int i = 0; i < col; i++)
			{
				int cnt[MAX + 1] = { 0, };
				//각 행 숫자 파악
				for (int j = 0; j < row; j++)
					cnt[A[j][i]]++;

				//v[i]는 각 행에 등장한 {숫자 등장횟수, 숫자}
				for (int j = 1; j <= MAX; j++)
					if (cnt[j])
						v[i].push_back({ cnt[j], j });
			}

			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					A[i][j] = 0;

			//{숫자 등장 횟수, 숫자}를 기준으로 오름차순
			for (int i = 0; i < col; i++)
				sort(v[i].begin(), v[i].end());

			for (int i = 0; i < col; i++)
			{
				int tempIdx = 0;
				for (int j = 0; j < v[i].size(); j++)
				{
					A[tempIdx++][i] = v[i][j].second;
					if (tempIdx == MAX)
						break;
					A[tempIdx++][i] = v[i][j].first;
					if (tempIdx == MAX)
						break;
				}
				row = max(row, tempIdx);
			}
		}

		if (A[r][c] == k)
		{
			flag = true;
			break;
		}
	}
	cout << time << "\n";
	return 0;
}