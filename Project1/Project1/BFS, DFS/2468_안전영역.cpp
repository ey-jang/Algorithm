#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int a[101][101];
int c[101][101];
int v[101][101]; // 방문

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
void bfs(int x, int y) {
	v[x][y] = 1;

	queue<pair<int, int>>q;
	q.push({ x, y });
	while (!q.empty()) {
		int first = q.front().first;
		int second = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = first + dx[i];
			int ny = second + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (c[nx][ny] == 0 && !v[nx][ny]) {
					q.push({ nx, ny });
					v[nx][ny] = 1;
				}
			}
		}


	}
}
int main() {
	cin >> n;
	int k = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			k = max(k, a[i][j]);

		}
	}
	int cntM = -1;
	int cnt = 0;


	while (k >= 0) { // 아무 지역도 물에 잠기지 않을 수 있기 때문에 0 이상인 경우
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] <= k) c[i][j] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (c[i][j] == 0 && !v[i][j]) {
					bfs(i, j);
					cnt++;
					cntM = max(cntM, cnt);

				}
			}
		}
		cnt = 0;

		k--;
		memset(c, false, sizeof(c));
		memset(v, false, sizeof(v));
	}

	cout << cntM << "\n";




}