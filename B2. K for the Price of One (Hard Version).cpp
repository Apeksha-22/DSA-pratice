#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        ll p;
        cin >> n >> p >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        const ll INF = (1ll<<60);
        vector<ll> cost(n+1, INF);
        cost[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cost[i] = cost[i-1] + a[i-1];
            if (i >= k) cost[i] = min(cost[i], cost[i-k] + a[i-1]);
        }
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (cost[i] <= p) ans = i;
        }
        cout << ans << '\n';
    }
    return 0;
}



Question Link: https://codeforces.com/problemset/problem/1699/B