#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long w=0;
	long long h=0;
	long long tmp = 0;

	cin >> N ;

	for (w = 1; w*w < N; w++)
		if (N%w == 0)
			tmp = w;



	if (w*w == N)
		tmp = w;

	h = N / tmp;

	cout << abs(tmp-h);
}



