#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int main(void)
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num = 1;
	int arr[1000001] = { 0 };

	while (num != 0) {
		cin >> num;
		if (num == 0) {
			break;
		
		}
		for (int i = 1; i <= num; i++) {

			arr[i] == i;

		}

		for (int i = 2; i <= num; i++) {
			for (int j = 1; (i ^ 2)*j <=num;j++ ) {

				arr[(i ^ 2)*j] = 0;
			}
			
		
		}

		for (int i = 1; i <= num; i++) {

			cout<<arr[i];

		}
	
	}
}