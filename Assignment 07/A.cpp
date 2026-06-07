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
vector<ll> dist(N, INF), par(N, -1);
int n, m, s, d;

void dijkstra() {
    dist[s] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        auto [d_u, u] = pq.top();
        pq.pop();

        if(d_u > dist[u]) continue;

        for(auto &[v, w] : g[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;
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

    cin >> n >> m >> s >> d;
    vi u(m), v(m), w(m);
    for(int i = 0; i < m; i++) cin >> u[i];
    for(int i = 0; i < m; i++) cin >> v[i];
    for(int i = 0; i < m; i++) cin >> w[i];

    for(int i = 0; i < m; i++) {
        g[u[i]].pb({v[i], w[i]});
    }

    dijkstra();

    if(dist[d] == INF) {
        cout << -1 << nl;
    } else {
        cout << dist[d] << nl;

        vi path;
        for(int now = d; now != s; now = par[now]) {
            path.pb(now);
        }
        path.pb(s);
        reverse(all(path));

        for(auto node : path) cout << node << " ";
        cout << nl;
    }
    return 0;
}