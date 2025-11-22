#include <bits/stdc++.h>
using namespace std;
int n, ret = -987654321;
string s;
vector<int> num;
vector<char> op;
int cal (char a, int b, int c) {
	if (a == '+') return b + c;
	if (a == '-') return b - c;
	if (a == '*') return b * c;
}
void go(int idx, int sum) {
	if (idx == num.size() - 1) {
		ret = max(ret, sum);
		return;
	}
	go(idx+1, cal(op[idx], sum, num[idx+1]));
	if (idx+2 <= num.size() - 1) {
		go(idx+2, cal(op[idx], sum, cal(op[idx+1], num[idx+1], num[idx+2])));
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) num.push_back(s[i]-'0');
		else op.push_back(s[i]);
	}
	go(0, num[0]);
	cout << ret << "\n";
}