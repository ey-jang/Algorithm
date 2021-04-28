#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
	int n;
	cin >> n;
	
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	cout << dp[n];

		
}
/*
* dp 문제 구분
  - 특정 수량의 최대 최소를 구하는 문제
  - 특정 조건을 만족하는 배열 갯수 세는 문제

*/