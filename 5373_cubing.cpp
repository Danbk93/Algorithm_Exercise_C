#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T; 

void left_rotate(char& a, char& b, char& c, char& d) {
	char temp = a;
	a = b;
	b = c;
	c = d;
	d = temp;
}
void right_rotate(char& a, char& b, char& c, char& d) {
	char temp = d;
	d = c;
	c = b;
	b = a;
	a = temp;
}




int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {

		int n = 0;
		cin >> n;
		char command[1001] = { 0 };
		char way[1001] = { 0 };
		char top[10] = {'0', 'w','w','w','w','w','w','w','w','w' };
		char bot[10] = { '0', 'y','y','y','y','y','y','y','y','y' };
		char front[10] = { '0', 'r','r','r','r','r','r','r','r','r' };
		char back[10] = { '0', 'o','o','o','o','o','o','o','o','o' };
		char left[10] = { '0', 'g','g','g','g','g','g','g','g','g' };
		char right[10] = { '0', 'b','b','b','b','b','b','b','b','b' };

		for (int i = 0; i < n; i++) {
			cin >> command[i];
			cin >> way[i];
		}

		for (int i = 0; i < n; i++) {
			if (command[i] == 'U') {
				if (way[i] == '-') {
					right_rotate(front[1], right[1], back[1], left[1]);
					right_rotate(front[2], right[2], back[2], left[2]);
					right_rotate(front[3], right[3], back[3], left[3]);

					left_rotate(top[1], top[3], top[9], top[7]);
					left_rotate(top[2], top[6], top[8], top[4]);

				}
				else if (way[i] == '+') {
					left_rotate(front[1], right[1], back[1], left[1]);
					left_rotate(front[2], right[2], back[2], left[2]);
					left_rotate(front[3], right[3], back[3], left[3]);

					right_rotate(top[1], top[3], top[9], top[7]);
					right_rotate(top[2], top[6], top[8], top[4]);
				}
			}
			else if (command[i] == 'D') {
				if (way[i] == '-') {
					left_rotate(front[7], right[7], back[7], left[7]);
					left_rotate(front[8], right[8], back[8], left[8]);
					left_rotate(front[9], right[9], back[9], left[9]);

					left_rotate(bot[1], bot[3], bot[9], bot[7]);
					left_rotate(bot[2], bot[6], bot[8], bot[4]);
				}
				else if (way[i] == '+') {
					right_rotate(front[7], right[7], back[7], left[7]);
					right_rotate(front[8], right[8], back[8], left[8]);
					right_rotate(front[9], right[9], back[9], left[9]);

					right_rotate(bot[1], bot[3], bot[9], bot[7]);
					right_rotate(bot[2], bot[6], bot[8], bot[4]);
				}
			}
			else if (command[i] == 'F') {
				if (way[i] == '-') {
					right_rotate(top[7], left[9], bot[3], right[1]);
					right_rotate(top[8], left[6], bot[2], right[4]);
					right_rotate(top[9], left[3], bot[1], right[7]);

					left_rotate(front[1], front[3], front[9], front[7]);
					left_rotate(front[2], front[6], front[8], front[4]);
				}
				else if (way[i] == '+') {
					left_rotate(top[7], left[9], bot[3], right[1]);
					left_rotate(top[8], left[6], bot[2], right[4]);
					left_rotate(top[9], left[3], bot[1], right[7]);

					right_rotate(front[1], front[3], front[9], front[7]);
					right_rotate(front[2], front[6], front[8], front[4]);
				}
			}
			else if (command[i] == 'B') {
				if (way[i] == '-') {
					left_rotate(top[1], left[7], bot[9], right[3]);
					left_rotate(top[2], left[4], bot[8], right[6]);
					left_rotate(top[3], left[1], bot[7], right[9]);

					left_rotate(back[1], back[3], back[9], back[7]);
					left_rotate(back[2], back[6], back[8], back[4]);
				}
				else if (way[i] == '+') {
					right_rotate(top[1], left[7], bot[9], right[3]);
					right_rotate(top[2], left[4], bot[8], right[6]);
					right_rotate(top[3], left[1], bot[7], right[9]);

					right_rotate(back[1], back[3], back[9], back[7]);
					right_rotate(back[2], back[6], back[8], back[4]);
				}
			}
			else if (command[i] == 'L') {
				if (way[i] == '-') {
					left_rotate(top[1], front[1], bot[1], back[9]);
					left_rotate(top[4], front[4], bot[4], back[6]);
					left_rotate(top[7], front[7], bot[7], back[3]);

					left_rotate(left[1], left[3], left[9], left[7]);
					left_rotate(left[2], left[6], left[8], left[4]);
				}
				else if (way[i] == '+') {
					right_rotate(top[1], front[1], bot[1], back[9]);
					right_rotate(top[4], front[4], bot[4], back[6]);
					right_rotate(top[7], front[7], bot[7], back[3]);

					right_rotate(left[1], left[3], left[9], left[7]);
					right_rotate(left[2], left[6], left[8], left[4]);
				}
			}
			else if (command[i] == 'R') {
				if (way[i] == '-') {
					right_rotate(top[3], front[3], bot[3], back[7]);
					right_rotate(top[6], front[6], bot[6], back[4]);
					right_rotate(top[9], front[9], bot[9], back[1]);

					left_rotate(right[1], right[3], right[9], right[7]);
					left_rotate(right[2], right[6], right[8], right[4]);
				}
				else if (way[i] == '+') {
				
					left_rotate(top[3], front[3], bot[3], back[7]);
					left_rotate(top[6], front[6], bot[6], back[4]);
					left_rotate(top[9], front[9], bot[9], back[1]);

					right_rotate(right[1], right[3], right[9], right[7]);
					right_rotate(right[2], right[6], right[8], right[4]);
				}
			}
			
			
		}

		int cnt = 0;
		for (int i = 1;i<10; i++) {
			cout << top[i];
			cnt++;
			if (cnt == 3 || cnt == 6 || cnt == 9) {
				cout << endl;
			}
		}

	}
	


}



