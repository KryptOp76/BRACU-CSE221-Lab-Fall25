#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
using ll = long long int;

void testCase() {
    string cal, exp; float x, y; cin >> cal >> x >> exp >> y;
    if(exp == "+") {
        cout << setprecision(9) << x + y << nl;
    } else if(exp == "-") {
        cout << setprecision(9) << x - y << nl;
    } else if(exp == "*") {
        cout << setprecision(9) << x * y << nl;
    } else {
        cout << setprecision(9) << x / y << nl;
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