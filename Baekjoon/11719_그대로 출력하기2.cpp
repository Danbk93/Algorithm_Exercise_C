#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

string str;

int main() {

	freopen("input.txt", "r", stdin);

	while (getline(cin, str)) {
		cout << str << endl;
	}
}
