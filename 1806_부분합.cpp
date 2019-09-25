#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 100000;
int arr[MAX];
const int INF = 987654321;

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int N, S;

	cin >> N >> S;



	for (int i = 0; i < N; i++)

		cin >> arr[i];


	int low = 0, high = 0;

	int sum = arr[0];

	int result = INF;

	//투 포인터 알고리즘 적용

	while (low <= high && high < N)

	{

		if (sum < S)

			sum += arr[++high];

		else if (sum == S)

		{

			result = min(result, (high - low + 1));

			sum += arr[++high];

		}

		else if (sum > S)

		{

			result = min(result, (high - low + 1));

			sum -= arr[low++];

		}

	}



	if (result == INF)

		cout << 0 << "\n";

	else

		cout << result << "\n";

	return 0;

}
	