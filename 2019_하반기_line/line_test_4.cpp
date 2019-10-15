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
	}   //�Է¹����� ���ÿ� ���ʻ������ �Ÿ��� üũ

	cal = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == 0) {
			ri[i] = ++cal;
		}
		else cal = 0;
	}   //������ ������� �Ÿ��� üũ

	int ans = 0;
	int dist = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) continue;   //�̹� ���ִ��ڸ��� �н�
		if (le[i] == 0 || ri[i] == 0) {
			dist = max(le[i], ri[i]);
		}   //0�̶�� ���� �� �����ִ� ����� �ǹ��ϹǷ� �ִ�Ÿ��� üũ
		else {
			dist = min(le[i], ri[i]);
		}   //��ó�� ���� ����� ������� �Ÿ��� üũ
		ans = max(ans, dist);
	}
	cout << ans;
	return 0;
}