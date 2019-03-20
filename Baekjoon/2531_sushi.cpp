#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, d, k, c = 0;
	int temp = 0;
	int ans = 0;
	int sushi[30001] = { 0 };
	int eaten[30001] = { 0 };

	cin >> N >> d>> k>>c;
	
	for (int i = 1; i <= N; i++) {
		cin >> sushi[i];
	
	}
	eaten[c]++;
	temp++;
	for (int i = 1; i <= k; i++) {
	
		eaten[sushi[i]]++;
		if (eaten[sushi[i]] == 1) {
			
			temp++;
		}
	}

	for (int i = 1; i <= N - 1; i++)            
	{                              
		if (i + k <= N)
		{
			eaten[sushi[i]]--;
			if (eaten[sushi[i]] == 0) {
				temp--;
			}

			eaten[sushi[i + k]]++;

			if (eaten[sushi[i + k]] == 1) {
				temp++;
			}
				
		}else{
			int j = i + k - N;

			eaten[sushi[i]]--;

			if (eaten[sushi[i]] == 0) {
				temp--;
			}
				
			eaten[sushi[j]]++;

			if (eaten[sushi[j]] == 1) {
				temp++;
			}
				
		}

		if (ans < temp)

			ans = temp;

	}


	cout << ans;
}