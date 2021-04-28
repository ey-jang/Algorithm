#include <iostream>
using namespace std;

int a[101][101];
int c[101];
int n, v;
int cnt = 0;
void dfs(int x) {
	c[x] = 1;

	for (int i = 1; i <= n; i++) {
		if (a[x][i] == 1 && !c[i]) {
			c[i] = 1;
			cnt++;
			dfs(i);
			
		}
	}
}

int main() {

	cin >> n >> v;

	int x, y;
	for (int i = 1; i <= v; i++) {
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	dfs(1);
	cout << cnt;

}