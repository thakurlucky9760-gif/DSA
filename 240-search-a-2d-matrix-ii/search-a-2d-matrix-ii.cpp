class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(); // row;
        int m=matrix[0].size(); // coloumn
        int row=n-1;
        int col=0;
         while(row>=0 and col<m){
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                row--;
            }
            else if(matrix[row][col]<target){
                col++;
            }
            
         }
         return false;
    }
};