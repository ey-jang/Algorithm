#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int k[1001][1001];
int c[1001];
int n, m, v;

/*
4 5 1
1 2
1 3
1 4
2 4
3 4
*/
void dfs(int x) {
	c[x] = 1;

	for (int i = 1; i <= n; i++) {
		if (k[x][i] == 1 && c[i] == 0) {
			cout << i << ' ';
			dfs(i);
			
			c[i] == 1;
		}
	}
}

void bfs(int start) {
	
	queue<int> q;
	q.push(start);
	c[start] = 1;

	while (!q.empty()) {
		start = q.front();
		q.pop();
		cout << start << " ";
		for (int i = 1; i <= n; i++) {
			if (k[start][i] && !c[i]) {
				c[i] = 1;
				q.push(i);
			}
		}
	}


}
int main() {
	
	cin >> n >> m >> v;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		k[a][b] = k[b][a] = 1;
	}
	cout << v << ' ';
	dfs(v);
	cout << "\n";
	memset(c, false, sizeof(c));
	bfs(v);
}