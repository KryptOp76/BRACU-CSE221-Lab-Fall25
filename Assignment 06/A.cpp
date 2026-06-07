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

vi topoSort(const vector<vi>& gr) {
    vi indeg(gr.size()), q;
    for(auto& li : gr) for(int x : li) indeg[x]++;
    for(int i = 0; i < gr.size(); i++) if(indeg[i] == 0) q.push_back(i);
    for(int j = 0; j < q.size(); j++) for(int x : gr[q[j]])
        if(--indeg[x] == 0) q.push_back(x);
    return q;
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
    vector<vi> g(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
    }

    vi order = topoSort(g);
    if(sz(order) == n + 1) {
        for(int i = 1; i <= n; i++) cout << order[i] << " ";
        cout << nl;
    } else {
        cout << -1 << nl;
    }
    return 0;
}