#include<iostream>
#include<vector>
using namespace std;

//if pivot = start element then pidx will be j
//else pivot = last element then pidx will be i

int partition(vector<int>& arr, int lo, int hi) {
    int pivot = arr[hi];
    int i = lo, j = hi;

    while (i < j) {
        while (arr[i] < pivot and i <= hi) i++;
        while (arr[j] >= pivot and j >= lo) j--;

        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[i], arr[hi]);

    return i;
}

void quickSort(vector<int>& arr, int lo, int hi) {
    if (lo < hi) {
        int pidx = partition(arr, lo, hi);
        quickSort(arr, lo, pidx - 1);
        quickSort(arr, pidx + 1, hi);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
       (void) !freopen("../input.txt", "r", stdin);
       (void) !freopen("../output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> arr(n);
    for(int& x: arr) cin >> x;

    quickSort(arr, 0, n - 1);
    for(int& x: arr) cout << x << " ";
}