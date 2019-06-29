#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int n;

void pr(int i, int j) {
	while (i != 0) {
		if (i % 3 == 1 && j % 3 == 1) {
			cout << ' ';
			return;
		}
		i =i/3;
		j = j / 3;
	}
	cout << '*';

}


int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pr(i, j);
		}
		cout << endl;
	}


}