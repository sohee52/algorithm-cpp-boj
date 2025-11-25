#include <bits/stdc++.h>
using namespace std;

int dpInc[1004], dpDe[1004], a[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dpInc[i] = dpDe[i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[i] > a[j] && dpInc[i] == dpInc[j]) dpInc[i]++;
        }
    }

    for(int i = n-1; i >= 1; i--){
        for(int j = n; j > i; j--){
            if(a[i] > a[j] && dpDe[i] == dpDe[j]) dpDe[i]++;
        }
    }

    int max = 0;
    for(int i = 1; i <= n; i++){
        int sum = dpInc[i] + dpDe[i];
        if(sum > max) max = sum;
    }

    cout << max - 1;
    return 0;
}