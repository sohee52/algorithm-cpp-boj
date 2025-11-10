#include <bits/stdc++.h>
using namespace std;
int t, n;
int go(int sum) {
    if(sum == n) return 1;
    if(sum > n) return 0;
    return go(sum+1) + go(sum+2) + go(sum+3);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> t;
	for (int i = 0; i < t; i++) {
        cin >> n;
        cout << go( 0) << "\n";
    }
}
