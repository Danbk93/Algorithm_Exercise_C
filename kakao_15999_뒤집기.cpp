#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;
int n, m;
char arr[2001][2001];
int tmp[2001][2001];
int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j + 1 < m && arr[i][j] != arr[i][j + 1]) {
				tmp[i][j] = 1;
				tmp[i][j + 1] = 1;
			}
			if (i + 1 < n && arr[i][j] != arr[i + 1][j]) {
				tmp[i][j] = 1;
				tmp[i + 1][j] = 1;
			}
		}
	}



	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				ans *= 2;
				ans= ans % 1000000007;
			}
		}

	}

	cout << ans;

}
