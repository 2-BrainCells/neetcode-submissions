class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int n = matrix.size();       
        int m = matrix[0].size();  
        
        int low = 0;
        int high = (n * m) - 1;     
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int mid1 = mid / m;  
            int mid2 = mid % m;  
            
            if (matrix[mid1][mid2] == target) {
                return true;
            }
            else if (matrix[mid1][mid2] > target) {
                high = mid - 1;  
            }
            else {
                low = mid + 1; 
            }
        }
        
        return false; 
    }
};