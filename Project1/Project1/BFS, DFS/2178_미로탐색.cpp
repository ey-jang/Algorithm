#include <iostream>
#include <queue>
using namespace std;

int a[101][101];
int c[101][101];
int n, m;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void bfs(int x, int y) {
	queue<pair<int,int>>q;
	q.push(make_pair(x, y));
	c[x][y]++;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (c[nx][ny] == 0 && a[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					c[nx][ny] = c[x][y] + 1;
				}


			}
		}
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &a[i][j]);

		}
	}
	bfs(0, 0);
	cout << c[n - 1][m - 1];
	return 0;
}