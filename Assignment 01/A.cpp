#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
using ll = long long int;

void testCase() {
    int n; cin >> n;
    if(n % 2 == 0) {
        cout << n << " is an Even number." << nl;
    } else {
        cout << n << " is an Odd number." << nl;
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