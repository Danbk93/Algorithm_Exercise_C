#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,x,y=0; 
	
	cin >> n;

	vector<int> solution;

	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;

		solution.push_back(temp);

	}

	sort(solution.begin(), solution.end(), [](int i, int j) { return abs(i) < abs(j); });

	long long temp = 9223372036854775807;
	for (int i = 0; i < n-1; i++) {
		if (abs(solution[i] + solution[i + 1]) < temp) {
			temp = abs(solution[i] + solution[i + 1]);
			x = solution[i];
			y = solution[i + 1];
		}
	}

	if (x < y)
		cout << x << " " << y;
	else
		cout << y << " " << x;
}