#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int highest = 0;

	cin >> N;

	int v[10001] = {0};
	int all = 0;
	for (int i = 0; i < N; ++i) {
	
		cin >> v[i];

		all += v[i];
	}

	int M = 0;
	cin >> M;

	sort(v,v+N);

	int left = M;
	int not_given = N;
	if (all <= M) {
		highest = v[N - 1];
	}
	else {
		int even= M / N;
		for (int i = 0; i < N; i++) {
			if ((v[i] - even)<=0) {
				left -= v[i];
				
			}else {
				not_given = N - i ;
				even = left / not_given;
				if ((v[i] - even) > 0) {
					break;
				}
				i--;
			}
		}

		highest = left / not_given;
		
	}


	cout << highest;
}