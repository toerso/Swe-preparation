#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:
      vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        long long s = 0, s2 = 0;

        long long sn = (n * (n + 1)) / 2, s2n = (n * (n + 1) * (2*n + 1)) / 6;

        for (int i = 0; i < arr.size(); ++i) {
            s += arr[i];
            s2 += (long long) arr[i] * (long long) arr[i];
        }

        long long val1 = s - sn;
        long long val2 = (s2 - s2n) / val1;

        long long x = (val1 + val2) / 2;
        long long y = (val2 - x);

        return {(int) x, (int) y};
    }
};


int main() {
    #ifndef ONLINE_JUDGE
       (void) !freopen("../input.txt", "r", stdin);
       (void) !freopen("../output.txt", "w", stdout);
    #endif

    Solution s;
    vector<int> arr;
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr.emplace_back(x);
    }

    vector<int> ans = s.findTwoElement(arr);

    cout << ans[0] << " " << ans[1] << "\n";
  }