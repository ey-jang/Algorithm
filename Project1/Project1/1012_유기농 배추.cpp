#include <iostream>
#include <cstring>
using namespace std;

int t, m, n, k; //테스트 케이스, 가로, 세로, 위치 개수
int a[51][51];
int c[51][51];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, 1, -1, 0 };
void dfs(int x, int y) {
	c[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
			if (a[nextX][nextY] == 1 && !c[nextX][nextY]) {
				
				dfs(nextX, nextY);
			}
		}
	}
}
int main() {
	
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		memset(c, 0, sizeof(c));
		memset(a, 0, sizeof(a));

		cin >> m >> n >> k;

		int x, y;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			a[y][x] = 1; // x, y 좌표를 받았으므로 a[y][x]로 넣는다.
		}
		int cnt = 0;
		for (int e = 0; e < n; e++) {
			for (int r = 0; r < m; r++) {
				if (a[e][r] == 1 && !c[e][r]) {
					
					dfs(e, r);
					cnt++;
				}
			}
		}
		
		cout << cnt << "\n";
		
	
	}
	
}