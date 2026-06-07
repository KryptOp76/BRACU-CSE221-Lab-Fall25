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
ll dist1[N], dist2[N];
int n, m, s, d;

void dijkstra() {
    for(int i = 1; i <= n; i++) {
        dist1[i] = INF;
        dist2[i] = INF;
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    dist1[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        auto[d_u, u] = pq.top();
        pq.pop();

        if(d_u > dist2[u]) continue;

        for(auto &[v, w] : g[u]) {
            ll newDist = d_u + w;

            if(newDist < dist1[v]) {
                dist2[v] = dist1[v];
                dist1[v] = newDist;
                pq.push({dist1[v], v});
                pq.push({dist2[v], v});
            } else if(newDist > dist1[v] && newDist < dist2[v]) {
                dist2[v] = newDist;
                pq.push({dist2[v], v});
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

    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    dijkstra();

    if(dist2[d] == INF) cout << -1 << nl;
    else cout << dist2[d] << nl;
    return 0;
}