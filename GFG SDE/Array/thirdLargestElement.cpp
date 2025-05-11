#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
    public:
      int thirdLargest(vector<int> &arr) {
          int first = INT_MIN, second = INT_MIN, third = INT_MIN;
          
          for (int i = 0; i < arr.size(); i++) {
              if (arr[i] > first) {
                  third = second;
                  second = first;
                  first = arr[i];
              }else if (arr[i] > second) {
                  third = second;
                  second = arr[i];
              }else if (arr[i] > third) {
                  third = arr[i];
              }
          }
          
          return third;
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

    int ans = s.thirdLargest(arr);

    cout << ans << '\n';
  }