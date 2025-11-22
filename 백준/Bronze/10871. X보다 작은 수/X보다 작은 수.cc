#include <bits/stdc++.h>
using namespace std;
int a, b, temp;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	for (int i : v) {
		if (i < b) cout << i << " ";
	}
}
