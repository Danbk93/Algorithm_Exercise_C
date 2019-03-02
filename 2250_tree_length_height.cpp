#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10000 + 1;
const int INF = 987654321;


int N, nodeIdx; //N과 노드의 위치
int node[MAX]; //루트 찾기 위해

int low[MAX];

int high[MAX];

pair<int, int> tree[MAX];



//Inorder Traversal(중위 순회)

void DFS(int nodeNum, int cnt)

{

	//left SubTree

	if (tree[nodeNum].first > 0)

		DFS(tree[nodeNum].first, cnt + 1);



	//Visit

	low[cnt] = min(low[cnt], nodeIdx);

	high[cnt] = max(high[cnt], nodeIdx++);



	//right SubTree

	if (tree[nodeNum].second > 0)

		DFS(tree[nodeNum].second, cnt + 1);

}



int main(void)

{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;



	for (int i = 0; i < MAX; i++)

		low[i] = INF;



	for (int i = 0; i < N; i++)

	{

		int parent, child1, child2;

		cin >> parent >> child1 >> child2;



		node[parent]++;



		if (child1 != -1)

			node[child1]++;

		tree[parent].first = child1;

		if (child2 != -1)

			node[child2]++;

		tree[parent].second = child2;

	}



	//루트 찾기

	int root;

	for (int i = 1; i <= N; i++)

		if (node[i] == 1)

			root = i;



	//DFS

	nodeIdx = 1;

	DFS(root, 1);



	//최대 길이를 구한다

	int result = high[1] - low[1] + 1;

	int level = 1;

	for (int i = 2; i <= N; i++)

	{

		int temp = high[i] - low[i] + 1;

		if (temp > result)

		{

			result = temp;

			level = i;

		}

	}

	cout << level << " " << result << "\n";

	return 0;

}