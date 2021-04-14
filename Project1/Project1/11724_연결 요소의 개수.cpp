#include <iostream>
#include <vector>
using namespace std;

#define MAX 1001
vector<int>v[MAX];
int c[MAX];

int n, m;
void dfs(int x) {
	c[x] = 1;

	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (!c[next]) dfs(next);
	}
}
int main() {
	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);

	}
	int cnt = 0;
	
	for (int i = 1; i <= n; i++) {
		if (!c[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << "\n";

}