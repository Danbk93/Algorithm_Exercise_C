#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
int N;
string ary[200][2];
string pref[200];
int alphabet_p[27] = { 0, };
int alphabet_s[27] = { 0, };
int most = 0;
char prefix = '0';
char subfix = '0';

void find_P(){
	//접두사 찾기

	most = 0;
	for (int i = 1; i < 27; i++) {
		if (most < alphabet_p[i]) {
			most = alphabet_p[i];
			prefix = char(i + 96);
		}

	}
	cout << prefix << endl;

}
void find_S() {

	//접미사 찾기

	most = 0;

	for (int i = 1; i < 27; i++) {
		if (most < alphabet_s[i]) {
			most = alphabet_s[i];
			subfix = char(i + 96);
		}

	}
	cout << subfix << endl;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	//input
	for (int i = 0; i < 2*(N - 1); i++) {
		string a;
		cin >> a;
		string len = to_string(a.length());
		
		ary[i][0]= a;
		ary[i][1] = len;
	}


	for (int i = 0; i < 2 * (N - 1); i++) {
		alphabet_p[int(ary[i][0].front()) - 96]++;

	}
	find_P();

	for (int i = 0; i < 2 * (N - 1); i++) {
		alphabet_s[int(ary[i][0].back()) - 96]++;
	}

	find_S();

	
	for (int i = 1; i < 27; i++) {
		 
		cout << alphabet_p[i] << alphabet_s[i] <<endl;
		
	}

	//1 글자 prefix subfix 적용
	int f = 0;
	for (int j = 0; j < 2 * (N - 1); j++) {
		if (ary[j][1] == to_string(1)) {
			if (prefix == ary[j][0][0] && f == 0) {
				pref[j] = 'P';
				f = 1;
			}
			else if (subfix == ary[j][0][0]) {
				pref[j] = 'S';
			}
		}
	}

	string str(1, prefix);

	// 하나씩 더하기
	string A_can = "0";
	string B_can = "0";
	int aj = 0;
	int bj = 0;

	for (int i=2;i<=N-1; i++) {
		for (int j = 0; j < 2 * (N - 1); j++) {
		
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

		if (A_can.back()==subfix) {
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
		else if (B_can.back() == subfix){
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

	cout << str+subfix<<endl;

	for (int i = 0; i < 2 * (N - 1); i++) {
		cout << pref[i];
	}


}



