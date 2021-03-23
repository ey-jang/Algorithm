#include <iostream>
#include <queue>

using namespace std;

int dir_x[] = { 0, 0, -1, 1, 0, 0 };
int dir_y[] = { -1, 1, 0, 0, 0, 0 };
int dir_z[] = { 0, 0, 0, 0, -1, 1 };
int a[101][101][101];

int main() {

	int M, N, H;
	cin >> M >> N >> H;

	queue<pair<int, pair<int, int>>> q;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> a[k][i][j];
				if (a[k][i][j] == 1) {
					q.push(make_pair(k, make_pair(i, j)));
				}
			}
		}
	}

	while (!q.empty()) {

		int x = q.front().second.second;
		int y = q.front().second.first;
		int z = q.front().first;

		q.pop();

		for (int i = 0; i < 6; i++) {
			int next_x = x + dir_x[i];
			int next_y = y + dir_y[i];
			int next_z = z + dir_z[i];

			if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && next_z >= 0 && next_z < H) {
				if (a[next_z][next_y][next_x] == 0) {
					q.push(make_pair(next_z, make_pair(next_y, next_x)));
					a[next_z][next_y][next_x] = a[z][y][x] + 1;
				}
			}
		}
	}

	int cnt = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[k][i][j] == 0) {
					cout << -1 << endl;
					return 0;
				}
				cnt = max(cnt, a[k][i][j]);
			}
		}
	}
	cout << cnt - 1 << endl;

	return 0;
}
