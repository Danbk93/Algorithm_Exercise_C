#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int T,N;
vector <double> x;
vector <double> m;

int main(void) {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed;
	cout.precision(10);
	int C = 1;
	cin >> T;

	while (T--) {
		double ans = 0.0;

		x.clear();
		m.clear();
		cin >> N;
	
		
		for (int i = 0; i < N; i++) {
			double c = 0;
			cin >> c;
			x.push_back(c);
		
		}
		for (int i = 0; i < N; i++) {
			double c = 0;
			cin >> c;
			m.push_back(c);

		}


		cout << "#" << C << " ";
		C++;

		for (int i = 0; i < N - 1; i++) {
			double l= x[i];
			double r= x[i+1];

			for (int j = 0; j < 50; j++) {
				double mid = (l + r) / 2;
				double front=0;
				double back = 0;
				for (int k = 0; k <= i; k++) {
					front += m[k]/ ((mid - x[k])*(mid - x[k]));
				}
				for (int k = i+1; k < N; k++) {
					back += m[k]/ ((mid - x[k])*(mid - x[k]));
				}
				if (front > back) {
					l = mid;
				}
				else {
					r = mid;
					ans = mid;
				}
			}
			cout << ans << " ";
		}
		cout << endl;
	}

}

