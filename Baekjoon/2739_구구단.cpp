#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

int N;

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i < 10; i++) {

		cout << N <<" * "<<i<<" = "<< N*i<< '\n';


	}

}
