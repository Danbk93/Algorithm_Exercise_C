#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>

using namespace std;

int n;
vector<pair<int, int> > using_time;
vector<pair<int,int> > toilet;

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int in;
		int out;
		cin >> in >> out;
		using_time.push_back(make_pair(in, out));
	}

	sort(using_time.begin(), using_time.end());// 시작 시간, 끝 시간  정렬

	for (int i = 0; i < n; i++) {
		int in = using_time[i].first;
		int out = using_time[i].second;
		sort(toilet.begin(), toilet.end()); // 사용중인 화장실 시간 별로 정렬

		if (i == 0) {
			toilet.push_back(make_pair(in, out));

		}else{
			for (int j = 0; j < toilet.size(); j++) {
				
				if (in >= toilet[j].second) {
					toilet[j].first = in;
					toilet[j].second = out;
					break; // 사용중이 아닐 시 시간 갱신
				
				}else if (toilet[j].first <= in && in < toilet[j].second) {
					toilet.push_back(make_pair(in, out));
					break; // 모두 사용 중 일 시 화장실 추가
				}
			}
			
			
		}

	}
	cout << toilet.size();

}