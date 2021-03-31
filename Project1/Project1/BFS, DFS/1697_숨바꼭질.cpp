#include <iostream>
#include <queue>
using namespace std;

int c[100001];
int n, k;

int bfs(int n, int k) {
	
	queue<pair<int, int>>q;
	q.push({ n, 0 });
	c[n] = 1;

	while (!q.empty()) {
		int situation = q.front().first;
		int time = q.front().second;
		q.pop();

		if (situation == k) return time;
		if (situation + 1 < 100001 && !c[situation + 1]) {
			q.push({ situation + 1, time + 1 });
			c[situation+1] = 1;
			
		}
		if (situation - 1 >=0 && !c[situation - 1]) {
			q.push({ situation - 1, time + 1 });
			c[situation-1] = 1;

		}
		if (situation *2 < 100001 && !c[situation * 2]) {
			q.push({ situation* 2, time + 1 });
			c[situation*2] = 1;

		}



	}

		

}

int main() {
	cin >> n >> k;

	cout << bfs(n, k) << endl;
}