#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
      void zigZag(vector<int> &arr) {
          bool flag = true;
          
          for (int i = 0; i < arr.size() - 1; i++) {
              if (flag) {
                  if (arr[i] > arr[i + 1])
                      swap(arr[i], arr[i + 1]);
              }else {
                  if (arr[i] < arr[i + 1])
                      swap(arr[i], arr[i + 1]);
              }
              
              flag = !flag;
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

    s.zigZag(arr);

    for (int& x: arr) cout << x << " ";
  }