#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

pair<ll, ll> powerSum(ll a, ll n, ll m) {
    if(n == 1) {
        ll power = a % m;
        ll sum = a % m;
        return {power, sum};
    }

    if(n % 2 == 0) {
        auto [halfPower, halfSum] = powerSum(a, n / 2, m);
        ll fullPower = (halfPower * halfPower) % m;
        ll fullSum = (halfSum * (1 + halfPower)) % m;
        return {fullPower, fullSum};
    } else {
        auto [prevPower, prevSum] = powerSum(a, n - 1, m);
        ll currPower = (prevPower * (a % m)) % m;
        ll currSum = (prevSum + currPower) % m;
        return {currPower,currSum};
    }
}

ll fastSeriesSum(ll a, ll n, ll m) {
    if(a % m == 0) return 0;
    if(a % m == 1) return n % m;

    auto [power, sum] = powerSum(a, n, m);
    return sum;
}

void testCase() {
    ll a, n, m; cin >> a >> n >> m;
    cout << fastSeriesSum(a, n, m) << nl;
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