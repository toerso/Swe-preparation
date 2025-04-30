#include<iostream>
#include<vector>
using namespace std;

//Always select minimum and put it in the front

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i <= n-2; ++i) {
        int mini = i;

        for(int j = i; j < n; j++) {
            if(arr[j] < arr[mini]) mini = j;
        }
        swap(arr[i], arr[mini]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
   (void) !freopen("../input.txt", "r", stdin);
   (void) !freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int& x: arr) cin >> x;

    selectionSort(arr);

    for(int& x: arr) cout << x << " ";
}