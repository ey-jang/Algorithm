#include <iostream>
#include <string>
#include <algorithm>
#include <cstring> // memset
using namespace std;

int n, m;
string a[101][101];

string bigNumAdd(string num1, string num2) {
	long long sum = 0;
	string result;

	//1의 자리 더하기
	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		//int-> string
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

//nCr = n-1Cr + n-1Cr-1

string combi(int n, int r) {
	if (n == r || r == 0) return "1";

	string& result = a[n][r];
	if (result != "")return result;

	result = bigNumAdd(combi(n - 1, r - 1), combi(n - 1, r));
	return result;
}
int main() {
	cin >> n >> m;

	cout << combi(n, m) << "\n";
}