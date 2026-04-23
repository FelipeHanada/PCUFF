#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<string> grid;
array<vector<pair<int,int>>,26> a;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
inline bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i=0; i<n; i++) cin >> grid[i];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            a[grid[i][j]-'A'].push_back(make_pair(i, j));
        }
    }

    int ans = INT32_MIN;
    vector<vector<int>> dp(n, vector<int>(m, 1));
    for (int i=0; i<26; i++) {
        for (auto [x, y] : a[i]) {
            ans = max(ans, dp[x][y]);

            for (int k=0; k<8; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (valid(nx, ny) && grid[x][y] + 1 == grid[nx][ny]) {
                    dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
                }
            }
        }
    }

    cout << ans << '\n';
}