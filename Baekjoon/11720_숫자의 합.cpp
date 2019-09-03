#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int N;

int main() {

	freopen("input.txt", "r", stdin);
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp=0;
		scanf("%1d", &temp);
		ans += temp;
	}
	printf("%d", ans);
}
