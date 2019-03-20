#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int class_num = 0;
	int student_num[1000000] = { 0 };
	int main_sup = 0;
	int sub_sup = 0;

	cin >> class_num;

	for (int i = 0; i < class_num; i++) {
		cin >> student_num[i];
	}

	cin >> main_sup;
	cin >> sub_sup;

	long long count = 0;

	for (int i = 0; i < class_num; i++) {
		student_num[i] -= main_sup;
		count++;

		if(student_num[i]<0){
			student_num[i] = 0;
		}

		if (student_num[i] % sub_sup == 0) {
			count += (student_num[i] / sub_sup);
		}
		else {
			count += (student_num[i] / sub_sup) + 1;
		}
	}

	cout << count;

}