#include <bits/stdc++.h>
using namespace std;

int omp_greedy(int n, int* files) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) pq.push(files[i]);

    int cost = 0;
    int file1, file2, file3;
    while(pq.size() > 1) {
        file1 = pq.top(); pq.pop();
        file2 = pq.top(); pq.pop();
        file3 = file1 + file2;
        cost += file3;
        pq.push(file3);
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int files[100005];

    for (int i = 0; i < n; i++) cin >> files[i];

    cout << omp_greedy(n, files) << "\n";
    return 0;
}
