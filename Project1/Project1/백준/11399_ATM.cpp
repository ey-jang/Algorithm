#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;
	int k;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		v.push_back(k); 
	}
	sort(v.begin(), v.end());
	int sum2 = 0;

	for (int i = 0; i < v.size(); i++) {
		int sum1 = 0;
		for (int j = 0; j <= i; j++) {
			
			sum1 += v[j];
		}
		sum2 += sum1;
	}
	cout << sum2 << "\n";
}