#include <iostream>
using namespace std;

int main() {
	int t, n, z[41] = { 1 }; // 0�� Ƚ�� z(0)=1, z(1)=1
	int o[41] = { 0, 1 }; // 1�� Ƚ�� o(0)=0, o(1)=1

	
	for (int n = 2; n <= 40; n++) { // n�� 2�̻��϶�
		z[n] = z[n - 1] + z[n - 2];
		o[n] = o[n - 1] + o[n - 2];
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << z[n] << ' ' << o[n] << "\n";
	}
}
//bottom-up ��� : �̹� �˰� �ִ� ���� ���� ���� ū �� ���ϱ�