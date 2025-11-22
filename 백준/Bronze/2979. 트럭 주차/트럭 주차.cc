#include <bits/stdc++.h>
using namespace std;
int a, b, c, s, e, ret;
int r[104];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		cin >> s >> e;
		for (int j = s; j < e; j++) {
			r[j]++;
		}
	}
	for (int i = 0; i < 104; i++) {
		if (r[i] == 0) continue;
		else if (r[i] == 1) ret += a;
		else if (r[i] == 2) ret += 2 * b;
		else ret += 3 * c;
	}
	cout << ret << "\n";
}