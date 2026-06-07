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
    vector<pii> times(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        times[i] = {b, a};
    }
    sort(all(times));

    vector<pii> ans;
    ans.pb({times[0].se, times[0].fi});
    int prevET = times[0].fi, cnt = 1;
    for(int i = 1; i < n; i++) {
        if(times[i].se > prevET) {
            cnt++;
            prevET = times[i].fi;
            ans.pb({times[i].se, times[i].fi});
        }
    }

    cout << cnt << nl;
    for(auto [st, et] : ans) {
        cout << st << " " << et << nl;
    }
    return 0;
}