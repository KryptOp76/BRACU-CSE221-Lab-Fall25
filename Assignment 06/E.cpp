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

    int n, m, s, q; cin >> n >> m >> s >> q;
    vector<vi> g(n + 1);
    while(m--) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    vi dist(n + 1, -1);
    queue<int> qu;
    while(s--) {
        int si; cin >> si;
        qu.push(si);
        dist[si] = 0;
    }

    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for(auto v : g[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
    }

    while(q--) {
        int qi; cin >> qi;
        cout << dist[qi] << " ";
    }
    cout << nl;
    return 0;
}