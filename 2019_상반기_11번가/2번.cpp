#include <map>
using namespace std;

int gcd(int x, int y) {
	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int lcm(int x, int y) {
	return (x*y) / gcd(x, y);
}

int solution(vector<vector<int>> balloons) {
	int ret = 0;
	map<pair<int, int>, int> m[4];
	map<pair<int, int>, int>::iterator iter;
	for (int i = 0; i < balloons.size(); i++) {
		bool isXminus = false; bool isYminus = false;
		int x = balloons[i][0]; int y = balloons[i][1];
		if (x < 0) {
			isXminus = true; x = -x;
		}
		if (y < 0) {
			isYminus = true; y = -y;
		}
		int field = 0;
		if (isXminus && !isYminus) field = 1;
		else if (isXminus && isYminus) field = 2;
		else if (!isXminus && isYminus) field = 3;

		int p = gcd(x, y);
		int nx = x / p; int ny = y / p;

		iter = m[field].find({ nx,ny });
		if (iter == m[field].end()) {
			m[field].insert({ {nx, ny}, 1 }); ret++;
		}
	}
	return ret;
}