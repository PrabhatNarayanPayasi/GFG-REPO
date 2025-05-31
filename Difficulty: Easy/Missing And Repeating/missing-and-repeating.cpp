class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int repeating = -1, missing = -1;

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                repeating = arr[i];
            }
        }

        // Sum of 1 to n is n*(n+1)/2
        long long expected_sum = (long long)n * (n + 1) / 2;
        long long actual_sum = 0;

        for (int i = 0; i < n; i++) {
            actual_sum += arr[i];
        }

        // Missing = expected - (actual - repeating)
        missing = expected_sum - (actual_sum - repeating);

        return {repeating, missing};
    }
};