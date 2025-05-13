#include<iostream>
#include<climits>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

class Solution {
    public:
      void rearrange(vector<int>& arr) {
          sort(arr.begin(), arr.end());
          
          int n = arr.size();
          int min_idx = 0, max_idx = n - 1;
          
          int M = arr[max_idx] + 1;
          
          for (int i = 0; i < n; ++i) {
              if (i & 1) {
                  arr[i] = arr[i] + (arr[min_idx++] % M) * M;
              }else {
                  arr[i] = arr[i] + (arr[max_idx--] % M) * M;
              }
          }
          
          for (int i = 0; i < n; ++i) {
              arr[i] /= M;
          }
          
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

    s.rearrange(arr);

    for (int& x: arr) cout << x << " ";

  }