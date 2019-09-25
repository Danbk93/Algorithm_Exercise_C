#include <iostream>
using namespace std;

const int MAX = 20;


int N, S;
int arr[MAX];
int result = 0;

void numOfSubset(int idx, int sum) {

	sum += arr[idx]; //�켱 �ش� ���ڸ� ���Ѵ�

	//�������: ���� �ʰ���
	if (idx >= N) return;
	//���� ������
	if (sum == S)result++;
	numOfSubset(idx + 1, sum - arr[idx]);
	//�ش� ���ڸ� ������ ���
	numOfSubset(idx + 1, sum);

}

int main(void) {

	cin >> N >> S;

	for (int i = 0; i < N; i++) cin >> arr[i];

	numOfSubset(0, 0);

	cout << result << endl;

	return 0;

}