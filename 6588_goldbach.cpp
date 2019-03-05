#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(void)
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num = 1;

	int arr[1000001];
	vector<int> v;
	std::fill_n(arr, 1000001, 1);

	for (int i = 2; i <= sqrt(1000000); i++) {
		int sqr = pow(i, 2);

		for (int j = 0; sqr + (i*j) <= 1000000; j++) {

			arr[sqr + (i*j)] = 0;

		}


	}

	//for (int i = 1; i <= 1000000; i++) {

	//	cout << arr[i] << endl;

	//}
	//cout << endl;

	for (int i = 3; i <= 1000000; i++) {

		if (arr[i] == 1) {
			v.push_back(i);

		}

	}

	while (num != 0) {
		cin >> num;
		if (num == 0) {
			break;
		
		}
		

		for (int i = 0; i < v.size(); i++) {
			if (arr[num - v[i]] == 1)
			{

				cout << num << " = " << v[i] << " + " << num - v[i] << "\n";

				break;

			}
		
		}



	
	}
}