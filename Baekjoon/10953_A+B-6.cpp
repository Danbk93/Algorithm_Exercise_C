#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int a, b,T;
char c;

int main() {

	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	cin >> T;
	for (int i = 0;i<T;i++) {

		scanf("%d%*c%d", &a, &b);

		cout << a + b << endl;
	}

}
//
//#include <stdio.h>
//
//int main(void) {
//	int tt, a, b;
//
//	scanf("%d", &tt);
//	for (int tc = 1; tc <= tt; tc++) {
//		scanf("%d%*c%d", &a, &b);
//		printf("%d\n", a + b);
//	}
//
//	return 0;
//}