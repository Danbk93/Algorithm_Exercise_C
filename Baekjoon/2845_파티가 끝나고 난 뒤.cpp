#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int L, P;
int news[5];

int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	cin >> L >> P;
	for (int i = 0; i < 5; i++) {

		cin >> news[i];
	}

	int real = L * P;
	
	cin >> L >> P;
	for (int i = 0; i < 5; i++) {

		cout<< news[i]-real<<" ";
	}
	
}