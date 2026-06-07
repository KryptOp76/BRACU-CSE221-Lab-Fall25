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

const int N = 2e5 + 10;
vi g[N];
bool vis[N];
bool valid = true;

void dfs(int u, int col, int &c0, int &c1) {
    vis[u] = true;
    if(col == 0) c0++;
    else c1++;
    for(auto v : g[u]) {
        if(!vis[v]) dfs(v, col ^ 1, c0, c1);
    }
}

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

    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            int c0 = 0, c1 = 0;
            dfs(i, 0, c0, c1);
            res += max(c0, c1);
        }
    }
    cout << res << nl;
    return 0;
}