//#include <vector>
//#include<algorithm>
//#include <iostream>
//#include <unordered_set>
//#include <string>
//
//
//using namespace std;
//
//std::vector<std::vector<int>> removeDuplicates(std::vector<std::vector<int>>& ans) {
//    std::vector<std::vector<int>> result;
//    std::unordered_set<std::string> seen;
//
//    for (const auto& v : ans) {
//        std::vector<int> sortedV = v;
//        std::sort(sortedV.begin(), sortedV.end());
//        std::string key;
//        for (int i : sortedV) {
//            key += std::to_string(i) + ",";
//        }
//        if (seen.find(key) == seen.end()) {
//            result.push_back(v);
//            seen.insert(key);
//        }
//    }
//
//    return result;
//}
//
//
//
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> ans;
//        vector<int> pair;
//        int l = 0;
//        int mid = 0;
//        int r = nums.size() - 1;
//        sort(nums.begin(), nums.end());
//
//        while (l < r)
//        {
//            if (nums[l] + nums[r] > 0)
//            {
//                mid = l + 1;
//                while (mid < r)
//                {
//                    if (nums[l] + nums[r] + nums[mid] == 0 && l != r && l != mid && mid != r)
//                    {
//                        ans.push_back({ nums[l],nums[mid],nums[r] });
//                    }
//                    ++mid;
//                }
//                --r;
//            }
//
//            if (nums[l] + nums[r] <= 0)
//            {
//                mid = r - 1;
//                while (mid > l)
//                {
//                    if (nums[l] + nums[r] + nums[mid] == 0 && (l != r && l != mid && mid != r))
//                    {
//                        ans.push_back({ nums[l],nums[mid],nums[r] });
//                    }
//                    --mid;
//                }
//                ++l;
//            }
//            
//        }
//
//        ans = removeDuplicates(ans);
//
//        return ans;
//    }
//};
//
////int main()
////{
////    vector<int> nums1 = { -1,0,1,2,-1,-4 };
////    vector<int> nums2 = { 0,1,1 };
////    vector<int> nums3 = { -2,0,1,1,2 };
////
////    Solution s;
////    vector<vector<int>> ans = s.threeSum(nums3);
////
////    for (auto& pair : ans)
////    {
////        for (auto& key : pair)
////            cout << key << " ";
////        cout << endl;
////    }
////}