#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

int month[13]={ 0,31,28,31,30,31,30,31,31,30,31,30,31 }; 
int x,y;
string day[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x>>y;
	
	for (int i = 1; i < x; i++) {
		y += month[i];
	}

	cout << day[y % 7];

}