//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//	int numSquares(int n) {
//		vector<int> dp(n + 1, INT_MAX);
//		dp[0] = 0;
//		for (int i = 0; i <= n; i++) { // 遍历背包
//			for (int j = 1; j * j <= i; j++) { // 遍历物品
//				dp[i] = min(dp[i - j * j] + 1, dp[i]);
//			}
//		}
//		return dp[n];
//	}
//};
//
//
