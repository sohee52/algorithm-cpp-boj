#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
stack<int> stk;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "push") {
            cin >> k;
            stk.push(k);
        } else if (s == "top") {
            if (stk.empty()) cout << -1 << "\n";
            else {
                cout << stk.top() << "\n";
            }
        } else if (s == "size") {
            cout << stk.size() << "\n";
        } else if (s == "pop") {
            if (stk.empty()) cout << -1 << "\n";
            else {
                cout << stk.top() << "\n";
                stk.pop();
            }
        } else if (s == "empty") {
            if (stk.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}
