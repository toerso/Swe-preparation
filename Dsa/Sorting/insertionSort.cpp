#include<iostream>
#include<vector>
using namespace std;

//Pushes maximum to the last by doing adjacent swapping

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 0; i <= n - 1; ++i) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
        
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

    insertionSort(arr);

    for(int& x: arr) cout << x << " ";
}