#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

map<string, int> m;

struct abc {
	int x, y;
	double w, d, l;
} a[6];

int s[4];
double ans[4];
pair<int, int> t[4];

void dfs(int n, double p) {
	if (n == 6) {
		for (int i = 0; i < 4; i++) {
			t[i].first = s[i];
			t[i].second = i;
		}
		sort(t, t + 4);
		int A = t[0].first, B = t[1].first, C = t[2].first, D = t[3].first;
		int a = t[0].second, b = t[1].second, c = t[2].second, d = t[3].second;
		if (B != C) {
			ans[c] += p; ans[d] += p;
		}
		else if (A == B && C == D) {
			ans[a] += p / 2.0; ans[b] += p / 2.0;
			ans[c] += p / 2.0; ans[d] += p / 2.0;
		}
		else if (A == B) {
			ans[a] += p / 3.0; ans[b] += p / 3.0;
			ans[c] += p / 3.0; ans[d] += p;
		}
		else if (C == D) {
			ans[b] += p * 2.0 / 3.0; ans[c] += p * 2.0 / 3.0;
			ans[d] += p * 2.0 / 3.0;
		}
		else {
			ans[b] += p / 2.0; ans[c] += p / 2.0;
			ans[d] += p;
		}
		return;
	}

	int x = a[n].x;
	int y = a[n].y;

	s[x] += 3;
	dfs(n + 1, p*a[n].w);
	s[x] -= 3;

	s[x] += 1; s[y] += 1;
	dfs(n + 1, p*a[n].d);
	s[x] -= 1; s[y] -= 1;

	s[y] += 3;
	dfs(n + 1, p*a[n].l);
	s[y] -= 3;
}

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		m[str] = i;
	}

	for (int i = 0; i < 6; i++) {
		string s1, s2;
		cin >> s1 >> s2 >> a[i].w >> a[i].d >> a[i].l;
		a[i].x = m[s1];
		a[i].y = m[s2];
	}

	dfs(0, 1.0);

	for (int i = 0; i < 4; i++) {
		printf("%.18lf\n", ans[i]);
	}

	return 0;
}
