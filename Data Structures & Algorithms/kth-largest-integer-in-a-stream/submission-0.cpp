class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int maxCapacity;

    KthLargest(int k, vector<int>& nums) {
        maxCapacity = k;

        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > maxCapacity) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
