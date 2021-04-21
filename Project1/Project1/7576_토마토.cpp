#include <iostream>
#include <queue>
using namespace std;

int a[1001][1001];

int m, n;

int dx[4] = { 0, 0 ,-1, 1 };
int dy[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;

void bfs() {

	while (!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nX = x + dx[i];
			int nY = y + dy[i];

			if (nX >= 0 && nX < n && nY >= 0 && nY < m) {
				if (a[nX][nY] == 0) {
					a[nX][nY] = a[x][y] + 1;
					q.push({ nX, nY });
					
					
					
				}
			}
		}

	}
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n; // 가로, 세로 

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
	
			cin >> a[i][j];
			if (a[i][j] == 1) q.push({ i, j });

		}
	}
	
	bfs();
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				cout << "-1" << "\n";
				return 0;
			}
			if (max < a[i][j]) max = a[i][j];
		}
		
	}
	cout << max - 1 << "\n";
	return 0;
}