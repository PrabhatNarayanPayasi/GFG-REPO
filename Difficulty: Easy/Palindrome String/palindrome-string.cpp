class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // code here
        vector<char>ch;
        for(int i=0; i<s.length(); i++){
            ch.push_back(s[i]);
        }
       // now we will compare with s 
       int n = s.length();
       for(int i=0; i<n; i++){
           if(s[i] != ch[n-i-1]){
               return false;
           }
       }
       return true;
    }
};