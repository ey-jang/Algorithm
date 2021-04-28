#include <iostream>
using namespace std;

int n, m;
int a[9];
int c[9];

void dfs(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';

		}
		cout << "\n";
		return;
	}
	for (int i = num; i <= n; i++) {
		if (!c[i]) {
			c[i] = 1;
			a[cnt] = i; //a[0]=1 a[1] = 2 
			dfs(i + 1, cnt + 1); // dfs(2, 1) dfs(3, 2)
			c[i] = 0;
		}
	}
}
int main() {
	
	cin >> n >> m;
	dfs(1, 0);
}