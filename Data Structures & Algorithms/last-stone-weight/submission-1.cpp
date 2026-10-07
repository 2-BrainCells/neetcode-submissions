class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int ans;
        if(pq.size() == 0){
            return 0;
        }
        if(pq.size() == 1){
            return pq.top();
        }
        while (pq.size() > 1) {
            int l1 = pq.top();
            pq.pop();
            int l2 = pq.top();
            pq.pop();
            if (l1 > l2) {
                l1 -= l2;
                pq.push(l1);
            }

            else {
                l2 -= l1;
                pq.push(l2);
            }
            cout << l1 << " " << l2 << endl;
            if(pq.size() == 0)
                return 0;
            
            if(pq.size() == 1)
            ans = pq.top();
        }
        return ans;
    }
};
