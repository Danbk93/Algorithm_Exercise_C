#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,a,b,c,d;
vector <int> A,B,C,D;
vector<int> AB, CD;
int result;


int searchNum(int index, int op) {

	int k = index + op; //��ĭ �� �Ǵ� ��ĭ ��
	int cnt = 0;

	while (k >= 0 && k < (n*n) && CD[index] == CD[k]) { //���� ������ ī��Ʈ���ش�.

		if (rr > k)rr = k; //����

		k += op;
		cnt++; //���� ���� ����
	}

	return cnt;
}

int main() {

	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		
		cin >> a >> b >> c >> d;

		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);

	}


	int k = n*n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);

		}
	}

	//for (int i = 0; i < k; i++) {
	//	cout << AB[i] << " ";
	//}
	//cout << endl;

	//����
	//sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	//�̺�Ž��
	for (int i = 0; i < k; i++) {

		int left = 0;
		int right = k-1;


		while (left <= right) {

			int mid = (left + right) / 2;
			if (CD[mid] > AB[i])
				right = mid - 1;
			else if (CD[mid] < AB[i])
				left = mid + 1;
			else
			{
				rr = mid;
				result += searchNum(mid, 1) + searchNum(mid, -1) + 1;
				break;
			}

		}

	}
	cout << result;


	/*for (int i = 0; i < n; i++) {

		cout << A[i];

	}*/
	
}