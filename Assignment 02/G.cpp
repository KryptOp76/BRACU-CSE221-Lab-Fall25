#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

void testCase() {

}

int lower_bound(vector<ll> &a, ll x) {
    int l = 0, r = a.size() - 1, idx = a.size();
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(a[m] >= x) {
            idx = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return idx;
}

int upper_bound(vector<ll> &a, ll y) {
    int l = 0, r = a.size() - 1, idx = a.size();
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(a[m] > y) {
            idx = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    // int tc; cin >> tc;
    // while(tc--) testCase();

    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    while(q--) {
        ll x, y; cin >> x >> y;
        int l = lower_bound(a, x);
        int r = upper_bound(a, y);
        cout << r - l<< nl;
    }
    return 0;
}