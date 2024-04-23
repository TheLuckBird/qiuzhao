//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
////class Solution {
////public:
////    vector<int> productExceptSelf(vector<int>& nums) {
////        vector<int> ans;
////
////        for (int i = 0; i != nums.size(); ++i)
////        {
////            int item = 1;
////            for (int j = 0; j != nums.size(); ++j)
////            {
////                if (i == j)
////                {
////                    continue;
////                }
////                else
////                {
////                    item *= nums[j];
////                }
////            }
////            ans.push_back(item);
////        }
////        return ans;
////    }
////};
//
////class Solution {
////public:
////    vector<int> productExceptSelf(vector<int>& nums) {
////        vector<int> ans;
////
////        int product = 1;
////        for_each(nums.begin(), nums.end(),
////            [&product](int x) {product *= x;});
////
////        for (int i = 0; i != nums.size(); ++i)
////        {
////            ans.push_back(product / nums[i]);
////        }
////        return ans;
////
////    }
////};
//
//
//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> ans(n);
//
//        vector<int> L(n);
//        vector<int> R(n);
//        L[0] = 1;
//        R[n - 1] = 1;
//
//        for (int i = 1; i != n; ++i)
//        {
//            L[i] = L[i - 1] * nums[i - 1];
//        }
//        for (int i = n - 2; i >= 0; --i)
//        {
//            R[i] = R[i + 1] * nums[i + 1];
//        }
//
//        for (int i = 0; i != n; ++i)
//        {
//            ans[i] = L[i ] * R[i];
//        }
//        return ans;
//    }
//};
//
//int main()
//{
//    vector<int> nums1 = { 1,2,3,4 };
//    vector<int> nums2 = { -1,1,0,-3,3 };
//    Solution s;
//    vector<int> ans = s.productExceptSelf(nums1);
//    for_each(ans.begin(),ans.end(),
//        [](int x) { cout << x << " "; });
//    return 0;
//}