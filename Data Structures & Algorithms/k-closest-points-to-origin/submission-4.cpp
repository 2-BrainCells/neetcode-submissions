class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxHeap; 
        
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            
            int squaredDist = (x * x) + (y * y);
            
            maxHeap.push({squaredDist, i});
            
            if (maxHeap.size() > k) {
                maxHeap.pop(); 
            }
        }
        
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            int idx = maxHeap.top().second;
            ans.push_back(points[idx]);
            maxHeap.pop();
        }
        
        return ans;
    }
};
