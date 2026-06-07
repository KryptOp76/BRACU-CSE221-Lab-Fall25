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

const ll INF = 1e18;
const int N = 2e5 + 10;

vector<pii> g[N];
ll dist[N];
int n, m;

void dijkstra(int src) {
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[src] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d_u, u] = pq.top();
        pq.pop();

        if(d_u > dist[u]) continue;

        for(auto &[v, w] : g[u]) {
            ll newDanger = max(dist[u], (ll)w);
            if(newDanger < dist[v]) {
                dist[v] = newDanger;
                pq.push({dist[v], v});
            }
        }
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

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    dijkstra(1);

    for(int i = 1; i <= n; i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    }
    cout << nl;
    return 0;
}