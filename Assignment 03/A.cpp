#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

void testCase() {

}

ll cnt = 0;
vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> sortedList;
    int l = 0, r = 0;
    while(l < left.size() && r < right.size()) {
        if(left[l] <= right[r]) sortedList.push_back(left[l++]);
        else sortedList.push_back(right[r++]), cnt += (left.size() - l);
    }
    while(l < left.size()) sortedList.push_back(left[l++]);
    while(r < right.size()) sortedList.push_back(right[r++]);
    return sortedList;
}

vector<int> mergeSort(vector<int>& lst, int lo, int hi) {
    if(lo == hi) return {lst[lo]};

    int mid = lo + (hi - lo) / 2;
    vector<int> left = mergeSort(lst, lo, mid);
    vector<int> right = mergeSort(lst, mid + 1, hi);

    return merge(left, right);
}

vector<int> mergeSort(vector<int>& lst) {
    if(lst.size() == 0) {
        return {};
    }
    return mergeSort(lst, 0, lst.size() - 1);
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

    a = mergeSort(a);
    cout << cnt << nl;
    for(auto x : a) cout << x << " ";
    cout << nl;
    return 0;
}