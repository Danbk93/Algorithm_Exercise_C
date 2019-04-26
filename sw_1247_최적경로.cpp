
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
struct po {
	int x, y;
};

int t, n;
int pm[12];
po a[12];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> n;
		int ans = 2e9;
		cin >> a[0].x >> a[0].y >> a[n + 1].x >> a[n + 1].y;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].x >> a[i].y;
			pm[i] = i;
		}
		pm[n + 1] = n + 1;
		do {
			int sum = 0;
			for (int i = 1; i <= n + 1; ++i)
				sum += abs(a[pm[i]].x - a[pm[i - 1]].x) + abs(a[pm[i]].y - a[pm[i - 1]].y);
			ans = min(ans, sum);
		} while (next_permutation(pm + 1, pm + 1 + n));
		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}


//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//
//int N;
//int map[101][101];
//int visited[101][101];
//int dist[101][101];
//
//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int me_x = 0, me_y = 0;
//int customer_n = 0;
//int cnt = 0,flag=0;
//
//void bfs(int a,int b,int distance) {
//	queue<pair<int, int>> q;
//	memset(dist, 0, sizeof(dist));
//	memset(visited, 0, sizeof(visited));
//	q.push(make_pair(a, b));
//	visited[a][b] = 1;
//	dist[a][b] = distance;
//	flag = 0;
//	while (!q.empty()) {
//		
//		int x = q.front().first;
//		int y = q.front().second;
//		
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nx = dx[i] + x;
//			int ny = dy[i] + y;
//
//			if (nx < 0 || nx >= 101 || ny < 0 || ny >= 101)continue;
//			if (visited[nx][ny] == 1)continue;
//			if (map[nx][ny] == 2 && cnt < customer_n)continue;
//			if (map[nx][ny] == 0) {
//				q.push(make_pair(nx, ny));
//				visited[nx][ny] = 1;
//				dist[nx][ny] = dist[x][y]+1;
//				
//			}else if(map[nx][ny] == 1){
//				map[nx][ny] = 0;
//				dist[nx][ny] = dist[x][y] + 1;
//				cnt++;
//				me_x =nx;
//				me_y = ny;
//				flag = 1;
//				break;
//			}
//			else if (map[nx][ny] == 2) {
//				dist[nx][ny] = dist[x][y] + 1;
//				flag = 2;
//				break;
//			}
//		}
//		if (flag == 1||flag==2) {
//			break;
//		}
//	}
//
//
//
//}
//
//
//int main() {
//
//	freopen("input.txt", "r", stdin);
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//
//	for (int n = 1; n <= N; n++) {
//		int ans = 0;
//		int h_x = 0, h_y = 0;
//		cin >> customer_n;
//
//		cin >> me_x >> me_y;
//		cin >> h_x >> h_y;
//		map[h_x][h_y] = 2;
//		for (int i = 0; i < customer_n; i++) {
//			int x = 0,y=0;
//			cin >> x >> y;
//			map[x][y] = 1;
//		}
//
//		//for (int i = 0; i < 101; i++) {
//		//	for (int j = 0; j < 101; j++) {
//
//		//		cout<<map[i][j];
//		//	}
//		//	cout << endl;
//		//}
//
//		int distance=0;
//		while (1) {
//
//			distance = dist[me_x][me_y];
//
//			bfs(me_x, me_y, distance);
//
//			if (flag == 2) {
//
//				cout << "#" << n << " " << dist[h_x][h_y]<<endl;
//				break;
//			}
//		}
//
//		
//		memset(dist, 0, sizeof(dist));
//		memset(visited, 0, sizeof(visited));
//		memset(map, 0, sizeof(map));
//		cnt = 0;
//		flag = 0;
//	}
//
//}