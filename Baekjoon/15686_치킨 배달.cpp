#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int map[51][51];
vector<pair<int, int>> chic;
vector<pair<int, int>> home;
int dist[102];
int ans=1000000;
int hom_cnt = 0;

int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				chic.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 1) {
				home.push_back(make_pair(i, j));
				hom_cnt++;
			}
		}
	}
	//치킨집 조합
	vector<int> ind;
	for (int i = 0; i < M; i++) {
		ind.push_back(1);
	}
	for (int i = 0; i < chic.size() - M; i++) {
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end());
	
	for (int u = 0; u < hom_cnt; u++) {
		dist[u] = 200;
	}
	
	do {
		// 치킨집 하나의 조합
		for (int i = 0; i < ind.size(); i++) {
			// 하나의 치킨집
			if (ind[i] == 1) {
			
				//cout << chic[i].first << chic[i].second;
				for (int j = 0; j < hom_cnt; j++) {

					if (dist[j] > (abs(home[j].first - chic[i].first) + abs(home[j].second - chic[i].second))) {
						dist[j] = (abs(home[j].first - chic[i].first) + abs(home[j].second - chic[i].second));
					}
					
				}
				

			}
			
		}
		int dist_temp = 0;
		for (int k = 0; k < hom_cnt; k++) {
			//cout << dist[k]<<" ";
			dist_temp += dist[k];
		}
		if (dist_temp < ans) {
			ans = dist_temp;
		}

		for (int u = 0; u < hom_cnt; u++) {
			dist[u] = 200;
		}

	} while (next_permutation(ind.begin(), ind.end()));

	cout << ans;

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout<< map[i][j];

	//	}
	//	cout << endl;
	//}
}