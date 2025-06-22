class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        int start = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
        while(sum >target&& start < i ){
            sum -= arr[start];
            ++start;
        }
        if(sum == target){
            return {start+1 , i+1 };
        }
        }
        return {-1};
    }
};