class Solution {
public:
    int dp[301][5001]; 

    int solve(int idx, vector<int>& coins, int amount){
        if(amount == 0) return 1;  
        if(idx == coins.size()) return 0; 

        if(dp[idx][amount] != -1) return dp[idx][amount]; 

        int take = 0;
        if(coins[idx] <= amount) { 
            take = solve(idx, coins, amount - coins[idx]);
        }
        int skip = solve(idx + 1, coins, amount);

        return dp[idx][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp)); 
        return solve(0, coins, amount);
    }
};