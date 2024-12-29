//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
       sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        vector<int>ans;
        set<int>st;
        int n1=a.size();
        int n2=b.size();
        int i=0;
        int j=0;
        
        while(i<n1&&j<n2)
        {
            if(a[i]==b[j]) {
            st.insert(a[i]);
            i++,j++;
            }
            
            else if(a[i]<b[j])
            i++;
            
            else
            j++;
        }
        
        for(auto k: st)
        ans.push_back(k);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends