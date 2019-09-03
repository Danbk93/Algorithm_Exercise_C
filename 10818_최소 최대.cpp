#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int n,xmin,num;
int xmax;

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (i == 0) {
			xmin = num;
			xmax = num;
		}
		if (num <= xmin) {
			xmin = num;
		}
		if (num >= xmax) {
			xmax = num;
		}
		
	}


	cout << xmin<<" "<<xmax;

}