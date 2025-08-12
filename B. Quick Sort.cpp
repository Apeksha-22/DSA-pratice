#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        vector<int> pos(n+1);
        for (int i = 0; i < n; ++i) pos[p[i]] = i;
        int m = 0;
        int last = -1;
        for (int x = 1; x <= n; ++x) {
            if (pos[x] > last) {
                ++m;
                last = pos[x];
            } else break;
        }
        int need = n - m;
        int ans = (need + k - 1) / k;
        cout << ans << '\n';
    }
    return 0;
}



Question Link: https://codeforces.com/problemset/problem/1699/B