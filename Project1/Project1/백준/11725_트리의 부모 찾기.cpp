#include <iostream>
#include <vector>
using namespace std;

int c[100001];
int p[100001];//ºÎ¸ð
vector<int> v[100001];

void parent(int x) {
	c[x] = 1;

	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];

		if (!c[next]) {
			p[next] = x;
			parent(next);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	

	for (int i = 1; i < n; i++) {
		int k1, k2;
		cin >> k1 >> k2;

		v[k1].push_back(k2);
		v[k2].push_back(k1);

	}
	parent(1);

	for (int i = 2; i <= n; i++)cout << p[i] << "\n";
}