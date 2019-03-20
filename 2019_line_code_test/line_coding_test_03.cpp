#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N,M;


int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool chk = true;

	cin >> N;
	vector<vector<string>> table1(N,vector<string>(3));


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			string a;
			cin >> a;
			table1[i][j] = a;

		}


	}

	cin >> M;
	vector<vector<string>> table2(M, vector<string>(3));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 3; j++) {
			string a;
			cin >> a;
			table2[i][j] = a;
		}

	}

	sort(table1.begin(), table1.end());
	for (int j = 0; j < 5; j++) {
		if (j < 3) {

			cout << table1[N-1][j] << " ";

		}
		else {
			cout << table2[0][j-2] << " ";
		}

	}

	cout << endl;
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < 5; j++) {
			if (j < 3) {

				cout<< table1[i][j]<<" ";
			}
			else{
				for (int k = 0; k < M; k++) {
					if (table1[i][0] == table2[k][0]) {

						cout<<table2[k][j - 2] << " ";
						chk = true; 
						break;
					}
					else {
						chk = false;
					}
					
				}
				if(!chk){
					cout << "NULL" << " ";
					
				}
			}
		

		}
		cout << endl;
	}


}



