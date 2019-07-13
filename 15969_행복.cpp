#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N = 0;

vector<int> grade;

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int g = 0;
		cin >> g;
		grade.push_back(g);
	}
	sort(grade.begin(), grade.end());

	cout << grade[N - 1] - grade[0];
}