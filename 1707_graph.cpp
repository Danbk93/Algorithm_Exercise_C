#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


using namespace std;
int line[200001] = { 0 };
int dot[20001] = { 0 };
bool graph = true;

void dfs(int i) {

	
	int nextdot = line[i];

	if (nextdot !=0 ) {

		if (dot[i] == 0) {
			dot[i] = 1;
		}

		if (dot[nextdot] == 0) {

			if (dot[i] == 2) {
				dot[nextdot] = 1;
			}
			else if (dot[i] == 1) {
				dot[nextdot] = 2;
			}

			dfs(nextdot);
		}
		else {
			if (dot[nextdot] == dot[i]) {
				graph = false;
			}
			else {
				graph = true;
			}
		}
	
	}
	
	
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num = 0;
	int V = 0;
	int E = 0;
	

	cin >> num;

	while (num--) {
		cin >> V;
		cin >> E;
		for (int i = 1; i <= E; i++) {
			int x, y=0;
			cin >> x;
			cin >> y;
			
			if (line[x] == 0) {

				line[x] = y;
			}
			else {
			
				line[y] = x;
			}

		}

		/*for (int i = 1; i <= V; i++) {
			cout <<line[i];
		}
		cout << endl;*/
		
		for (int i = 1; i <= V; i++) {
			if (dot[i] == 0) {
			
				dfs(i);

				/*if (graph == false) {
					break;
				}*/
			}
			cout << dot[i];
		}



		if (graph) {
			cout << "YES"<<endl;
		}
		else {

			cout << "NO" << endl;
		}

		for (int i = 1; i <= E; i++) {
			line[i] = 0;
		}
		for (int i = 1; i <= V; i++) {
			dot[i] = 0;
		}
	}

}