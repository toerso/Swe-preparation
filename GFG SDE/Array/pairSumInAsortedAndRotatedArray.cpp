#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
    public:
      bool pairInSortedRotated(vector<int>& arr, int target) {
          int i, n = arr.size();
          
          for (i = 0; i < n-1; ++i) {
              if (arr[i] > arr[i + 1]) break;
          }
          
          int l = (i + 1) % n;
          int r = i;
          
          while (l != r) {
              if (arr[l] + arr[r] == target) return true;
              if (arr[l] + arr[r] < target)
                  l = (l + 1) % n;
              else
                  r = (r - 1 + n) % n;
          }
          
          return false;
      }
};

int main() {
    #ifndef ONLINE_JUDGE
       (void) !freopen("../input.txt", "r", stdin);
       (void) !freopen("../output.txt", "w", stdout);
    #endif

    Solution s;
    vector<int> arr;
    int n, target; cin >> n >> target;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr.emplace_back(x);
    }

    bool ans = s.pairInSortedRotated(arr, target);

    cout << ans << '\n';
  }