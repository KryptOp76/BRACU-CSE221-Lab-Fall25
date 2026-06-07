#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
using ll = long long int;

void testCase() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(n == 1) {
        cout << "YES" << nl;
        return;
    }

    bool isSorted = true;
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i - 1]) {
            isSorted = false;
        }
    }
    if(isSorted) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) testCase();
    return 0;
}