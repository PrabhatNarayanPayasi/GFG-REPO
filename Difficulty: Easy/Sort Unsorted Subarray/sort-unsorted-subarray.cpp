//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> printUnsorted(vector<int>& arr) {
       auto temp = arr;
        sort(temp.begin(), temp.end());
        int start = arr.size(), end = 0, n = arr.size();
        for(int i = 0; i<n; i++) {
            if(temp[i] != arr[i]) {
                start = min(start, i);
                end = max(end, i);
            }
        }
        
        return {start,end};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the number of test cases
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr);
        cout << ans[0] << " " << ans[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends