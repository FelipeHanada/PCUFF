#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;

        int ans = -1;
        int best = 0, curr = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'R') curr--;
            else curr++;

            if (curr < best) {
                best = curr;
                ans = i;
            }
        }

        cout << ans + 1 << '\n';
    }
}