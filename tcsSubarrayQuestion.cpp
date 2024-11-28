/*
                                ::::::  Problem ::::::

You are given an array of even integers. Your task is to determine whether it's possible to split the array into two non-empty subarrays such that the average of both subarrays is the same.

If such a split is possible, print "YES." Otherwise, print "NO."

Input Format:

The first line contains an integer n, the size of the array.
The second line contains n space-separated even integers.
Output Format:

Print "YES" if it's possible to split the array into two subarrays with the same average, otherwise print "NO".
Constraints:

2 ≤ n ≤ 10^5 (where n is the length of the array)
2 ≤ a[i] ≤ 10^9 (where a[i] is an element of the array and all elements are even)

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int &i : arr) cin >> i;
    unordered_map<int, float> mp;
    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        mp[i] = sum / (i + 1);  
    }
    sum = 0;
    int el = 1;
    bool possible = false;
    for(int i = n - 1; i > 0; i--) {
        sum += arr[i];
        float avg = sum / el;
        if (fabs(mp[i - 1] - avg) < 1e-6) {
            possible = true;
            break; 
        }
        el++;
    }
    if (possible) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}