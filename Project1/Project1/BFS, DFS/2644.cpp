#include <iostream>
#include <queue>
using namespace std;


int n, m;
int a, b;
int k[101][101];
int c[101];
int cnt = 0;
void bfs(int x) {
	
	queue<int>q;
	q.push(x);
	while (!q.empty()) {
		int start = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (k[start][i] == 1 && !c[i]) {
				
				c[i] = c[start] + 1;
				q.push(i);
			}
		}
	}
}
int main() {
	
	cin >> n;
	cin >> a >> b;
	cin >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		k[x][y] = k[y][x] = 1;
	}
	
	bfs(a);
	if (c[b] == 0) cout << -1;
	else cout << c[b];
}