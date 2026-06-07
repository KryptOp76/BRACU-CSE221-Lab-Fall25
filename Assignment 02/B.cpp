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
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int l = 0, r = m - 1, i = 0, j = 0;
    ll minGap = INT_MAX;
    while(l < n && r >= 0) {
        if(abs(a[l] + b[r] - k) < minGap) {
            minGap = abs(a[l] + b[r] - k);
            i = l; j = r;
            if(minGap == 0) {
                break;
            }
        }
        if(a[l] + b[r] <= k) {
            l++;
        } else {
            r--;
        }
    }
    cout << i + 1 << " " << j + 1 << nl;
    return 0;   
}