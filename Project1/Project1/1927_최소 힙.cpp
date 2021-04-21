#include <iostream>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;

		if (k == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(k);

	}
}