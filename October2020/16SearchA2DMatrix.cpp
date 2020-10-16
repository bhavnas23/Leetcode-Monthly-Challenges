class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0)
            return false;  
        int m = matrix[0].size();
        if(m==0)
            return false;
        int x = 0, y = m-1;
        while(x<n && y>=0){
            if(target==matrix[x][y])
                return true;
            else if(target>matrix[x][y]){
                x++;
            }
            else{
                y--;
            }
        }
        return false;
        
    }
};
