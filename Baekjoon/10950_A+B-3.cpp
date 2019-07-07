#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int T;
int a, b;

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int i=0; i < T; i++) {
		cin >> a >> b;
		cout << a + b<<endl;
	}

}