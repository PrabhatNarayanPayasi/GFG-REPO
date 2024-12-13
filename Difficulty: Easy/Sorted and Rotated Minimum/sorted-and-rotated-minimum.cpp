//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int mini=min(arr[0],arr[n-1]);
        int l=1,r=n-2;

        while(l<=r){
            int mid=(l+r)/2;

            if(arr[mid]<arr[mid-1] && arr[mid]<=arr[mid+1]){
                mini=min(mini,arr[mid]);
                r=mid-1;
            }

            else if(arr[mid]<=arr[n-1]){
                r=mid-1;
            }

            else{
                l=mid+1;
            }
        }

        return mini;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends