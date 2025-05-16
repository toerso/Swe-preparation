#include<iostream>
#include<climits>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

class Solution {
    public:
      // arr: input array
      // Function to find maximum circular subarray sum.
      int circularSubarraySum(vector<int> &arr) {
          int curMaxSum = 0, curMinSum = 0, totalSum = 0;
          int maxSum = INT_MIN, minSum = INT_MAX;
          
          for (int i = 0; i < arr.size(); i++) {
              curMaxSum = max(curMaxSum + arr[i], arr[i]);
              maxSum = max(curMaxSum, maxSum);
              
              curMinSum = min(curMinSum + arr[i], arr[i]);
              minSum = min(minSum, curMinSum);
              
              totalSum += arr[i];
          }
          
          int circularSum = totalSum - minSum;
          
          if (minSum == totalSum) return maxSum;
          
          return max(maxSum, circularSum);
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

    int ans = s.circularSubarraySum(arr);

    cout << ans << "\n";
}