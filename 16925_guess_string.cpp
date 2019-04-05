#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int N;
string ary[200][2];
vector<string> first;
string pref[200];

int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	char x = '0';
	char y = '0';
	int x_c = 0;
	int y_c = 0;

	string str = "0";
	char back = '0';

	

	for (int i = 0; i < 2*(N - 1); i++) {
		string a;
		cin >> a;
		string len = to_string(a.length());
		
		
		ary[i][0]= a;
		ary[i][1] = len;
	}
	//접두사 찾기
	for (int i = 0; i < 2 * (N - 1); i++) {
	
		if (i == 0) {
			x = ary[i][0].front();
			x_c++;
		}
		else if (x != ary[i][0].front()) {
			y = ary[i][0].front();
			y_c++;
		}
		else {
			x_c++;
		}
		
		
	}
	if (x_c < y_c) {
		str = y;
	}
	else {
		str = x;
		
	}
	x_c = 0;
	y_c = 0;

	//접미사 찾기
	for (int i = 0; i < 2 * (N - 1); i++) {

		if (i == 0) {
			x = ary[i][0].back();
			x_c++;
		}
		else if (x != ary[i][0].back()) {
			y = ary[i][0].back();
			y_c++;
		}
		else {
			x_c++;
		}


	}
	if (x_c <= y_c) {
		back = y;

	}
	else {
		back = x;

	}

	// 하나씩 더하기
	string A_can = "0";
	string B_can = "0";
	int aj = 0;
	int bj = 0;
	for (int i=2;i<=N-1; i++) {
		for (int j = 0; j < 2 * (N - 1); j++) {
			if (str == ary[j][0]) { // 이 부분 중복 되는거 고치기
				pref[j] = 'P';
			}else if (to_string(back) == ary[j][0]) {
				pref[j] = 'S';
			}

			if (ary[j][1] == to_string(i)) {
			
				if (A_can=="0") {
					A_can = ary[j][0];
					aj = j;
				}
				else {
					B_can = ary[j][0];
					bj = j;
				}
				
					
			}
		}
		cout << aj+1 <<" "<< bj+1<<endl; // 이부분도 중복 되는부분 있음 

		if (A_can.back()==back) {
			if (str == B_can.substr(0, i - 1)) {
				str = B_can;
				pref[bj] = 'P';
				pref[aj] = 'S';
			}else{
				str = A_can;
				pref[aj] = 'P';
				pref[bj] = 'S';
			}
			
		}
		else if (B_can.back() == back){
			if (str == A_can.substr(0, i - 1)) {
				str = A_can;
				pref[aj] = 'P';
				pref[bj] = 'S';
			}
			else {
				str = B_can;
				pref[bj] = 'P';
				pref[aj] = 'S';
			}
		}

		A_can = "0";
		B_can = "0";
	}

	cout << str+back<<endl;

	for (int i = 0; i < 2 * (N - 1); i++) {
		cout << pref[i];
	}


}



