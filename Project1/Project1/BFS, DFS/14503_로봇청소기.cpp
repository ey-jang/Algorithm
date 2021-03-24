#include <iostream>
using namespace std;

int n, m;
int a[51][51];
int x, y;
int cnt;
int dir;//방향

//북, 동, 남, 서
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int main() {
	cin >> n >> m;
	cin >> x >> y >> dir;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	while (1) {

		//현재위치 청소
		if (a[x][y] == 0) {
			a[x][y] = 2;
			cnt++;
		}

		int next = 0;
		for (int i = 0; i < 4; i++) {
			//왼쪽 방향으로 전환
			dir = (dir + 3) % 4;
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (a[nx][ny] == 0) {
				x = nx;
				y = ny;
				next = 1;
				break;
			}
		}
		if (next == 1) continue;

		//후진
		int newDir = (dir + 2) % 4;
		x = x + dx[newDir];
		y = y + dy[newDir];

		if (a[x][y] == 1) break;

	}
	cout << cnt;

}