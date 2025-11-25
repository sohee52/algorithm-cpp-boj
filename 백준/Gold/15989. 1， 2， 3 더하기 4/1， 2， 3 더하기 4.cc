#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 1e12;
typedef pair <int, int> pii;

int t, n, dp[100001][4];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    dp[1][1] = 1;
    dp[2][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;
    
    for(int i = 4; i < 10001; i++)
    {
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }

    while(t--)
    {
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }

    return 0;
}