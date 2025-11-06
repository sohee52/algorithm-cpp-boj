#include <bits/stdc++.h>
using namespace std;
int n, num = 5000, mn = 5000, k;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
    for (int i = n/5; i >= 0; i--) {
        k = n-(i*5);
        if(k % 3 == 0) num = k/3 + i;
        mn = min(num, mn);
    }
    if (mn == 5000) cout << "-1\n";
    else cout << mn << "\n";
}

