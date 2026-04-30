#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n; string s;
    cin >> n >> s;
    ll m = stoll(string(s.begin(), s.end() - 1));
    if (s.back() == 'G') m *= 1024LL;
    else if (s.back() == 'T') m *= 1024LL * 1024;

    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<ll> prefix(n+1);
    prefix[0] = 0;
    for (int i=1; i<=n; i++) prefix[i] = prefix[i-1] + a[i-1];

    auto check = [&](int r) -> pair<bool, int> {
        for (int i=0; i+r <= n; i++) {
            if (prefix[i+r] - prefix[i] > m)
                return {0, -1};
        }

        for (int i=0; i+r+1 <= n; i++) {
            if (prefix[i+r+1] - prefix[i] > m)
                return {1, i + 1};
        }

        return {1, -1};
    };

    if (prefix.back() <= m) {
        cout << n << " -1\n";
        return 0;
    }

    int l=1, r=n, L = -1;
    for (int i=0; L == -1 && i<n-1; i++) {
        if (a[i] + a[i+1] > m) L = i + 1;
    }

    while (r - l > 1) {
        int mid = (l + r) / 2;
        auto [ok, LL] = check(mid);
        if (ok) {
            l = mid;
            L = LL;
        } else {
            r = mid;
        }
    }

    cout << l << ' ' << L << '\n';
}