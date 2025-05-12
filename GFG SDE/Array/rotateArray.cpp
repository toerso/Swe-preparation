#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

// class Solution {
//     public:
//       //brute approach
      
//       void rotateArr(vector<int>& arr, int d) {
//           int n = arr.size();
          
//           d = d % n;
//           vector<int> tmp;
//           for (int i = 0; i < d; i++) {
//               tmp.emplace_back(arr[i]);
//           }
             
//           for (int i = d; i < n; ++i) {
//               arr[i - d] = arr[i];
//           }
             
//           for (int i = n-d; i < n; ++i) {
//               arr[i] = tmp[i - (n - d)];
//           }
//       }
// };


class Solution {
    public:
      //optimal
      
      void rotateArr(vector<int>& arr, int d) {
          int n = arr.size();
          d = d % n;
          
          reverse(arr.begin(), arr.begin() + d);
          reverse(arr.begin() + d, arr.end());
          reverse(arr.begin(), arr.end());
      }
};

int main() {
    #ifndef ONLINE_JUDGE
       (void) !freopen("../input.txt", "r", stdin);
       (void) !freopen("../output.txt", "w", stdout);
    #endif

    Solution s;
    vector<int> arr;
    int n, d; cin >> n >> d;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr.emplace_back(x);
    }

    s.rotateArr(arr, d);

    for (int& x: arr) cout << x << " ";

  }