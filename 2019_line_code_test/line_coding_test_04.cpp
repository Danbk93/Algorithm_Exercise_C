#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include<string>

using namespace std;

int N;


int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<vector<int>> v(N+1, vector<int>(2));

	for (int i=1; i <= N; i++) {
	
		int a = 0;
		cin >> a;
		v[i][0] = a;
		v[i][1] = i;
	}

	sort(v.begin(), v.end());

	for(int i=N;;)


	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
		
			cout<< v[i][j]<<" ";
			
		}
		cout << endl;
	}





}



