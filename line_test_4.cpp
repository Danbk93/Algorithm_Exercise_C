#include <iostream>
#include <algorithm>

using namespace std;
int arr[20001];
int le[20001];
int ri[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	int cal = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 0) {
			le[i] = ++cal;
		}
		else cal = 0;
	}   //입력받음과 동시에 왼쪽사람과의 거리를 체크

	cal = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == 0) {
			ri[i] = ++cal;
		}
		else cal = 0;
	}   //오른쪽 사람과의 거리를 체크

	int ans = 0;
	int dist = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) continue;   //이미 차있는자리는 패스
		if (le[i] == 0 || ri[i] == 0) {
			dist = max(le[i], ri[i]);
		}   //0이라는 것은 맨 끝에있는 사람을 의미하므로 최대거리를 체크
		else {
			dist = min(le[i], ri[i]);
		}   //근처에 가장 가까운 사람과의 거리를 체크
		ans = max(ans, dist);
	}
	cout << ans;
	return 0;
}