#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
      int removeDuplicates(vector<int> &arr) {
         int idx = 1;
         
         for (int i = 1; i < arr.size(); i++) {
             if (arr[i] == arr[i - 1]) continue;
             arr[idx++] = arr[i];
         }
         
         return idx;
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

    int ans = s.removeDuplicates(arr);

    cout << ans << "\n";
  }