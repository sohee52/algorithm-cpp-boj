#include <bits/stdc++.h>
using namespace std;

struct Star { double x, y; };
vector<Star> stars;
vector<pair<double, pair<int,int>>> edges;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) parent[a] = b;
        else if (rank[a] > rank[b]) parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
        return true;
    }
};

void build_edges(int n) {
    edges.clear();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = dist(stars[i].x, stars[i].y, stars[j].x, stars[j].y);
            edges.push_back({d, {i, j}});
        }
    }
}

double kruskal(int n) {
    UnionFind uf(n);
    sort(edges.begin(), edges.end());

    double total = 0;
    int cnt = 0;

    for (auto &e : edges) {
        double w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if (uf.unite(u, v)) {
            total += w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    stars.resize(n);
    for (int i = 0; i < n; i++) cin >> stars[i].x >> stars[i].y;

    build_edges(n);
    double ans = kruskal(n);

    cout << fixed << setprecision(2) << ans << "\n";
}