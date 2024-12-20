//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
          int m = mat.size();
    int n = mat[0].size();

    // Vector to store the spiral order elements
    vector<int> res;

    // Initialize boundaries
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    // Iterate until all elements are printed
    while (top <= bottom && left <= right) {

        // Print top row from left to right
        for (int i = left; i <= right; ++i) {
            res.push_back(mat[top][i]);
        }
        top++;

        // Print right column from top to bottom
        for (int i = top; i <= bottom; ++i) {
            res.push_back(mat[i][right]);
        }
        right--;

        // Print bottom row from right to left (if exists)
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                res.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // Print left column from bottom to top (if exists)
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                res.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends