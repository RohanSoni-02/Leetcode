class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));
        if (n == 0) {
            return {};
        }
        int res = 1;
        int left = 0, right = n-1, top = 0, bottom = n-1;
        
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                matrix[top][i] = res++;
            }
            top++;
            
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = res++;
            }
            right--;
            
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = res++;
                }
                bottom--;
            }
            
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = res++;
                }
                left++;
            }
        }
        
        return matrix;
    }
};