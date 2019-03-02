#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> maxnumber;
vector<int> minnumber;

int main(void)
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 0;
	char sign[10] = { '0' };

	cin >> k;

	for (int i = 0; i < k; i++) {
	
		cin >> sign[i];
	
	}

	for (int i = 9; i > 9 - (k + 1); i--) {
		maxnumber.push_back(i);
	}
	for (int i = 0; i < (k + 1); i++) {
		minnumber.push_back(i);
	}
	bool flag = true;
	while (1){

			for (int i = 0; i < k; i++) {

				if (sign[i] == '<' && maxnumber[i] > maxnumber[i + 1]) {
					flag = false;
					break;

				}
				else if (sign[i] == '>' && maxnumber[i] < maxnumber[i + 1]) {
					flag = false;
					break;
				}
				else {
					flag = true;
				}

			}
		
			if (flag) {
			
				break;
			}
			else {
			
				prev_permutation(maxnumber.begin(), maxnumber.end());
			}
		
	}

	while (1) {

		for (int i = 0; i < k; i++) {

			if (sign[i] == '<' && minnumber[i] > minnumber[i + 1]) {
				flag = false;
				break;
			}
			else if (sign[i] == '>' && minnumber[i] < minnumber[i + 1]) {
				flag = false;
				break;
			}
			else {
				flag = true;
			}

		}

		if (flag) {

			break;
		}
		else {

			next_permutation(minnumber.begin(), minnumber.end());
		}
		
	}


	for (int i = 0; i < maxnumber.size(); i++) {
		cout << maxnumber[i];
	}
	cout << endl;

	for (int i = 0; i < minnumber.size(); i++) {
		cout << minnumber[i];
	}
	cout << endl;
}