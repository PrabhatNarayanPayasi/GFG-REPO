//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long maxProduct(vector<int> arr) {
      sort(arr.begin(),arr.end());
     int n = arr.size();
     
     long long pro1 = static_cast<long long>(arr[n-1])*arr[n-2]*arr[n-3];
     long long pro2 = static_cast<long long>(arr[0])*arr[1]*arr[n-1];
     
     return max(pro1,pro2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends