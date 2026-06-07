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

vi trialDivision(int n) {
    vi factors;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            factors.pb(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) factors.pb(n);
    return factors;
}

void testCase() {
    int s, t; cin >> s >> t;

    if(s == t) {
        cout << 0 << nl;
        return;
    }
    if(s > t) {
        cout << -1 << nl;
        return;
    }

    vi dist(t + 1, -1);
    dist[s] = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(u == t) {
            cout << dist[u] << nl;
            return;
        }

        vi factors = trialDivision(u);

        for(auto p : factors) {
            if(p == u) continue;
            int v = u + p;
            if(v <= t && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    cout << -1 << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int tc; cin >> tc;
    while(tc--) testCase();
    return 0;
}