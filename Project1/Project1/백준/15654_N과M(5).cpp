#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[9];
int ans[9];
int c[9];

void dfs(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';

		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!c[i]) {
			c[i] = 1;
			ans[level] = a[i]; 
			dfs(level + 1); 
			c[i] = 0;
		}
	}
}
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		
	}
	sort(a, a + n);
	dfs(0);
}