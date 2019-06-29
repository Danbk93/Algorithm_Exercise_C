#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;
int R, C, N;
char map[201][201];

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;

	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	while (N--) {

		if (cnt % 3 == 0) {

		}
		else if (cnt % 3 == 1) {
			
		}
		else if (cnt % 3 == 2) {
			
		
		
		}

		cnt++;
	}


}