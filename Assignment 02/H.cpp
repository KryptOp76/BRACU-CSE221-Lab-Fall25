#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

void testCase() {
    ll k, x; cin >> k >> x;
    ll div = k / (x - 1), mod = k % (x - 1);
    if(mod == 0) {
        cout << x * div - 1 << nl;
    } else {
        cout << x * div + mod << nl;
    }
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