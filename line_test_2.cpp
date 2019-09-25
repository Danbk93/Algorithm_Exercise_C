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
	}   //string으로 입력 받아서 parsing 한 후 int형으로 변환해서 벡터에 대입
	cin >> target;   //순열 돌릴 횟수
	sort(v.begin(), v.end());   //벡터 정렬
	for (int i = 1; i < target; i++) {
		next_permutation(v.begin(), v.end());
	}   //for문을 이용해 원하는 수만큼 순열을 돌림. 전체 경우의 수가 10!이기 때문에 돌려도 무방
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}   //찾은 순열을 출력

	return 0;
}