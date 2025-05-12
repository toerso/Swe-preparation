#include<iostream>
#include<climits>
#include<vector>
#include<unordered_map>
using namespace std;

// class Solution {
//     //better solution
//   public:
//     int majorityElement(vector<int>& arr) {
//         unordered_map<int, int> ump;
        
//         for (int i = 0; i < arr.size(); ++i) {
//             ump[arr[i]]++;
//         }
        
//         for (auto& x: ump) {
//             if (x.second > arr.size()/2) return x.first;
//         }
        
//         return -1;
//     }
// };

class Solution {
    //moor's voting algorithm
  public:
    int majorityElement(vector<int>& arr) {
        int count = 0, elem;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                elem = arr[i];
                count = 1;
            }else if (arr[i] == elem) {
                count++;
            }else {
                count--;
            }
        }
        
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == elem) cnt++;
        }
        
        if (cnt > n / 2) return elem;
        return -1;
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

    int ans = s.majorityElement(arr);

    cout << ans << "\n";

  }