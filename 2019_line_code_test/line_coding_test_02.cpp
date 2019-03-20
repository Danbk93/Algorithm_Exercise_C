#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

string chemical;
vector<char> alpha;
vector<char> num;

int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool check = true;
	

	cin >> chemical;

	int ch_size = chemical.length();


	if (ch_size % 2 == 0) {

		for (int i = 1; i <= ch_size; i++) {

			if (isalpha(chemical[i-1]) && i <= ch_size / 2) {
				
				alpha.push_back(chemical[i-1]);
			}
			else if (!isalpha(chemical[i-1]) && i > ch_size / 2) {
				num.push_back(chemical[i-1]);
			}
			else {
				check = false;
				break;
			}
		}


	}
	else {

		check = false;
	}


	if (check) {
		for (int i = 0; i < ch_size / 2; i++) {
			cout << alpha[i];
			if (num[i] != '1') {

				cout << num[i];
			}
		
		}
	}
	else {
		cout << "error";
	}






}



