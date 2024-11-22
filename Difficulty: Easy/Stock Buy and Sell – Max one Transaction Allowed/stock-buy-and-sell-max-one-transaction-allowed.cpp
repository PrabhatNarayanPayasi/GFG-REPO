//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
      int maxi=prices[0];
        int mini=prices[0];
        int profit=0;
        for(int i=1; i<prices.size(); i++) {
              if(prices[i]>maxi) maxi=prices[i];
              else if(prices[i]<mini) {
                    profit=max(profit,(maxi-mini));
                      maxi=prices[i];
                      mini=prices[i];
              }
        }
        profit=max(profit,maxi-mini);
        return profit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends