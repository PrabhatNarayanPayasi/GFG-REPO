//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
      int n = s1.size();
        int m = s2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int j = 0; j <= m; j++) prev[j] = j;

        for(int i = 1; i <= n; i++){
            
            curr[0] = i;
            for(int j = 1; j <= m; j++){

                if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
                else{
                    curr[j] = 1 + min( prev[j], min( curr[j-1], prev[j-1]));
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends