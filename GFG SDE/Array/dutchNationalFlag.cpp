#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
    public:
      void sort012(vector<int>& arr) {
          int n = arr.size();
          int lo = 0, high = n - 1, mid = 0;
          
          while (mid <= high) {
              if (arr[mid] == 0) swap (arr[lo++], arr[mid++]);
              else if (arr[mid] == 1) mid++;
              else swap(arr[mid], arr[high--]);
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

    s.sort012(arr);

    for (int& x: arr) cout << x << " ";

  }