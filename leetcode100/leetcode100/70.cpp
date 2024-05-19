//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    int climbStairs(int n) {
//        int ans = 0;
//
//        int x = 1;
//        int y = 2;
//
//        if (n == 1) return 1;
//        if (n == 2) return 2;
//
//        for (int i = 3; i != n + 1; ++i)
//        {
//            ans = x + y;
//            x = y;
//            y = ans;
//            cout << ans << endl;
//        }
//        return ans;
//    }
//};
//
//int main()
//{
//    Solution s;
//    int res = s.climbStairs(4);
//    cout << res << endl;
//}
