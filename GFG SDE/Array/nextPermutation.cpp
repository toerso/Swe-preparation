#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    public:
      void nextPermutation(vector<int>& arr) {
          int n = arr.size();
          int idx = -1;
          for (int i = n - 2; i >= 0; i--) {
              if (arr[i] < arr[i + 1]) {
                  idx = i;
                  break;
              }
          }
          
          if (idx == -1) {
              reverse(arr.begin(), arr.end());
              return;
          }
          
          for (int i = n - 1; i >= idx; i--) {
              if (arr[i] > arr[idx]) {
                  swap(arr[i], arr[idx]);
                  break;
              }
          }
          
          reverse(arr.begin() + idx + 1, arr.end());
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

    s.nextPermutation(arr);

    for (int& x: arr) cout << x << " ";

  }