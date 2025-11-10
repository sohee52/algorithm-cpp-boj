#include <bits/stdc++.h>
using namespace std;
int n, m, a[10];
void go(int idx, int start) {
    if (idx == m) {
        for (int i = 0; i < m; i++) cout << a[i] << " ";
        cout << "\n";
    } else {
        for (int i = start; i <= n; i++) {
            a[idx] = i;
            go(idx+1, i);
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
    go(0, 1);
}
