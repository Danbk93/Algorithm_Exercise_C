#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int a, b, T;
char c;

int main() {

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (int i = 0; i < T; i++) {

		scanf("%d%d", &a, &b);

		cout << "Case "<< "#" << i+1 << ": " << a + b << endl;
	}

}
