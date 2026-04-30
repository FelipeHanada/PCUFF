#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n, T;
    cin >> n >> T;
    vector<int> h(n), d(n);

    map<int, vector<int>> moves;
    map<int, ll> dp;
    set<int> times;

    for (int i=0; i<n; i++) {
        int t;
        cin >> h[i] >> d[i] >> t;
        for (int j=0; j<t; j++) {
            int ti; cin >> ti;
            moves[ti].push_back(i);
            dp[ti] = 0;
            times.insert(ti);
        }
    }

    dp[0] = dp[INT32_MAX] = 0;

    ll last = 0;
    for (int t : times) {
        dp[t] = max(dp[t], last);
        for (int i : moves[t]) {
            auto lb = dp.lower_bound(t + d[i]);
            if (lb == dp.end()) continue;
            dp[lb->first] = max(lb->second, dp[t] + h[i]);
        }
        last = dp[t];
    }

    cout << max(last, dp[INT32_MAX]) << '\n';
}