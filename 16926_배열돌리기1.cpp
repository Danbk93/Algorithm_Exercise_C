#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int N, M, R,least;
int arr[301][301];
int flag;

int main(void){
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	
	cin >> N>> M>> R;

	if (N <= M) {
		least = N;
		flag = 0;
	}
	else {
		least = M;
		flag = 1;
	}
	least /= 2;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];

		}

	}

	while (R--) {
		while (least--) {
			N/2

		}


	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j];
		}

	}

}