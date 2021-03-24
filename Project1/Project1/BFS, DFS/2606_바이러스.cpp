#include <iostream>
#include <queue>
using namespace std;


int n,m;
int a[101][101];
bool c[101];
int x, y;
int cnt = 0;
void dfs(int x) {
	c[x] = 1;
	
	for (int i = 1; i <= n; i++) {
		if (a[x][i] == 1 && !c[i]) {
			
			dfs(i);
			cnt++;
			
		}
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	dfs(1);
	cout << cnt;
}