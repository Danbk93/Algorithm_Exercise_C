#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	getline(cin, s);
	istringstream iss(s);
	string token;

	int cnt = 0; int target = 0;
	while (getline(iss, token, ' ')) {
		v.push_back(stoi(token));
	}   //string���� �Է� �޾Ƽ� parsing �� �� int������ ��ȯ�ؼ� ���Ϳ� ����
	cin >> target;   //���� ���� Ƚ��
	sort(v.begin(), v.end());   //���� ����
	for (int i = 1; i < target; i++) {
		next_permutation(v.begin(), v.end());
	}   //for���� �̿��� ���ϴ� ����ŭ ������ ����. ��ü ����� ���� 10!�̱� ������ ������ ����
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}   //ã�� ������ ���

	return 0;
}