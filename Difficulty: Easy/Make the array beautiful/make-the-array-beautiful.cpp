//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int>s;
        for(int i=0; i<arr.size(); i++){
            //stack empty
        if(s.empty()){
            s.push(arr[i]);
        }
            //greatern 0 ya non negative element ho 
            else if(arr[i]>=0){
                if(s.top()>=0){
                    s.push(arr[i]);
                }
                else{
                    s.pop();
                }
            }
            //smaller than 0
            else{
               if(s.top()<0){
                   s.push(arr[i]);
               }
               else{
                   s.pop();
               }
            }
           
        }
         vector<int>ans(s.size());
            int i = s.size()-1;
            while(!s.empty()){
                ans[i] = s.top();
                i--;
                s.pop();
            }
            return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends