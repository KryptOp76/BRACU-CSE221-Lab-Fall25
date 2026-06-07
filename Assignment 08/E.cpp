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
    int n, k; cin >> n >> k;
    vector<pii> times(n);
    for(int i = 0; i < n; i++) cin >> times[i].se >> times[i].fi;
    sort(all(times));

    int cnt = 0;
    multiset<int> et;
    for(int i = 0; i < k; i++) et.insert(-1);

    for(int i = 0; i < n; i++) {
        auto it = et.lower_bound(times[i].se);
        if(it == begin(et)) continue;

        et.erase(--it);

        et.insert(times[i].fi);
        cnt++;
    }
    cout << cnt << nl;
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