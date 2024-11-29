//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
      string trimLeadingZeros(const string &s) {
        
        // Find the position of the first '1'
        size_t firstOne = s.find('1');
        return (firstOne == string::npos) ? "0" : s.substr(firstOne);
    }

    
    string addBinary(string& s1, string& s2) {
        // your code here
        // Trim leading zeros
        s1 = trimLeadingZeros(s1);
        s2 = trimLeadingZeros(s2);
      
        int n = s1.size();  
        int m = s2.size(); 
        
        // swap the strings if s1 is of smaller length
        if (n < m) {
            return addBinary(s2, s1);
        }
        
        int j = m - 1;  
        int carry = 0; 
        
        // Traverse both strings from the end
        for (int i = n - 1; i >= 0; i--) {
          
              // Current bit of s1
            int bit1 = s1[i] - '0';  
            int sum = bit1 + carry;
            
            // If there are remaining bits in s2, add them to the sum
            if (j >= 0) {
                  
                  // Current bit of s2
                int bit2 = s2[j] - '0';  
                sum += bit2;
                j--;
            }
            
            // Calculate the result bit and update carry
            int bit = sum % 2;
            carry = sum / 2;
            
            // Update the current bit in s1
            s1[i] = (char)(bit + '0');
        }
        
        // If there's any carry left, update s1
        if (carry > 0) {
            s1 = '1' + s1;
        }
        
        return s1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends