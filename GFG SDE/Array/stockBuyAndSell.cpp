#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
      int maximumProfit(vector<int> &prices) {
          int maxprofit = 0;
          int buy = prices[0];
          
          for (int i = 1; i < prices.size(); ++i) {
              maxprofit = max(maxprofit, prices[i] - buy);
              if (buy > prices[i]) buy = prices[i];
          }
          
          return maxprofit;
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

    int ans = s.maximumProfit(arr);

    cout << ans << "\n";
  }