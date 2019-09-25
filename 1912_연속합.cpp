#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> c(n, 0);
	vector<int> d(n, 0);

	int ret = -1000;

	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}

	d[0] = c[0];
	for (int i = 1; i < n; i++) {
		d[i] = max(d[i - 1] + c[i], c[i]);
		ret = max(ret, d[i]);
	}
	ret = max(ret, d[0]);

	printf("%d\n", ret);

	return 0;
}