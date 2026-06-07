#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 107;

ll binpow(ll b, ll p) {
    ll ans = 1;
    while(p > 0) {
        if(p % 2) ans = (ans % MOD * b % MOD) % MOD;
        b = (b % MOD * b % MOD) % MOD;
        p /= 2;
    }
    return ans;
}

void testCase() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    // int tc; cin >> tc;
    // while(tc--) testCase();

    ll a, b; cin >> a >> b;
    ll ans = binpow(a, b);
    cout << ans << nl;
    return 0;
}