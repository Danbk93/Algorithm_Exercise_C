#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>

using namespace std;

int row, col, tr, tc;

 long long comb(int n, int r) {

	long long arr[50][50];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= r; j++) {
			if (i == j || j == 0) {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
				
		}
	}// nCr = (n-1)C(r-1) + (n-1)C(r)
	return arr[n][r];

}

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> col >> row;
	cin >> tr >> tc;
	if (tr < 0 || tc < 0 || tr > row || tc > col) {
		cout << "fail";
	}
	else {
		cout << tr + tc << endl<< comb(tr + tc, tc)<<endl;
	}
}