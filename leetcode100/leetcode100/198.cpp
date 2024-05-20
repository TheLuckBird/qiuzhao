//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        vector<int> ans(nums.size());
//        if (nums.size() == 1)
//            return nums[0];
//
//        for (int i = 0; i != nums.size(); ++i)
//        {
//            if (i == 0)
//                ans[i] = nums[i];
//            else if (i == 1)
//                ans[i] = max(nums[0], nums[1]);
//            else
//                ans[i] = max(ans[i - 2] + nums[i],ans[i - 1]);
//            cout << ans[i] << endl;
//        }
//
//        return ans[nums.size() -1];
//    }
//};
//
//void test()
//{
//    vector<int> nums1 = { 1,2,3,1 };
//    vector<int> nums2 = { 2,7,9,3,1 };
//    vector<int> nums3 = { 2,1,1,2 };
//    Solution s;
//    int ans = s.rob(nums3);
//    cout << ans << endl;
//}
//
//int main()
//{
//    test();
//}