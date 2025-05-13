#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    public:
      // Function to find maximum product subarray
      int maxProduct(vector<int> &arr) {
          int n = arr.size();
          int maxmul = INT_MIN;
          int pref = 1, suff = 1;
          
          for (int i = 0; i < n; i++) {
              if (pref == 0) pref = 1;
              if (suff == 0) suff = 1;
              
              pref = pref * arr[i];
              suff = suff * arr[n - i - 1];
              
              maxmul = max(maxmul, max(pref, suff));
          }
          
          return maxmul;
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

    int ans = s.maxProduct(arr);

    cout << ans << "\n";

  }