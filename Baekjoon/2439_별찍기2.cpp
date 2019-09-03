#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;

int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N - i - 1; j++) {
			cout << ' ';
		}
		for (int z = 0; z < i+1; z++) {
			cout << '*';
		}
		cout << endl;
	}

	
}