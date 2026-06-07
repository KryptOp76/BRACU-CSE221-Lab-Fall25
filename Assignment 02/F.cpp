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

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, int> m;
    int l = 0, r = 0, ans = 0;
    while(r < n) {
        m[a[r]]++;
        while(m.size() > k) {
            m[a[l]]--;
            if(m[a[l]] == 0) m.erase(a[l]);
            l++;
        }
        if(m.size() <= k) {
            ans = max(ans, r - l + 1);
        }
        r++;
    }
    cout << ans << nl;
    return 0;
}