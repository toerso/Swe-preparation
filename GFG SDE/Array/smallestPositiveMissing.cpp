#include<iostream>
#include<climits>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

class Solution {
    int partition(vector<int>& arr) {
        int pidx = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > 0) {
                swap(arr[i], arr[pidx]);
                pidx += 1;
            }
        }
        
        return pidx;
    }
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int k = partition(arr);
        
        for (int i = 0; i < k; ++i) {
            int idx = abs(arr[i]);
            
            if (idx - 1 < k && arr[idx - 1] > 0) arr[idx-1] = -arr[idx-1];
        }
        
        for (int i = 0; i < k; ++i) {
            if (arr[i] > 0) return i + 1;
        }
        
        return k + 1;
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

    int ans = s.missingNumber(arr);

    cout << ans << "\n";
}