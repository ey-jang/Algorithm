#include <iostream>
#include <set>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;

	while (T--) {
		multiset<int>arr;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			char c;
			cin >> c;
			int n;
			cin >> n;
			if (c == 'I') arr.insert(n);
			else {
				if (arr.empty()) continue;
				if (n == 1) {
					auto iter = arr.end();
					iter--;
					arr.erase(iter);
				}
				else {
					auto iter = arr.begin();
					arr.erase(iter);
				}
			}
		}
		if (arr.empty())cout << "EMPTY" << "\n";
		else {
			auto end = arr.end();
			end--;
			cout << *end << " " << *arr.begin() << "\n";
		}
	}
}