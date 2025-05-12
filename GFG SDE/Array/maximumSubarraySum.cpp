#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// class Solution {
//     //Brute approach
//     public:
//       int maxSubarraySum(vector<int> &arr) {
//           int maxsum = INT_MIN;
          
//           for (int i = 0; i < arr.size(); ++i) {
//               int sum = 0;
              
//               for (int j = i; j < arr.size(); ++j) {
//                   sum += arr[j];
//                   maxsum = max(maxsum, sum);
//               }
//           }
          
//            return maxsum;
//       }
// };

class Solution {
    //kadane's algorithm
    public:
      int maxSubarraySum(vector<int> &arr) {
          int maxsum = INT_MIN;
          int sum = 0;
          
          for (int i = 0; i < arr.size(); ++i) {
              sum += arr[i];
              maxsum = max(maxsum, sum);
              
              if (sum <= 0) sum = 0;
          }
          
          return maxsum;
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

    int ans = s.maxSubarraySum(arr);

    cout << ans << " ";

  }