#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

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

    ll n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = 0, maxSub = 0;
    ll sum = 0;
    for(r = 0; r < n; r++) {
        sum += a[r];
        while(l <= r && sum > k) {
            sum -= a[l];
            l++;
        }
        maxSub = max(maxSub, r - l + 1);
    }
    cout << maxSub << nl;
    return 0;
}