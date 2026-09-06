class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &x:arr){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
