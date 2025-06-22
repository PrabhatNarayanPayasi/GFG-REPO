// User function Template for C++
class Solution {
  public:
    string revStr(string s) {
        // code here
        stack<char>st;
        int n = s.length();
        for(int i=0; i<n; i++){
            st.push(s[i]);
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};