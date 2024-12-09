//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    int count(vector<int>& arr, int l, int r, int m){
        int n1 = m - l + 1;
        int n2 = r-m;
        vector<int>left(n1), right(n2);
        
        for(int i = 0; i < n1; i++){
            left[i] = arr[i+l];
        }
        
        for(int j = 0; j < n2; j++){
            right[j] = arr[m+j+1];
        }
        
        int res = 0;
        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2){
            if(left[i] <= right[j]){
                arr[k++] = left[i++];
            }
            else{
                arr[k++] = right[j++];
                res += (n1 -i);
            }
        }
        while(i < n1){
            arr[k++] = left[i++];
        }
        while(j < n2){
            arr[k++] = right[j++];
        }
        return res;
    }
    
    int inversions(vector<int>& arr, int l, int r){
        int res = 0;
        if(l < r){
            int m = (r+l)/2;
            
            res += inversions(arr, l, m);
            res += inversions(arr, m+1, r);
            
            res += count(arr, l, r, m);
        }
        return res;
    }
    
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return inversions(arr, 0, n-1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends