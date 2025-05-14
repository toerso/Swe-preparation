#include<iostream>
#include<climits>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

class Solution {
    public:
      int maxWater(vector<int> &arr) {
          int n = arr.size();
          vector<int> prefixMax(n), suffixMax(n);
          prefixMax[0] = arr[0], suffixMax[n - 1] = arr[n - 1];
          
          for (int i = 1; i < n; ++i) {
              prefixMax[i] = max(prefixMax[i - 1], arr[i]);
          }
          
          for (int i = n - 2; i >= 0; i--) {
              suffixMax[i] = max(suffixMax[i + 1], arr[i]);
          }
          
          int total = 0;
          
          for (int i = 0; i < n; ++i) {
              int leftMax = prefixMax[i], rightMax = suffixMax[i];
              
              if (arr[i] < leftMax and arr[i] < rightMax) {
                  total += min(leftMax, rightMax) - arr[i];
              }
          }
          
          return total;
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

    int ans = s.maxWater(arr);

    cout << ans << "\n";
}