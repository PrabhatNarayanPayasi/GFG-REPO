class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // Max Heap
        priority_queue<int> pq;

        // First k elements push करो
        for(int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }

        // बाकी elements चेक करो
        for(int i = k; i < arr.size(); i++) {
            if(arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        // Top element is the k-th smallest
        return pq.top();
    }
};
