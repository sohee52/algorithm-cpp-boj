#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n, t, a, b, cnt, s, e, last;
pll jobs[100004];

void solve() {
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    for (int i = 0; i < n; i++) {
        pq.push(jobs[i]);
    }

    while(!pq.empty()) {
        e = pq.top().first;
        s = pq.top().second;
        pq.pop();
        if (s >= last) {
            cnt++;
            last = e;
        }
    }
    cout << cnt << "\n";
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        jobs[i] = {b, a};
    }
       solve();
}