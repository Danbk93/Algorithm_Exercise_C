#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K= 0;
	long long dp[202][202] = { 0 };
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (i == 0 && j > 0) {
				dp[i][j] = 1;
			}
			if (i > 0 && j > 0) {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
			}
		}
	}


	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			
			cout << dp[i][j]<<" ";

		}
		cout << endl;
	}

	cout << dp[N][K];
}