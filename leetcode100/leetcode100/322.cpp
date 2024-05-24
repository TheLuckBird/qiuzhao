//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        vector<int> dp(amount + 1, INT_MAX);
//        dp[0] = 0;
//        for (int i = 1; i <= amount; i++) {  // 遍历背包
//            for (int j = 0; j < coins.size(); j++) { // 遍历物品
//                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
//                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
//                }
//            }
//        }
//        if (dp[amount] == INT_MAX) return -1;
//        return dp[amount];
//    }
//};