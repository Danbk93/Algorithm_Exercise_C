#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;


int T;
int whos[19];
int in[9];
vector<int> kyu;


int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;

	for(int i=0;i<T;i++){

		int win = 0;
		int lost = 0;

		for (int j=0; j < 9; j++) {
			int a = 0;
			cin >> a;
			whos[a] = 1;
			in[j] = a;
		}

		for (int h = 0; h< 19; h++) {
	
			if (whos[h] == 0) {

				kyu.push_back(h);
			}
			
		}



		next_permutation(kyu.begin(),kyu.end());



		cout << "#" << i << " " << win<<" "<<lost;

		for (int k = 0; k < 19; k++) {
			whos[k] = 0;
		}
	}



}



