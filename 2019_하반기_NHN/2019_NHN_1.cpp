#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include<string>
#include<hash_map>

using namespace std;

int n;
string arr[1001];



int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	hash_map<string, int> hm;



	for (int i = 0; i < n; i++) {
		
		cin >> arr[i];
		hm.insert(hash_map<string, int>::value_type(arr[i], 0));
	}
	int card = n;
	int difff = n;

	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i].compare(arr[j]) == 0) {
				difff--;

				hash_map<string,int>::iterator FindIter = hm.find(arr[i]);      // Key�� 10�� ��� ã��.

				if(FindIter != hm.end())
				{   // ã�Ҵٸ� �����

					FindIter->second++;     

				}
			

			}
			else {
				
			}
		}
		
	}
	
	cout << difff;
}