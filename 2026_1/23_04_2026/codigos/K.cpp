#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int md = int(1e9)+7;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}
int mult(int a, int b) {
    return ((ll)a * b) % md;
}

constexpr int N = int(1e6);

int main() {
    vector<int> pw2(N+1);
    pw2[0] = 1;
    for (int i=1; i<=N; i++) pw2[i] = mult(pw2[i-1], 2);
    
    vector<int> dp(N+1, 0);
    // dp[i] = número de sequencias binárias de tamanho i
    //          que não contém sequencia periódica
    // prop.: dp[i] = 2^i - (dp[j] forall j|i && j<i)
    // para toda sequência binária A de tamanho i que contém
    //          uma sequência binária B de tamanho j < i
    //      temos que j|i
    //      
    //      se B é periódica, então existe um j' < j tal que j'|j
    //          então podemos tomar j' no lugar de j
    //      se B não é periódica, então ela é contada em dp[j]
    //      
    //      portanto, existe uma correspondência 1:1 de toda
    //      sequência binária periódica A com uma única sequência binária B
    //      que não é periódica e possui tamanho j<i com j|i
    //      (esta é contada em dp[j])

    for (int i=1; i<=N; i++) {
        dp[i] = add(dp[i], pw2[i]);
        for (int j=2*i; j<=N; j+=i) {
            dp[j] = sub(dp[j], dp[i]);
        }
    }

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        cout << sub(pw2[n], dp[n]) << '\n';
    }
}
