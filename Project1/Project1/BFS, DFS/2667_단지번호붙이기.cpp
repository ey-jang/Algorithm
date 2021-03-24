#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[26][26];
int c[26][26];


int dx[] = { 0, 1, -1, 0 };
int dy[] = { 1, 0, 0, -1 };
int sum=0;
void dfs(int x, int y) {
	sum++;
	c[x][y]=1;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (a[nx][ny] == 1 && !c[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++)	a[i][j] = temp[j] - '0';
	}
	
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && !c[i][j]) {
				
				dfs(i, j);
				v.push_back(sum);
				sum = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}