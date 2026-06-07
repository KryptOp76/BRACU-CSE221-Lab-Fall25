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
    
    int n; cin >> n;

    for(int v1 = 0; v1 < n; v1++) {
        int k; cin >> k;
        while(k--) {
            int v2; cin >> v2;
            graph[v1][v2] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << nl;
    }
    return 0;
}