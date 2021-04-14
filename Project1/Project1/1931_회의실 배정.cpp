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

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		v.push_back({ y, x });
	}

	sort(v.begin(), v.end());
	
	int result = v[0].first;
	int cnt = 1;
	for (int i = 1; i < n; i++) { // 이중 for문은 시간초과..
		if (result <= v[i].second) {
			cnt++;
			result = v[i].first;
		}
		
		
	}
	cout << cnt << "\n";
}