#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n; string s;
    cin >> n >> s;
    ll m = stoll(string(s.begin(), s.end() - 1).c_str());
    if (s.back() == 'G') m *= 1024LL;
    else if (s.back() == 'T') m *= 1024LL * 1024;

    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int i=0, j=0;
    int R;
    vector<int> L(n+1, -1);
    ll curr = 0;

    while (j < n && curr + a[j] <= m)
        curr += a[j++];
    R = j - i;
    if (j < n && L[j-i] == -1) L[j-i] = i + 1;
    curr -= a[i++];

    while (R <= n - i) {
        while (j < n && curr + a[j] <= m)
            curr += a[j++];

        R = min(R, j - i);
        if (j < n && L[j-i] == -1) L[j-i] = i + 1;

        curr -= a[i++];
    }

    cout << R << ' ' << L[R] << '\n';
}