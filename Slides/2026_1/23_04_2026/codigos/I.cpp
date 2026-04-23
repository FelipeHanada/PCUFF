#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        int ans = 0;
        while (n) {
            int _old = n;

            int _new = 1;
            int curr = n;
            while (curr) {
                _new *= curr % 10;
                curr /= 10;
            }

            if (_old == _new) break;
            ans++;
            n = _new;
        }

        cout << ans << '\n';
    }
}