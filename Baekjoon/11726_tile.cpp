#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num=0;
	int dp[1000] = { 0 };

	cin >> num;
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2;i<=num; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}
	
	cout << dp[num];
}