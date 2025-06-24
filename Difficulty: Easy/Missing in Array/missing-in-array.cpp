class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        vector<int>ans  = arr ;
        
       sort(ans.begin() , ans.end());
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(ans[i] != i+1){
                return i+1;
            }
            
        }
        return n+1;
    }
};