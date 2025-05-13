#include<iostream>
#include<climits>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

class Solution {
    public:
      int maxSum(vector<int> &arr) {
          int n = arr.size();
          int sum = accumulate(arr.begin(), arr.end(), 0);
          
          int prev = 0;
          
          for (int i = 0; i < n; ++i) {
              prev += (i * arr[i]);
          }
          
          int ans = prev;
          
          for (int i = 1; i < n; ++i) {
              int tmp = prev - (sum - arr[i - 1]) + arr[i - 1] * (n - 1);
              ans = max(ans, tmp);
              prev = tmp;
          }
          
          return ans;
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

    int ans = s.maxSum(arr);

    cout << ans << "\n";

  }