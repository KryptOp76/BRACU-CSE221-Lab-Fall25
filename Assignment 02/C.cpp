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
    ll n, x; cin >> n >> x;
    vector<pair<ll, ll >> a(n);
    for(int i = 0; i < n; i++) {
        ll v; cin >> v;
        a[i] = {v, i};
    }

    sort(all(a));
    for(int l = 0; l < n; l++) {
        int m = l + 1, r = n - 1;
        while(m < r) {
            if(a[l].first + a[m].first + a[r].first == x) {
                cout << a[l].second + 1 << " " <<
                a[m].second + 1 << " " <<
                a[r].second + 1 << nl;
                return 0;
            } else if(a[l].first + a[m].first + a[r].first < x) {
                m++;
            } else {
                r--;
            }
        }
    }
    cout << -1 << nl;
    return 0;   
}