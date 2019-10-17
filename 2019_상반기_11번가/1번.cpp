#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int N;
vector<int> v;

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	int number = N;
	int largest = 0;
	int jin = 0;
	

	for ( int i = 2; i <= 10; i++) {
		N = number;
		for (int j = 0; N > 0; j++) {	
			v.push_back(N % i);
			N = N / i;
		}
		int jari = 1;
		for (int k = 0;k<v.size();k++) {

			if (v[k] != 0) {
				jari = jari * v[k];
			}
		}
		if (jari >= largest) {
			largest = jari;
			jin = i;
		}
		v.clear();	
	}
	cout << jin <<" " <<largest;
	return 0;

}
