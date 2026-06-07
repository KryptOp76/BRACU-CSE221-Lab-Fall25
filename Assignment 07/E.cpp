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
ll dist[N][2];
int n, m;

void dijkstra(int src) {
    for(int i = 1; i <= n; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    priority_queue<pair<ll, pii>,
                   vector<pair<ll, pii>>,
                   greater<pair<ll, pii>>> pq;

    pq.push({0, {src, 2}});

    while(!pq.empty()) {
        ll d_u = pq.top().fi;
        int u = pq.top().se.fi;
        int lastType = pq.top().se.se;
        pq.pop();

        if(lastType != 2 && d_u > dist[u][lastType]) continue;

        for(auto &[v, w] : g[u]) {
            int currParity = w % 2;
            
            if(lastType == 2 || lastType != currParity) {
                if(d_u + w < dist[v][currParity]) {
                    dist[v][currParity] = d_u + w;
                    pq.push({dist[v][currParity], {v, currParity}});
                }
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

    vi u(m), v(m), w(m);
    for(int i = 0; i < m; i++) cin >> u[i];
    for(int i = 0; i < m; i++) cin >> v[i];
    for(int i = 0; i < m; i++) cin >> w[i];

    for(int i = 0; i < m; i++) {
        g[u[i]].pb({v[i], w[i]});
    }

    dijkstra(1);

    ll ans = min(dist[n][0], dist[n][1]);
    if(ans == INF) cout << -1 << nl;
    else cout << ans << nl;
    return 0;
}