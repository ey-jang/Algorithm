#include <iostream>
using namespace std;

int a[129][129];
int w, b = 0;

void sol(int x, int y, int size) {
	int tmp = 0;
	for (int i = x; i < x+size; i++) {
		for (int j = y; j < y+size; j++) {
			if (a[i][j] == 1)tmp++;
		}
	}
	if (tmp==0) w++;
	else if (tmp == size*size) b++;
	else {
		sol(x, y, size/ 2);
		sol(x + size / 2, y, size/2);
		sol(x, y+size/2, size / 2);
		sol(x + size / 2, y+size/2, size / 2);
	}
	
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j]; //하얀색 : 0, 파란색 : 1
		}
	}

	sol(0, 0, n);
	cout << w <<"\n"<< b;
	

}