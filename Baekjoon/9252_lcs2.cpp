#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int table[1001][1001] = { 0 };
	string string1;
	string string2;
	cin >> string1 >> string2;


	string1 = '0' + string1;
	string2 = '0' + string2;

	for (int i = 1; i < string1.size(); i++) {
		for (int j = 1; j < string2.size(); j++) {

			if (string1[i] == string2[j]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else {
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		
		}
	}

	for (int i = 0; i < string1.size(); i++) {
		for (int j = 0; j < string2.size(); j++) {

			cout << table[i][j] <<" ";

		}
		cout << "\n";
	}



	int x = string1.size()-1;
	int y = string2.size()-1;
	stack<int> lcs;

 	while (table[x][y] != 0) {

		if (table[x][y] == table[x-1][y]) {
			x--; 
		}else if (table[x][y] == table[x][y - 1]) {
			y--;
		}else if (table[x][y] == table[x - 1][y - 1] + 1) {
			lcs.push(x);
			x--;
			y--;
		}
	}
		

	cout << table[string1.size() - 1][string2.size() - 1]<<endl;
	while (!lcs.empty()) {
		cout << string1[lcs.top()];
		lcs.pop();
	}
	

}