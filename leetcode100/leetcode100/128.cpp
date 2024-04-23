//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//    int longestConsecutive(vector<int>& nums) {
//        if (!nums.size()) return 0;
//        //1.构建不重复元素的数组
//        vector<int> tmp;
//
//        for (auto it = nums.begin(); it != nums.end(); ++it)
//        {
//            if (!count(tmp.begin(), tmp.end(), *it))
//            {
//                tmp.push_back(*it);
//            }
//        }
//
//        for (auto it = tmp.begin(); it != tmp.end(); ++it)
//            cout << *it << " ";
//        cout << endl;
//
//
//        int ans = 0;
//        for (auto it = tmp.begin(); it != tmp.end(); ++it)
//        {
//            if (!count(tmp.begin(), tmp.end(), (*it) - 1))//没有比目前值小一的元素
//            {
//                int curnum = *it;
//                int curl = 1;
//
//                while (count(tmp.begin(), tmp.end(), curnum + 1))//有比目前值大一的元素
//                {
//                    curnum += 1;
//                    curl += 1;
//                }
//
//                ans = max(ans, curl);
//            } 
//        }
//        return ans;
//    }
//};
//
////int main()
////{
////    Solution s;
////    vector<int> nums1 = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
////    vector<int> nums2 = { 100,4,200,1,3,2 };
////    vector<int> nums3 = { 9,1,4,7,3,-1,0,5,8,-1,6 };
////    int ans = s.longestConsecutive(nums3);
////    cout << ans << endl;
////}
//
