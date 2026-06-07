#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

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

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> idx;
    int ops = 0;
    for(int i = 0; i < n - 2; i ++) {
        for(int j = 0; j < n - i - 2; j++) {
            if(a[j] > a[j + 2]) {
                int temp = a[j];
                a[j] = a[j + 2];
                a[j + 2] = temp;
                idx.push_back({j, j + 2});
                ops++;
            }
        }
    }

    bool isSorted = true;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] > a[i + 1]) isSorted = false;
    }

    if(isSorted) {
        cout << "YES" << nl;
        cout << ops << nl;
        for(auto [r, l] : idx) {
            cout << r + 1 << " " << l + 1 << nl;
        }
    } else {
        cout << "NO" << nl;
    }
    return 0;
}