#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 1000001
int F, S, G, U, D;

int a[MAX];
bool c[MAX];
vector<int> v;
queue<int>q;

void bfs(int x) {
	c[x] = 1;
	q.push(x);

	while (!q.empty()) {
		x = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int start = x + v[i];

			if (0 < start && start <= F) {
				if (!c[start]) {
					c[start] = 1;
					q.push(start);
					a[start] = a[x] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> F >> S >> G >> U >> D;

	v.push_back(U);
	v.push_back(D * -1);

	bfs(S);

	if (c[G]) {
		cout << a[G];
	}
	else cout << "use the stairs";
}