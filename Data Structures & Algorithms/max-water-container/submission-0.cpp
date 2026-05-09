class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int arr = 0;
        while(i < j){
            int l = min(heights[i], heights[j]), b = j - i;
            int curr_arr = l * b;
            if(arr < curr_arr){
                arr = curr_arr;
            }
            if(heights[i] > heights[j])
                j -= 1;
            else
                i += 1;
        }
        return arr;
    }
};
