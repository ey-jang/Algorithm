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
	vector<int> v(n); // 원본 벡터

	//입력
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> cv(v); //원본 벡터를 복사해서 중복된 수 제거, 정렬할 벡터
	sort(cv.begin(), cv.end()); 

	//중복 제거
	//unique 는 연속으로 중복되는 원소를 vector 제일 뒤로 보낸다
	cv.erase(unique(cv.begin(), cv.end()), cv.end());

	for (int i = 0; i < n; i++) {

		//lower_bound(first iterator, last, iterator, value) value:찾고자 하는 값
		//i 번째 요소 값의 위치 it
		auto it = lower_bound(cv.begin(), cv.end(), v[i]);

		//it에서 cv 벡터 시작 주소값 빼준 값
		cout << it - cv.begin() << ' ';
	}



}