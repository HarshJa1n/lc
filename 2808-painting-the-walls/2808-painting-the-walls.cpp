class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int paintWalls(vector<int>& cost, vector<int>& time) {
        //the ith item costs cost[i] and paints 1+time[i] walls, need to paint n walls
        //knapsack
         n = cost.size();
         dp = vector(n,vector(n+1,-1));
         return func(0, n , cost , time);
    }
    int func( int i, int remain, vector<int>& cost, vector<int>& time){
        if(remain <= 0) return 0;
        if( i == n) return 1e9;
        if(dp[i][remain] != -1){
            return dp[i][remain];
        }

        int paiddo = cost[i] + func(i+1, remain -1 - time[i], cost, time);
        int paidnot = func(i+1, remain, cost , time);
        dp[i][remain] = min(paiddo, paidnot);
        return dp[i][remain];
    }
};