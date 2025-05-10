#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int lo, int mid, int hi) {
    vector<int> tmp;
    int left = lo, right = mid + 1;

    while (left <= mid and right <= hi) {
        if (arr[left] <= arr[right]) {
            tmp.emplace_back(arr[left]);
            left += 1;
        }else {
            tmp.emplace_back(arr[right]);
            right += 1;
        }
    }

    while (left <= mid) {
        tmp.emplace_back(arr[left]);
        left += 1;
    }

    while (right <= hi) {
        tmp.emplace_back(arr[right]);
        right += 1;
    }

    for (int i = lo; i <= hi; ++i) {
        arr[i] = tmp[i - lo];
    }
}

void mergeSort(vector<int>& arr, int lo, int hi) {
    if (lo >= hi) return;

    int mid = (lo + hi) / 2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}

int main() {
    #ifndef ONLINE_JUDGE
       (void) !freopen("../input.txt", "r", stdin);
       (void) !freopen("../output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> arr(n);
    for(int& x: arr) cin >> x;

    mergeSort(arr, 0, n - 1);
    for(int& x: arr) cout << x << " ";
}