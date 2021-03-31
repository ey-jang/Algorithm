#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

bool c[101][101];

int main() {
	int t;
	cin >> t;

	int n, u, v;
	
	vector<pair<int, int>>location;

	for (int i = 0; i < t; i++) {
		cin >> n;
		//집
		cin >> u >> v;
		location.push_back({ u, v });
		
		//편의점
		for (int i = 0; i < n; i++) {
			cin >> u >> v;
			location.push_back({ u, v });
		}
		// 펜타포트
		cin >> u >> v;
		location.push_back({ u, v });

		memset(c, false, sizeof(c));

		for (int i = 0; i < location.size(); i++) {
			for (int j = 0; j < location.size(); j++) {
				if (i == j) continue;
				int dist = abs(location[i].first - location[j].first) + abs(location[i].second - location[j].second);

				if (dist <= 1000) c[i][j] = 1;

			}
		}
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < n + 2; j++) {
				for (int r = 0; r < n + 2; r++) {
					if (j == r) continue;
					if (j == i || r == i) continue;

					if (!c[j][r]) {
						if (c[j][i] && c[i][r]) c[j][r] = 1;
					}
				}
			}
		}

		if (c[0][n + 1]) cout << "happy" << "\n";
		else cout << "sad" << "\n";

		location.clear();
	}
}