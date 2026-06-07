#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define fi first
#define se second
#define pb push_back
using ll = long long int;
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
using vi = vector<int>; using vll = vector<ll>;
using pii = pair<int,int>; using pll = pair<ll,ll>;

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

    int n; cin >> n;
    vector<pii> duraDead(n);
    for(int i = 0; i < n; i++) cin >> duraDead[i].fi >> duraDead[i].se;
    sort(all(duraDead));

    ll ft = 0, ans = 0;
    for(auto &[dura, dead] : duraDead) {
        ft += dura;
        ans += (dead - ft);
    }
    cout << ans << nl;
    return 0;
}