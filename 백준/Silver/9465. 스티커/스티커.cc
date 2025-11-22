#include <bits/stdc++.h>
using namespace std;
int t, n, a[100004][3], dp[100004][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
    while(t--) {
        cin >> n;
        for (int j = 0; j < 2; j++) {
            for (int i = 1; i <= n; i++) {
                cin >> a[i][j];
            }
        }

        dp[1][0] = a[1][0];
        dp[1][1] = a[1][1];
        dp[1][2] = 0;

        // 0: 위, 1: 아래, 2: 떼지 않음
        for (int i = 2; i <= n; i++) {
            // cout << i << "번째 줄\n";
            dp[i][0] = a[i][0] + max(dp[i-1][1], dp[i-1][2]);
            // cout << dp[i][0] << "\n";
            dp[i][1] = a[i][1] + max(dp[i-1][0], dp[i-1][2]);
            // cout << dp[i][1] << "\n";
            dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
            // cout << dp[i][2] << "\n";
        }

        // cout << "result\n";
        cout << max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
    }
}
