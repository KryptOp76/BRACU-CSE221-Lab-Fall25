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

int n, m, s, d;
vector<pii> g[N];
ll dist[N], c[N];

void dijkstra() {
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        auto [d_u, u] = pq.top(); pq.pop();
        if(d_u > dist[u]) continue;
        for(auto &[v, w] : g[u]) {
            if(dist[u] + w < dist[v]) {
                pq.push({dist[v] = dist[u] + w, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> s >> d;

    for(int i = 1; i <= n; i++) cin >> c[i];

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].pb({v, c[v]});
    }

    dijkstra();

    if(dist[d] == INF) {
        cout << -1 << nl;
    } else {
        cout << dist[d] + c[s] << nl;
    }
    return 0;
}