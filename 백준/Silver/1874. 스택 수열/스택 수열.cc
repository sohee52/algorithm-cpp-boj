#include <bits/stdc++.h>
using namespace std;
int n, a[100004], i = 1, cnt = 1, visited[100004];
bool flag;
stack<int> stk;
vector<char> v;

void add() {
    stk.push(i);
    visited[i] = 1;
    v.push_back('+');
    // cout << "i = " << i << " stk.top() = " << stk.top() << " + " << " cnt = " << cnt << "\n";
    i++; 
}

void sub() {
    if (stk.empty()) flag = 1;
    else if (stk.top() < a[cnt]) {
        // cout << "i = " << i << " stk.top() = " << stk.top() << " - " << " cnt = " << cnt << "\n";
        stk.pop();
        v.push_back('-');
    } else if (stk.top() == a[cnt]) {
        // cout << "i = " << i << " stk.top() = " << stk.top() << " - " << " cnt = " << cnt << "\n";
        stk.pop();
        v.push_back('-');
        cnt++;
    } else if (stk.top() > a[cnt]) {
        flag = 1;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (true) {
        if (i <= a[cnt]) add();
        else if (i > a[cnt]) sub();
        if (cnt == n + 1) break;
        if (flag) break;
        if (cnt > n + 1 || i > n + 1) {
            flag = 1; break;
        }
    }

    // cout << "result\n";
    if(flag) cout << "NO\n";
    else {
        for (char a : v) {
            cout << a << "\n";
        }
    }
}
