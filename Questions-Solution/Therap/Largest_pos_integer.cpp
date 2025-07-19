//Given array of int find the largest positive int in that array nums[-1, -2, -5, 6, 2, 8, 3] which has also negative element.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLargestPos(vector<int>& arr) {
  sort(arr.begin(), arr.end());

  int lo = 0, hi = arr.size() - 1;

  while (lo < hi) {
     int max = arr[hi];

     if (max == (-1 * arr[lo])) return max;
     else if (abs(arr[lo]) > max) lo += 1;
     else hi += 1;
  }

  return -1;
}

int main() {
   vector<int> arr = {1, 2, -1, -3, 3};

   cout << findLargestPos(arr) << "\n";

   return 0;
}
