//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        int count = 0;
        sort(intervals.begin(),intervals.end());
        int e = intervals[0][1];
        int n = intervals.size();
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0] < e)
            {
                count++;
                e = min(e, intervals[i][1]);
            }
            else
            {
                e = intervals[i][1];
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends