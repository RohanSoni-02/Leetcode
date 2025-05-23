class Solution {
public:
    int dfs(int row, int col,vector<vector<int>>& mat, vector<vector<int>> & dp){
        int n = mat.size(),m = mat[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int maxim = 0;
        if(dp[row][col] != -1)
            return dp[row][col];
        for(int i = 0;i < 4;i++) {
            int drow=delrow[i] + row;
            int dcol=delcol[i] + col;
            if(drow >= 0 && dcol >= 0 && drow < n && dcol < m && mat[drow][dcol] > mat[row][col]) {
                maxim = max(maxim , 1 + dfs(drow,dcol,mat,dp));
            }
        }
        return dp[row][col] = maxim;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
       int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        int ans = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                ans=max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans+1;
    }

    
};