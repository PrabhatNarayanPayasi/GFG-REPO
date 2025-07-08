class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int , vector<int> , greater<int> >p;
        for(int x :arr){
            p.push(x);
        }
        int totalcost = 0;
        while(p.size()>1){
            int first = p.top();
            p.pop();
            int second = p.top();
            p.pop();
            int cost = first + second;
            totalcost += cost;
            p.push(cost);
        }
        return totalcost;
    }
};