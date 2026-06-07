#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 1e9 + 7;

vector<ll> matrixMul(vector<ll>& a, vector<ll>& b) {
    vector<ll> ans(4);
    ans[0] = (a[0] * b[0] + a[1] * b[2]) % MOD;
    ans[1] = (a[0] * b[1] + a[1] * b[3]) % MOD;
    ans[2] = (a[2] * b[0] + a[3] * b[2]) % MOD;
    ans[3] = (a[2] * b[1] + a[3] * b[3]) % MOD;
    return ans;
}

vector<ll> binpow(vector<ll>& base, ll p) {
    vector<ll> ans = {1, 0, 0, 1};
    while(p > 0) {
        if(p % 2) ans = matrixMul(ans, base);
        base = matrixMul(base, base);
        p /= 2;
    }
    return ans;
}

void testCase() {
    vector<ll> matrix(4);
    for(int i = 0; i < matrix.size(); i++) {
        cin >> matrix[i];
        matrix[i] %= MOD;
    }
    ll x; cin >> x;

    vector<ll> result = binpow(matrix, x);
    cout << result[0] << " " << result[1] << nl;
    cout << result[2] << " " << result[3] << nl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int tc; cin >> tc;
    while(tc--) testCase();
    return 0;
}