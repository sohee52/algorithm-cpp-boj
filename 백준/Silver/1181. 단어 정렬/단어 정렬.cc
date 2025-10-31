#include <bits/stdc++.h>
using namespace std;
int n;
string temp;
vector<string> v;
bool cmp (const string &a, const string &b) {
    if (a.length() != b.length()) return a.length() < b.length();
    return a < b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (string &s : v) cout << s << "\n";
    return 0;
}
