#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll c, r, s;
        cin >> c >> r >> s;

        ll n = (c + r + s - 1) / s;

        cout << n-(r+s-1)/s << ' ' << max(0LL, n-r) << '\n';
    }
}