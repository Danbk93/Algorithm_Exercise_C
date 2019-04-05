#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N;
int arr[1001];
vector<int> v;
vector<int> v2;

int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int count = 0;
	cin >> N;
	int num[4] = { 1,5,10,50 };
	v.push_back(0);

	while (N--) {
		for (int j = 0; j < 1001; j++) {

			arr[j] = 0;
		}

		for (int i = 0; i < v.size(); i++) {
			int number = v[i];
			
			for (int j = 0; j < 4; j++) {

				if (arr[number + num[j]] == 0) {
					arr[number + num[j]] = 1;
					v2.push_back(number + num[j]);
				
				}
		
			}

		}
		v = v2;	
		v2.clear();
	}

	for (int j = 1; j < 1001; j++) {
		
		if (arr[j]==1) {

			count++;
		}
	}
	cout << count;
	

}



