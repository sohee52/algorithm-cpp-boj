#include <bits/stdc++.h>
using namespace std;
int k, temp, num;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> temp;
        if (temp == 0) v.pop_back();
        else v.push_back(temp);
    }
    for (int i = 0; i < v.size(); i++) {
        num += v[i];
    }
    cout << num << "\n";
}
