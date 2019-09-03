#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int T, n, m;
long long cnt;

vector<int> A;
vector<int> B;
vector<int> sum1,sum2;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		B.push_back(num);
	}

	

	for (int i = 0; i < n; i++)
	{
		int sum = A[i];
		sum1.push_back(sum);
		for (int j = i + 1; j < n; j++)
		{
			sum += A[j];
			sum1.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++)
	{
		int sum = B[i];
		sum2.push_back(sum);
		for (int j = i + 1; j < m; j++)
		{
			sum += B[j];
			sum2.push_back(sum);
		}
	}

	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());

	for (int i = 0; i < sum1.size(); i++)
	{
		int low = lower_bound(sum2.begin(), sum2.end(),T-sum1[i])- sum2.begin();
		int up = upper_bound(sum2.begin(), sum2.end(), T - sum1[i]) - sum2.begin();
		cnt += (up - low);
	}

	cout << cnt;

	
}