#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;

string str;
int mini = 1000001;
int answer = 1000001;
int temp = 0;

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;
	//���� ū ���ڿ� ���� ���� �� ����
	for (int i = str.length(); i > 0; i--) {
		//�ϳ��� ���� ��Ʈ��
		cout << i << "��ŭ�� ���꽺Ʈ��" << endl;

		string checkstr = str.substr(0, i);
		
		if (i==str.length()) {
			temp = checkstr.length();
		}

		//�ߺ�üũ
		int nex= i;
		int cnt = 0;
		int a = 0;
		while (nex < str.length() - i+1) {
			if (checkstr != str.substr(nex, i)) {
				
				if (cnt > 0) {
					int a=0;
					if (cnt < 9) {
						a = 1;
					}
					else if (cnt < 99) {
						a = 2;
					}
					else if (cnt < 999) {
						a = 3;
					}
					else if (cnt < 9999) {
						a = 4;
					}
					temp = temp - (checkstr.length()*cnt)+a;
					cout <<"cnt" <<cnt;
				}
				
				checkstr = str.substr(nex, i);
				cnt = 0;
				
			}else if (checkstr == str.substr(nex, i)) {
				cout <<"sub " <<str.substr(nex, i) << endl;
				cnt++;
				
			}
			nex+=i;
		}
		if (cnt > 0) {
			int a = 0;
			if (cnt < 9) {
				a = 1;
			}
			else if (cnt < 99) {
				a = 2;
			}
			else if (cnt < 999) {
				a = 3;
			}
			else if (cnt < 9999) {
				a = 4;
			}
			temp = temp - (checkstr.length()*cnt) + a;
			cout << "cnt" << cnt;
		}
		
		cout << "temp" << temp << endl;
		if (mini >= temp) {
			mini = temp;
		}
		temp = str.length();

		
		cout << "��ȯ��" << mini << endl;
	}

	if (answer >= mini) {
		answer = mini;
	}
	cout <<answer<< endl;

}