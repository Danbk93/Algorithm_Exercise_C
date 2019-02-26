#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	int num = 0;

	stack<char> front;
	stack<char> rear;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		front.push(str[i]);
	}
	cin >> num;

	while(num--){
		char command;
		cin >> command;

		if ('L' == command) {
			if (!front.empty()) {
				rear.push(front.top());
				front.pop();
			}
			
		}else if ('D' == command) {
			if (!rear.empty()) {
				front.push(rear.top());
				rear.pop();
			}

		}else if ('B' == command) {
			if (!front.empty()) {
				front.pop();
			}

		}else if ('P' == command) {
			char new_word;

			cin >> new_word;
			front.push(new_word);
		}
	}

	while (!front.empty()) {
		rear.push(front.top());
		front.pop();
	}

	while (!rear.empty()) {
		cout<<rear.top();
		rear.pop();
	}

}