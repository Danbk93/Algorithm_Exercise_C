#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

string N;

int main() {

	freopen("input.txt", "r", stdin);
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N.size(); i++) {
		cnt++;
		cout << N[i];

		if (cnt % 10 == 0) {
			cout << endl;
		}

	}
	
}
