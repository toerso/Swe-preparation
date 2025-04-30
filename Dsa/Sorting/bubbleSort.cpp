#include<iostream>
#include<vector>
using namespace std;

//Pushes maximum to the last by doing adjacent swapping

void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = n-1; i >= 1; --i) {
        for(int j = 0; j <= i-1; j++) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
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

    bubbleSort(arr);

    for(int& x: arr) cout << x << " ";
}