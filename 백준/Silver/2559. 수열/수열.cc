#include <bits/stdc++.h>
using namespace std;
int n, k, a, psum[100004], ret = - 10000000;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		psum[i] = psum[i - 1] + a;
	}
	for (int i = k; i <= n; i++) {
		ret = max(ret, psum[i] - psum[i - k]);
	}
	cout << ret << "\n";
}