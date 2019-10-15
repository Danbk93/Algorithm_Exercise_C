#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include<string>

using namespace std;

int n;
vector<int> v;
int check[101];
int max_arr[101];

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string sol;
		int a;
		cin >> sol;
		if (sol == "enqueue") {
			cin >> a;

			v.push_back(a);
			check[a]++;

		
		}
		else {
			int max = 0;
			
			for (int j = 0; j < 101; j++) {
			
				max_arr[j]=0;
			
			}


			for (int j = 0; j < 101; j++) {
				if (check[j] > max && check[j] != 0) {
					max = check[j];
					
				
				}
			}
			for (int j = 0; j < 101; j++) {
				if (max == check[j]) {
					max_arr[j]++;
				}
			}

		

			for (int k = 0;k<v.size();k++) {
				int flag=0;
			
				for (int j = 0; j < 101; j++) {
				
					if (max_arr[j] == 1 && j == v[k]){
						cout << v[k] << " ";
						v[k] = 0;
						check[j]--;
						flag = 1;
						break;
					}
				
				}
				if (flag == 1) {
					break;
				}
			}
				
		}

	}
		
		
}

	
