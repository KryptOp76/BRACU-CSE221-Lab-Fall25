#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

void testCase() {

}

int toMinutes(string &t) {
    return ((t[0] - '0') * 10 + (t[1] - '0')) * 60 +
            ((t[3] - '0') * 10 + (t[4] - '0'));
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
    vector<string> train(n), city(n), strTime(n);
    string w2, w3, w4, w6;
    for(int i = 0; i < n; i++) {
        cin >> train[i] >> w2 >> w3 >> w4 >> city[i] >> w6 >> strTime[i];
    }

    vector<int> time(n), idx(n);
    for(int i = 0; i < n; i++) {
        time[i] = toMinutes(strTime[i]);
        idx[i] = i;
    }

    for(int i = 0; i < n; i++) {
        int minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if((train[j] < train[minIdx]) ||
            (train[j] == train[minIdx] && time[j] > time[minIdx]) ||
            (train[j] == train[minIdx] && time[j] == time[minIdx] && idx[j] < idx[minIdx])) {
                minIdx = j;
            }
        }
        if(minIdx != i) {
            swap(train[i], train[minIdx]);
            swap(time[i], time[minIdx]);
            swap(strTime[i], strTime[minIdx]);
            swap(city[i], city[minIdx]);
            swap(idx[i], idx[minIdx]);
        }
    }

    for(int i = 0; i < n; i++) {
        cout << train[i] << " will departure for " 
        << city[i] << " at " << strTime[i] << nl;
    }
    return 0;
}