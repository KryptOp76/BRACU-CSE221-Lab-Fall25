#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

const int N = 1e3 + 10;
int graph[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int v1, v2, w; cin >> v1 >> v2 >> w;
        graph[v1][v2] = w;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << nl;
    }
    return 0;
}