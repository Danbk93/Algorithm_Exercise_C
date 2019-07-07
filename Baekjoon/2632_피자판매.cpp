#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int a, b, a_total, b_total;
int a_slices[1001];
int b_slices[1001];
vector<int> a_whole, b_whole;

int main()
{

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int num = 0;
		cin >> num;
		a_slices[i] = num;
		a_total += num;
	}
	for (int i = 0; i < b; i++) {
		int num = 0;
		cin >> num;
		b_slices[i] = num;
		b_total += num;
	}

	for (int i = 0; i < a; i++) {
		int temp = 0;
		for (int j = i; j < a + i - 1; j++) {
			temp += a_slices[j%a];
			a_whole.push_back(temp);
		}
	}
	a_whole.push_back(a_total);

	for (int i = 0; i < b; i++) {
		int temp = 0;
		for (int j = i; j < b + i - 1; j++) {
			temp += b_slices[j%b];
			b_whole.push_back(temp);
		}
	}
	b_whole.push_back(b_total);

	sort(a_whole.begin(), a_whole.end());
	sort(b_whole.begin(), b_whole.end());

	int ways = upper_bound(a_whole.begin(), a_whole.end(), n) - lower_bound(a_whole.begin(), a_whole.end(), n);
	ways += upper_bound(b_whole.begin(), b_whole.end(), n) - lower_bound(b_whole.begin(), b_whole.end(), n);

	for (int i = 0; i < a_whole.size(); i++) {
		if (a_whole[i] >= n)
			break;
		int b_left = n - a_whole[i];
		ways += upper_bound(b_whole.begin(), b_whole.end(), b_left) - lower_bound(b_whole.begin(), b_whole.end(), b_left);
	}

	cout << ways;
}
