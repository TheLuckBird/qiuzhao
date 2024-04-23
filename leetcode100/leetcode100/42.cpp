//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        int ans;
//
//        for (int l = 0, int r = 1; l != height.size();++l)
//        {
//            if (height[l] == 0 || height[r] == 0)
//            {
//                ++l;
//                ++r;
//            }
//
//            //1.’“ø”
//            bool flag = false;
//            while (r != height.size())
//            {
//                ++r;
//                if (height[l] <= height[r])
//                {
//                    flag = true;
//                    break;
//                }
//            }
//
//            //2.º∆À„ø”µƒ»›ª˝
//            for (int i = l; i != r; ++i)
//            {
//
//            }
//            if (flag)
//            {
//                l = r - 1;
//                r = r + 1;
//            }
//            else
//                ++r;
//        }
//
//        return ans;
//    }
//};