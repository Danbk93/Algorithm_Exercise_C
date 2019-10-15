#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


typedef long long int ll;

ll a[4001];
ll b[4001];
ll c[4001];
ll d[4001];
ll arr[16000001];
ll brr[16000001];

int n, rr;
int searchNum(int index, int op) {

	int k = index + op; //��ĭ �� �Ǵ� ��ĭ ��
	int cnt = 0;

	while (k >= 0 && k < (n*n) && brr[index] == brr[k]) { //���� ������ ī��Ʈ���ش�.

		if (rr > k)rr = k; //����

		k += op;
		cnt++; //���� ���� ����
	}

	return cnt;
}
int binarysearch(ll num) {

	int L = 0;
	int R = rr;

	int cnt = 0;
	while (L <= R) {

		int mid = (L + R) / 2;

		if (num == brr[mid]) { //���ٸ�ã�� ����,

			rr = mid;
			return searchNum(mid, 1) + searchNum(mid, -1) + 1;

		}
		else if (num < brr[mid])R = mid - 1;
		else L = mid + 1;
	}

	return 0;

}
int main() {


	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %lld %lld", &a[i], &b[i], &c[i], &d[i]);
	}


	//�ѷ� ��ġ��
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[k] = a[i] + b[j];
			brr[k++] = c[i] + d[j];
		}
	}

	//����
	sort(arr, arr + k);
	sort(brr, brr + k);

	//�̺�Ž��go
	ll ans = 0, temp = 0;
	rr = k;

	for (int i = 0; i < k; i++) {
		if (i > 0 && arr[i - 1] == arr[i]) { //��ġ�� �Ŷ�� �Ȱ����� �����ֱ�
			ans += temp;
		}
		else {
			temp = binarysearch(-arr[i]);
			ans += temp;
		}
	}


	printf("%lld\n", ans);

}