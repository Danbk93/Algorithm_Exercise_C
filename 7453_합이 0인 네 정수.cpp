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

	int k = index + op; //한칸 뒤 또는 한칸 앞
	int cnt = 0;

	while (k >= 0 && k < (n*n) && brr[index] == brr[k]) { //같을 때까지 카운트해준다.

		if (rr > k)rr = k; //갱신

		k += op;
		cnt++; //같은 숫자 개수
	}

	return cnt;
}
int binarysearch(ll num) {

	int L = 0;
	int R = rr;

	int cnt = 0;
	while (L <= R) {

		int mid = (L + R) / 2;

		if (num == brr[mid]) { //같다면찾고 종료,

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


	//둘로 합치기
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[k] = a[i] + b[j];
			brr[k++] = c[i] + d[j];
		}
	}

	//정렬
	sort(arr, arr + k);
	sort(brr, brr + k);

	//이분탐색go
	ll ans = 0, temp = 0;
	rr = k;

	for (int i = 0; i < k; i++) {
		if (i > 0 && arr[i - 1] == arr[i]) { //겹치는 거라면 똑같은거 더해주기
			ans += temp;
		}
		else {
			temp = binarysearch(-arr[i]);
			ans += temp;
		}
	}


	printf("%lld\n", ans);

}