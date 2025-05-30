class Solution {
  public:
    vector<int> nFibonacci(int N) {
        // code here
        vector<int>Fib;
        int a = 0, b = 1;
       
        while(a<=N){
            Fib.push_back(a);
       int  sum = a+b;
            
            a=b;
            b=sum;
        }
        return Fib;
    }
};