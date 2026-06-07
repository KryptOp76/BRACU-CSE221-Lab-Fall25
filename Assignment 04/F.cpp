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
    int x, y; cin >> x >> y;
    vector<pii> a;

    if(x - 1 >= 1 && y - 1 >= 1) a.pb({x - 1, y - 1});
    if(x - 1 >= 1) a.pb({x - 1, y});
    if(y - 1 >= 1) a.pb({x, y - 1});

    if(x + 1 <= n && y + 1 <= n) a.pb({x + 1, y + 1});
    if(x + 1 <= n) a.pb({x + 1, y});
    if(y + 1 <= n) a.pb({x, y + 1});

    if(x - 1 >= 1 && y + 1 <= n) a.pb({x - 1, y + 1});
    if(x + 1 <= n && y - 1 >= 1) a.pb({x + 1, y - 1});

    sort(all(a));
    cout << sz(a) << nl;
    for(auto [xi, yi] : a) cout << xi << " " << yi << nl;
    return 0;
}