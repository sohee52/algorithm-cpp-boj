#include <bits/stdc++.h>
using namespace std;
int n, m, temp, a[100004], s, e;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
    cin >> a[1];
    for (int i = 2; i <= n; i++) {
        cin >> temp;
        a[i] = a[i-1] + temp;
    }
    while(m--) {
        cin >> s >> e;
        cout << a[e] - a[s-1] << "\n";
    }
}
