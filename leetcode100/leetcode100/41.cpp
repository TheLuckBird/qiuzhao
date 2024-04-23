//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
////class Solution {
////public:
////    int firstMissingPositive(vector<int>& nums) {
////        sort(nums.begin(), nums.end());
////        
////        for (int i = 1; i != nums.size() + 2; ++i)
////        {
////            if (find(nums.begin(), nums.end(), i) == nums.end())
////                return i;
////        }
////    }
////};
//
//class Solution {
//public:
//    int firstMissingPositive(vector<int>& nums) {
//        int n = nums.size();
//        for (auto& x : nums)//最小丢失正整数只在[1，N],将不在此范围内的数改成n+1,只修<=0就行
//        {
//            if (x <= 0)
//            {
//                x = n + 1;
//            }
//        }
//
//        for (int i = 0; i != n; ++i)//将元素数值映射为数组索引以构造哈希表，将元素值修改为负数
//        {
//            int tmp = abs(nums[i]);
//            if (tmp <= n)
//            {
//                nums[tmp - 1] = -abs(nums[tmp - 1]);
//            }
//        }
//
//        for (int i = 0; i != n; ++i)
//        {
//            if (nums[i] > 0)
//                return i + 1;
//        }
//        return n + 1;
//    }
//};
//
//int main()
//{
//    vector<int> nums1 = { 1,2,0 };
//    vector<int> nums2 = { 3,4,-1,1 };
//    vector<int> nums3 = { 7,8,9,11,12 };
//    Solution s;
//    int ans = s.firstMissingPositive(nums2);
//    cout << ans;
//}