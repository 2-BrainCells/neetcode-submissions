class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int ans;
        ans = (pq.size() == 0) ? 0 : pq.top();
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

        }
            ans = (pq.size() == 0) ? 0 : pq.top();

        return ans;
    }
};
