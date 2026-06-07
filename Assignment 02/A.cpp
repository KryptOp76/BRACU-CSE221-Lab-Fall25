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

    ll n, s; cin >> n >> s;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = n - 1;
    while(r > l) {
        if(a[l] + a[r] == s) {
            cout << l + 1 << " " << r + 1 << nl;
            return 0;
        }
        if(a[l] + a[r] > s) {
            r--;
        } else {
            l++;
        }
    }
    cout << -1 << nl;
    return 0;
}