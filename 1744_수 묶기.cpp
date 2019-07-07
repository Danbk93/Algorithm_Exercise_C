#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> v;
long ans = 0;

int main()
{

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a=0;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int left = 0;
	int right = n - 1;
	ans = 0;

	for (; left < right; left += 2) {
		if (v[left] < 1 && v[left + 1] < 1) {
			ans += v[left] * v[left + 1];
		}
		else {
			break;
		}
	}

	for (; right > 0; right -= 2) {
		if (v[right] > 1 && v[right - 1] > 1) {
			ans += v[right] * v[right - 1];
		}
		else {
			break;
		}
	}

	for (; right >= left; right--) {
		ans += v[right];
	}
	cout << ans;

}
