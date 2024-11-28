//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
       int sign = 1;
        int step = 1;
        long long val = 0;
        while (s != 0) {
            if (step == 1) {
                if (*s != ' ')
                    step++;
                else
                    s += 1;
            }
            else if (step == 2) {
                if (*s == '+' || *s == '-') {
                    sign = *s == '-' ? -1 : 1;
                    s += 1;
                }
                step++;
            }
            else if (step == 3) {
                if (*s == '0')
                    s += 1;
                else
                    step++;
            }
            else if (step == 4) {
                if (*s > '9' || *s < '0') {
                    step++;
                }
                else {
                    val = val * 10 + (*s - '0');
                    s += 1;
                }
                if (val * sign > ((1ll << 31) - 1)) {
                    return ((1ll << 31) - 1);
                }
                else if (val * sign < (1ll << 31) * (-1))
                    return (1ll << 31) * (-1);
            }
            else if (step == 5)
                return val * sign;

        }

        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends