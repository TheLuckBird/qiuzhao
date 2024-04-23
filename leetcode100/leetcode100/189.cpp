//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//
//        for (int i = 0; i != k; ++i)
//        {
//            int num = nums.back();
//            nums.insert(nums.begin(), num);
//            nums.pop_back();
//        }
//        for_each(nums.begin(), nums.end(),
//            [](int x) { cout << x << " "; });
//    }
//};
//
//int main()
//{
//    vector<int> nums1 = { 1,2,3,4,5,6,7 };
//    vector<int> nums2 = { -1,-100,3,99 };
//    int k = 3;
//    Solution s;
//    s.rotate(nums1, 3);
//}