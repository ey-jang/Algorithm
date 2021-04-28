#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	priority_queue<int> q;


	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		if (x != 0) {
			q.push(x);
		}
		else {
			if (!q.empty()) {
				cout << q.top() << "\n";
				q.pop();
			}
			else {
				cout << 0 << "\n";
			}
		}
	}
}