#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n); // ���� ����

	//�Է�
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> cv(v); //���� ���͸� �����ؼ� �ߺ��� �� ����, ������ ����
	sort(cv.begin(), cv.end()); 

	//�ߺ� ����
	//unique �� �������� �ߺ��Ǵ� ���Ҹ� vector ���� �ڷ� ������
	cv.erase(unique(cv.begin(), cv.end()), cv.end());

	for (int i = 0; i < n; i++) {

		//lower_bound(first iterator, last, iterator, value) value:ã���� �ϴ� ��
		//i ��° ��� ���� ��ġ it
		auto it = lower_bound(cv.begin(), cv.end(), v[i]);

		//it���� cv ���� ���� �ּҰ� ���� ��
		cout << it - cv.begin() << ' ';
	}



}