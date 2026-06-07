#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

const int N = 1e3 + 10;
vector<pair<int, int>> graph[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;

    vector<int> u(m + 1), v(m + 1);
    for(int i = 1; i <= m; i++) cin >> u[i];
    for(int i = 1; i <= m; i++) cin >> v[i];

    for(int i = 1; i <= m; i++) {
        int wt; cin >> wt;
        graph[u[i]].push_back({v[i], wt});
    }

    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(int j = 0; j < graph[i].size(); j++) {
            cout << "(" << graph[i][j].first << "," << graph[i][j].second << ") ";
        }
        cout << nl;
    }
    return 0;
}