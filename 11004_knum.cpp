#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int v[5000001];
int sorted[5000001];

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void quick_sort(int left, int right, int* data) {
	int pivot = left;
	int j = pivot;
	int i = left + 1;
	
	if (left < right) {
		for (; i <= right; i++) {
			if (data[i] < data[pivot]) {
				j++;
				swap(&data[j], &data[i]); 
			
			}
		}
		swap(&data[left], &data[j]);
		pivot = j;
		quick_sort(left, pivot-1,data); 
		quick_sort(pivot+1, right, data); 
	}

}

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k = 0;

	cin >> n;
	cin >> k;

	int aaa=0;
	for (int i = 0; i < n; i++) {
		cin >> v[i],sorted[i];
	}

	sort(sorted, sorted + n);
	for (int i = 0; i < n; i++) {
		if (v[i] != sorted[i]) {
			
			quick_sort(0, n - 1, v);

			cout << v[k - 1];
			return 0;
		}
		else {
			aaa++;
			if (aaa == n) {
				cout << v[k - 1];
			}
		}
	}


}