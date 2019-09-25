#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;

int n;

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		

		for (int j = 0; j < i;j++) {
			cout << ' ';
	
		
		}
		for (int k = n; k > i; k--) {
			cout << '*';
		}
	
			cout <<endl;

	}
	

}