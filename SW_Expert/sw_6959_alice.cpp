#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int T;
string num;


int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int chk = 0;
	cin >> T;

	for(int i=0;i<T;i++) {
		cin >> num;

		while (num.size() > 1) {
			int sum =0;
		
			sum = num[num.size()-2] + num[num.size()-1] - '0' - '0';
			
			num.replace(num.size() - 2, 2, to_string(sum));
			
			chk++;
		}

		if (chk % 2 == 1) {
			cout << "#" << i+1 << " " << "A"<<endl;
		}
		else {
			cout << "#" << i+1 << " " << "B"<< endl;
		}
		chk = 0;
	}

}



