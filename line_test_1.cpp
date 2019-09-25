#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>

using namespace std;

int m,c;

vector<int> consumer_time;

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> m>> c;

	for (int i = 0; i < m; i++) {
		int a = 0;
		cin >> a;

		if (i < c) {
			consumer_time.push_back(a);
		}
		else {
			int flag = 0;
			int least = 101;
			for (int j = 0; j < consumer_time.size(); j++) {
		
				if (least >= consumer_time[j]) {
					least = consumer_time[j];
					flag = j;
				}

			}
	
			consumer_time[flag] = consumer_time[flag] + a;
			flag = 0;
			least = 101;

		
		}
	
	}


	int large = 0;
	for (int k = 0; k < consumer_time.size(); k++) {
		if (large <= consumer_time[k]) {
			large = consumer_time[k];
		}
	}
	cout << large;

	
}