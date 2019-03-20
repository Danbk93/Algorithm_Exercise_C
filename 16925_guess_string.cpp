#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int N;
vector<string> v;

int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string first = "0";
	string last = "0";

	string front= "0";
	string back = "0";

	string whole = "0";
	int cnt = 0;
	int re_cnt = 0;
	cin >> N;
	for (int i = 0; i < 2*(N - 1); i++) {
		string a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < 2 * (N - 1); i++) {

		if (size(v[i]) == N-1) {
			
			if (front != "0") {
				back = v[i];
			}
			else {
				front = v[i];
			}
		}else if (size(v[i]) == 1) {

			if (first != "0") {
				last = v[i];
			}
			else {
				first = v[i];
			}
		}
	}


	for (int i = 0; i < N - 2; i++) {
			if (front[i+1] == back[i]) {
				cnt++;

			}
			
			if (back[i + 1] == front[i]) {

				re_cnt++;
			}
	}

	if (cnt == N - 2) {
		whole = front + back[N - 2];

		if (first[0] == whole[0] && last[0] == whole[N - 2]) {

			check(whole);

		}
		else if{

			
		}

	}
	
	if (re_cnt == N - 2) {
		whole = back+ front[N - 2];
		cout << whole;
	}


}



