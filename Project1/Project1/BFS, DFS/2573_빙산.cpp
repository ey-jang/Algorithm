#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int a[301][301];
int c[301][301];

int n, m;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, 1, -1, 0 };
int result = 0;

void dfs(int yy, int xx, int cnt) {
	c[yy][xx] = cnt; 

	for (int i = 0; i < 4; i++) {
		int y = yy + dy[i];
		int x = xx + dx[i];
		if (y >= 0 && y < n && x >= 0 && x < m)
			if (a[y][x] && c[y][x] == 0)
				dfs(y, x, cnt);

	}
}
void melt_ice() {
	int melt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) continue;
			melt = 0;
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];
				if (a[y][x] == 0 && y >= 0 && y < n && x >= 0 && x < m)
					melt++;
			}

			if (a[i][j] < melt) continue;
			else c[i][j] = a[i][j] - melt;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = c[i][j];
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	while (1) {
		//1. 빙산이 몇조각인지 확인하기
		memset(c, 0, sizeof(c));
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] && c[i][j] == 0) {
					cnt++;
					dfs(i, j, cnt);
				}
		//2. 두조각 이상인지 확인하기 
		if (cnt >= 2) {
			cout << result << endl;
			return 0;
		}
		//3. 얼음 녹이기 
		memset(c, 0, sizeof(c));
		melt_ice();
		//4. 얼음이 다녹은지 확인
		bool jud = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j]) jud = true;

		if (jud == false) {
			cout << 0 << endl;
			return 0;
		}

		//카운트 증가
		result++;
	}
}