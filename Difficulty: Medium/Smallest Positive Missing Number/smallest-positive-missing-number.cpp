//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        int ans = 1;

        vector<bool> vis(n + 1, false);

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0 && arr[i] <= n) {
                vis[arr[i]] = true;
            }
        }

        for (int i = 1; i <= vis.size(); i++) {
            if (vis[i]==false) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends