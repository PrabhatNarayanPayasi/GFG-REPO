class Solution {
  public:
  
  int Fibo(int n , vector<int>& dp){
      if(n == 0 || n == 1){
          return n;
      }
      
      //  These two lines for memoization.... which chekcks the resulte is calculated 
    //   or not......
    
      if(dp[n] != -1){
          return dp[n];
      }
      return dp[n] = Fibo(n - 1, dp) + Fibo(n - 2, dp);
  }

  vector<int> fibonacciNumbers(int n) {
      vector<int> dp(n + 1, -1);
      vector<int> result;

      for(int i = 0; i < n; i++) {
          result.push_back(Fibo(i, dp));
      }

      return result;
  }
};
