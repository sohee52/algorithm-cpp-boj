#include <bits/stdc++.h>
using namespace std;
int n, a[130][130];
int white = 0;
int blue = 0;
void dnc(int x, int y, int k) {
	bool cut = false;
	int first_color = a[x][y];
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if (a[i][j] != first_color) {
				cut = true;
				break;
			}
		}
	}

	if (cut) {
		dnc(x, y, k/2);
		dnc(x, y+k/2, k/2);
		dnc(x+k/2, y, k/2);
		dnc(x+k/2, y+k/2, k/2);
	} else {
		if (first_color == 1) blue++;
		else white++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	dnc(0, 0, n);
	cout << white << "\n";
	cout << blue << "\n";
	return 0;
}
