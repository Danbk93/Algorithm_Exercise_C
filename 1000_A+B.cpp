#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int a, b;


int main()
{

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a>>b;
	cout << a + b;
	
}
